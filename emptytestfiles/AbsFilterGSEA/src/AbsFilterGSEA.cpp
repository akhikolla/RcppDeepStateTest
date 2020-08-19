// [[Rcpp::depends(RcppArmadillo)]]

#include<RcppArmadilloExtensions/sample.h>
#include<Rcpp.h>
#include<vector>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>
#include<math.h>
#include<Rmath.h>
#include<Rcpp/stats/random/random.h>

using namespace Rcpp;
using namespace std;

void split(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos     = str.find_first_of(delimiters, lastPos);
	while (string::npos != pos || string::npos != lastPos) {
		tokens.push_back(str.substr(lastPos, pos - lastPos));
   		lastPos = str.find_first_not_of(delimiters, pos);
      		pos = str.find_first_of(delimiters, lastPos);
    	}
}

// [[Rcpp::export]]
RcppExport SEXP OnetailedGSEA(SEXP tvalue, SEXP genesetfile, SEXP min, SEXP max, SEXP nPerm, SEXP cutoff, SEXP q)
{
	fstream infile;
	string address = as<string>(genesetfile);
	int nGeneset = 0;
	vector<string> field;
	string buf;
	unsigned int MIN = as<int>(min);
	unsigned int MAX = as<int>(max);
	vector<string> GenesetName;
	vector<int> Elements;
	NumericVector Tvalue = as<NumericVector>(tvalue);
	NumericVector rank(Tvalue.size());
	CharacterVector symbol = Tvalue.names();
	vector<string> GENESYMBOL(Tvalue.size());
  double ESweight = as<double>(q);
//	double ESweight = (double) ESweight1;
	map<string, int> gene2index;
	vector<int>::iterator iV;
	int i, k, gs, PERM;
	double N_R; // Gene score sum
	vector<int> rankGene;
	int NPERM = as<int>(nPerm) + 1;
	double P_hit, P_miss;
	int left, right, mean;
	int orgPos, orgNeg, allPos, allNeg;
	int nPos, nNeg, n;
	double FDRmo, FDRja, FDR;
	double sumX, sumY;
	double nominalP;
	float CUT_OFF = as<float>(cutoff);
	vector<string> OUTPUT_GENESET;
	vector<double> OUTPUT_NES, OUTPUT_NominalP, OUTPUT_FDR;
	vector<int> OUTPUT_SIZE;

	// Fill Gene symbol vector
	for(i=0; i<Tvalue.size(); i++)
		GENESYMBOL[i] = symbol[i];

	// Map the gene symbol to integer
	for(i=0; i<Tvalue.size(); i++){
		if(GENESYMBOL[i].substr(0,1)=="\"")
			GENESYMBOL[i] = GENESYMBOL[i].substr(1, GENESYMBOL[i].length()-2);
		gene2index[GENESYMBOL[i].c_str()] = i;
	}

	// Count the number of gene sets satisfying user options: MIN, MAX
	infile.open(address.c_str());
	while(getline(infile, buf)){
		field.clear();
		split(buf, field, "\t");
		Elements.clear();
		for(unsigned int n=1; n<field.size(); n++){
			if(gene2index.count(field[n]))
				Elements.push_back(gene2index.count(field[n]));
		}
		if(Elements.size() >= MIN && Elements.size() <= MAX)
		{
			nGeneset++;
		}
	}
	infile.close();

	if(nGeneset == 0)
	{
	  Rcpp::warning("No gene-set passed the condition for gene-set size. Please check the option minGenesetSize and maxGenesetSize. Also, the gene-set file must be tab-delimited (like .gmt file). Refer to the format of gene-set file in the example code of GenePermGSEA function.");
	}

	//Store gene set member
	std::vector<vector<int> > rowGeneset;
	for(int i=0;i<nGeneset; i++)
	{
	  rowGeneset.push_back(vector<int>());
	}

	infile.open(address.c_str());
	int ord = 0;
	while(getline(infile, buf))
	{
		field.clear();
		split(buf, field, "\t");
		Elements.clear();
		for(unsigned int n=1; n<field.size(); n++){
			if(gene2index.count(field[n])) {
				Elements.push_back(gene2index[field[n]]);
			}
		}

		if(Elements.size() < MIN || Elements.size() > MAX)
			continue ;

		GenesetName.push_back(field[0].c_str());

		for(unsigned int n=0; n<Elements.size(); n++)
			rowGeneset[ord].push_back(Elements[n]);
		ord ++;
	}
	infile.close();

	// ES score calculation
	NumericMatrix enrich(nGeneset, NPERM);
	mean = 0;
	// Set rank
	for(k=0; k<Tvalue.size(); k++)
	{
		left = 0; right=Tvalue.size()-1;
		while(left<=right){
			mean = (left + right) / 2 ;
			if(Tvalue[k] < Tvalue[mean])
				left = mean + 1;
			else if(Tvalue[k] > Tvalue[mean])
				right = mean - 1;
			else
				break;
		}
		rank[k] = mean;
	}

	for(gs=0; gs<nGeneset; gs++)
	{
		rankGene.clear();
		N_R = 0.0;
		for(iV=rowGeneset[gs].begin(); iV !=rowGeneset[gs].end(); iV++)
		{
			rankGene.push_back(rank[*iV]); // rank == order
		  if(ESweight == 0.0){N_R += 1;}
		  if(ESweight > 0.0){N_R += fabs(Tvalue[rank[*iV]]);}
		}

		sort(rankGene.begin(), rankGene.end());

		enrich[gs] = P_hit = 0. ;
		for(unsigned int kk=0; kk<rankGene.size(); kk++){
			//at (hit - 1)
			P_miss = 1./(Tvalue.size() - rankGene.size()) * (rankGene[kk]-kk);
			if(enrich[gs] < (P_hit-P_miss))
				enrich[gs] = P_hit-P_miss;

			//at hit
			if(ESweight == 0.0){P_hit += 1.0/N_R;}
			if(ESweight > 0.0){P_hit += fabs(Tvalue[rankGene[kk]])/N_R;}

			if(enrich[gs] < (P_hit - P_miss))
				enrich[gs] = P_hit-P_miss;
		}
	} // finished

	// Do permutation
	int size = Tvalue.size();
	bool replace = false;
	NumericVector prob = NumericVector::create();
	for(PERM = 1; PERM<NPERM; PERM++)
	{
		NumericVector Tvalue_temp = clone(tvalue);
    Tvalue_temp = RcppArmadillo::sample(Tvalue_temp, size, replace, prob);

		// Set rank
		for(int kk=0; kk<Tvalue.size(); kk++)
		{
			left = 0; right=Tvalue.size()-1;
			while(left<=right){
				mean = (left + right) / 2 ;
				if(Tvalue_temp[kk] < Tvalue[mean])
					left = mean + 1;
				else if(Tvalue_temp[kk] > Tvalue[mean])
					right = mean - 1;
				else
					break;
			}
			rank[kk] = mean;
		}

		for(gs=0; gs<nGeneset; gs++)
		{
			rankGene.clear();
			N_R = 0.0;

			for(iV=rowGeneset[gs].begin(); iV !=rowGeneset[gs].end(); iV++)
			{
				rankGene.push_back(rank[*iV]);
			  if(ESweight == 0.0){N_R += 1;}
			  if(ESweight > 0.0){N_R += fabs(Tvalue_temp[*iV]);}
			}
			sort(rankGene.begin(), rankGene.end());

			enrich[nGeneset*PERM+gs] = P_hit = 0.0;
			for(unsigned int kk=0; kk<rankGene.size(); kk++){
				// at hit-1
				P_miss = 1./(Tvalue.size()-rankGene.size()) * (rankGene[kk] - kk);
				if(enrich[nGeneset*PERM+gs] < (P_hit - P_miss))
					enrich[nGeneset*PERM+gs] = P_hit-P_miss;

				// at hit
				if(ESweight == 0.0){P_hit += 1.0/N_R;}
				if(ESweight > 0.0){P_hit += fabs(Tvalue[rankGene[kk]])/N_R;}
				if(enrich[nGeneset*PERM+gs] < (P_hit - P_miss))
					enrich[nGeneset*PERM+gs] = P_hit - P_miss;
			}
		}
	}
	// normalization
	orgPos = orgNeg = 0;
	allPos = allNeg = 0;
	for(gs=0; gs<nGeneset; gs++)
	{
		if(enrich[gs] >= 0)
			++orgPos;
		for(PERM=1; PERM<NPERM; PERM++)
			if (enrich[nGeneset*PERM+gs] >= 0)
				++allPos;
	}
	orgNeg = nGeneset - orgPos;
	allNeg = nGeneset*(NPERM-1) - allPos;

	for(gs=0; gs<nGeneset; gs++)
	{
		nPos = 0; sumX = 0.; //positive
		nNeg = 0; sumY = 0.; //negative

		for(PERM = 1; PERM<NPERM; PERM++)
		{
			if(enrich[nGeneset*PERM+gs] >=0){
				++nPos;
				sumX += enrich[nGeneset*PERM+gs];
			} else {
				++nNeg ;
				sumY += enrich[nGeneset*PERM+gs];
			}
		}

		if(nPos > 0){
			sumX /= nPos;
			for(PERM = 0; PERM<NPERM; PERM++)
				if(enrich[nGeneset*PERM+gs] >= 0)
					enrich[nGeneset*PERM+gs]/=sumX;
		}

		if(nNeg > 0){
			sumY = fabs(sumY/nNeg);
			for(PERM=0; PERM<NPERM; PERM++)
				if(enrich[nGeneset*PERM+gs]<0)
					enrich[nGeneset*PERM+gs]/=sumY;
		}

	}
	// estimating significance: normal p value, FDR
	for(gs=0; gs<nGeneset; gs++)
	{
		nominalP = 0.;
		nPos = nNeg = 0;
		FDRmo = FDRja = 0.;
		if(enrich[gs] >=0){
			//nominal P
			for(PERM=1; PERM<NPERM; PERM++)
			{
				if(enrich[nGeneset*PERM+gs] >=0){
					++nPos;
					if(enrich[nGeneset*PERM+gs] >= enrich[gs])
						++nominalP;
				}
			}
			// FDR
			for(k=0; k<nGeneset; k++)
			{
				if(enrich[gs] <= enrich[k]){
					++FDRmo;
				}
			}
			FDRmo /= orgPos;

			for(k=0; k<nGeneset; k++){
				for(PERM=1; PERM<NPERM; PERM++)
					if(enrich[gs] <= enrich[nGeneset*PERM+k])
						++FDRja;
			}
			FDRja /= allPos;
		} else {
			// nominal P
			for(PERM=1; PERM<NPERM; PERM++){
				if(enrich[gs] < 0){
					++nNeg;
					if(enrich[nGeneset*PERM+gs] <= enrich[gs])
						++nominalP;
				}
			}
			// FDR
			for(k=0; k<nGeneset; k++){
				if(enrich[gs] >= enrich[k])
					++FDRmo;
			}
			FDRmo/=orgNeg;

			for(k=0; k<nGeneset; k++){
				for(PERM=1; PERM<NPERM; PERM++)
					if(enrich[gs] >= enrich[nGeneset*PERM+k])
						++FDRja;
			}
			FDRja /= allNeg;
		}

		if(enrich[gs] >= 0){
			nominalP /= nPos;
		  nominalP = Rf_fprec(nominalP, 4);
		} else {
			nominalP /= nNeg;
		  nominalP = Rf_fprec(nominalP, 4);
		}
		FDR = FDRja/FDRmo;
		FDR = Rf_fprec(FDR, 4);

		// Result vectors
		if(FDR <= CUT_OFF){
			n = rowGeneset[gs].size();
			OUTPUT_GENESET.push_back(GenesetName[gs]);
			OUTPUT_SIZE.push_back(n);
			OUTPUT_NES.push_back(enrich[gs]);
			OUTPUT_NominalP.push_back(nominalP);
			OUTPUT_FDR.push_back(FDR);
		}
	}
	DataFrame df = DataFrame::create(Named("GenesetName", OUTPUT_GENESET),
							Named("Size", OUTPUT_SIZE),
							Named("NES", OUTPUT_NES),
							Named("Nominal P-value", OUTPUT_NominalP),
							Named("FDR Q-value", OUTPUT_FDR)
							);
	return wrap(df);
}

// [[Rcpp::export]]
RcppExport SEXP TwotailedGSEA(SEXP tvalue, SEXP genesetfile, SEXP min, SEXP max, SEXP nPerm, SEXP cutoff, SEXP q)
{
	fstream infile;
	string address = as<string>(genesetfile);
	int nGeneset = 0;
	vector<string> field;
	string buf;
	unsigned int MIN = as<int>(min);
	unsigned int MAX = as<int>(max);
	vector<string> GenesetName;
	vector<int> Elements;
	NumericVector Tvalue = as<NumericVector>(tvalue);
	NumericVector rank(Tvalue.size());
	double ESweight = as<double>(q);
	//double ESweight = (double) ESweight1;
	CharacterVector symbol = Tvalue.names();
	vector<string> GENESYMBOL(Tvalue.size());
	map<string, int> gene2index;
	vector<int>::iterator iV;
	int i, k, gs, PERM;
	double N_R; // Gene score sum
	vector<int> rankGene;
	int NPERM = as<int>(nPerm) + 1;
	double P_hit, P_miss;
	int left, right, mean;
	int orgPos, orgNeg, allPos, allNeg;
	int nPos, nNeg, n;
	double FDRmo, FDRja, FDR;
	double sumX, sumY;
	double nominalP;
	string updown;
	float CUT_OFF = as<float>(cutoff);
	vector<string> OUTPUT_GENESET, DIRECTION;
	vector<double> OUTPUT_NES, OUTPUT_NominalP, OUTPUT_FDR;
	vector<int> OUTPUT_SIZE;

	// Fill Gene symbol vector
	for(i=0; i<Tvalue.size(); i++)
		GENESYMBOL[i] = symbol[i];

	// Map the gene symbol to integer
	for(i=0; i<Tvalue.size(); i++){
		if(GENESYMBOL[i].substr(0,1)=="\"")
			GENESYMBOL[i] = GENESYMBOL[i].substr(1, GENESYMBOL[i].length()-2);
		gene2index[GENESYMBOL[i].c_str()] = i;
	}

	// Count the number of gene sets satisfying user options: MIN, MAX
	infile.open(address.c_str());
	while(getline(infile, buf)){
		field.clear();
		split(buf, field, "\t");
		Elements.clear();
		for(unsigned int n=1; n<field.size(); n++){
			if(gene2index.count(field[n]))
				Elements.push_back(gene2index.count(field[n]));
		}
		if(Elements.size() >= MIN && Elements.size() <= MAX)
		{
			nGeneset++;
		}
	}
	infile.close();

	if(nGeneset == 0)
	{
	  Rcpp::warning("No gene-set passed the condition for gene-set size. Please check the option minGenesetSize and maxGenesetSize. Also, the gene-set file must be tab-delimited (like .gmt file). Refer to the format of gene-set file in the example code of GenePermGSEA function.");
	}

	//Store gene set member
	std::vector<std::vector<int> > rowGeneset;
  for(int i=0; i<nGeneset; i++)
  {
    rowGeneset.push_back(vector<int>());
  }
	infile.open(address.c_str());
	int ord = 0;
	while(getline(infile, buf))
	{
		field.clear();
		split(buf, field, "\t");
		Elements.clear();
		for(unsigned int n=1; n<field.size(); n++){
			if(gene2index.count(field[n])) {
				Elements.push_back(gene2index[field[n]]);
			}
		}

		if(Elements.size() < MIN || Elements.size() > MAX)
			continue ;

		GenesetName.push_back(field[0].c_str());


		for(unsigned int n=0; n<Elements.size(); n++)
			rowGeneset[ord].push_back(Elements[n]);
		ord++;
	}
	infile.close();

	// ES score calculation
	NumericMatrix enrich(nGeneset, NPERM);
	mean = 0;

	// Set rank
	for(k=0; k<Tvalue.size(); k++)
	{
		left = 0; right=Tvalue.size()-1;
		while(left<=right){
			mean = (left + right) / 2 ;
			if(Tvalue[k] < Tvalue[mean])
				left = mean + 1;
			else if(Tvalue[k] > Tvalue[mean])
				right = mean - 1;
			else
				break;
		}
		rank[k] = mean;
	}

	for(gs=0; gs<nGeneset; gs++)
	{
		rankGene.clear();
		N_R = 0.0;
		for(iV=rowGeneset[gs].begin(); iV !=rowGeneset[gs].end(); iV++)
		{
			rankGene.push_back(rank[*iV]); // rank == order
		  if(ESweight == 0.0){N_R+=1;
		  }else{
		    N_R += fabs(Tvalue(rank[*iV])); //Pointer?
		  }
		}

		sort(rankGene.begin(), rankGene.end());

		enrich[gs] = P_hit = 0. ;
		for(unsigned int kk=0; kk<rankGene.size(); kk++){
			//at (hit - 1)
			P_miss = 1./(Tvalue.size() - rankGene.size()) * (rankGene[kk]-kk);
			if(fabs(enrich[gs]) < fabs(P_hit-P_miss))
				enrich[gs] = P_hit-P_miss;

			//at hit
			if(ESweight == 0.0){P_hit += 1.0/N_R;
			}else{
			  P_hit += fabs(Tvalue[rankGene[kk]])/N_R;
			}
			if(fabs(enrich[gs]) < fabs(P_hit - P_miss))
				enrich[gs] = P_hit-P_miss;
		}
	}

	// Do permutation
	int size = Tvalue.size();
	bool replace = false;
	NumericVector prob = NumericVector::create();

	for(PERM = 1; PERM<NPERM; PERM++)
	{
	  NumericVector Tvalue_temp = clone(tvalue);
	  Tvalue_temp = RcppArmadillo::sample(Tvalue_temp, size, replace, prob);

		// Set rank
		for(int kk=0; kk<Tvalue.size(); kk++)
		{
			left = 0; right=Tvalue.size()-1;
			while(left<=right){
				mean = (left + right) / 2 ;
				if(Tvalue_temp[kk] < Tvalue[mean])
					left = mean + 1;
				else if(Tvalue_temp[kk] > Tvalue[mean])
					right = mean - 1;
				else
					break;
			}
			rank[kk] = mean;
		}

		for(gs=0; gs<nGeneset; gs++)
		{
			rankGene.clear();
			N_R = 0.0;

			for(iV=rowGeneset[gs].begin(); iV !=rowGeneset[gs].end(); iV++)
			{
				rankGene.push_back(rank[*iV]);
			  if(ESweight == 0.0){N_R += 1;
			  }else{
			    N_R += fabs(Tvalue_temp[*iV]);
			  }
			}
			sort(rankGene.begin(), rankGene.end());

			enrich[nGeneset*PERM+gs] = P_hit = 0.0;
			for(unsigned int kk=0; kk<rankGene.size(); kk++){
				// at hit-1
				P_miss = 1./(Tvalue.size()-rankGene.size()) * (rankGene[kk] - kk);
				if(fabs(enrich[nGeneset*PERM+gs]) < fabs(P_hit - P_miss))
					enrich[nGeneset*PERM+gs] = P_hit-  P_miss;

				// at hit
				if(ESweight == 0.0){P_hit += 1.0/N_R;
				}else{
				  P_hit += fabs(Tvalue[rankGene[kk]])/N_R;
				}
				if(fabs(enrich[nGeneset*PERM+gs]) < fabs(P_hit - P_miss))
					enrich[nGeneset*PERM+gs] = P_hit - P_miss;
			}
		}
	}

	// normalization
	orgPos = orgNeg = 0;
	allPos = allNeg = 0;
	for(gs=0; gs<nGeneset; gs++)
	{
		if(enrich[gs] >= 0)
			++orgPos;
		for(PERM=1; PERM<NPERM; PERM++)
			if (enrich[nGeneset*PERM+gs] >= 0)
				++allPos;
	}
	orgNeg = nGeneset - orgPos;
	allNeg = nGeneset*(NPERM-1) - allPos;

	for(gs=0; gs<nGeneset; gs++)
	{
		nPos = 0; sumX = 0.; //positive
		nNeg = 0; sumY = 0.; //negative

		for(PERM = 1; PERM<NPERM; PERM++)
		{
			if(enrich[nGeneset*PERM+gs] >=0){
				++nPos;
				sumX += enrich[nGeneset*PERM+gs];
			} else {
				++nNeg ;
				sumY += enrich[nGeneset*PERM+gs];
			}
		}

		if(nPos > 0){
			sumX /= nPos;
			for(PERM = 0; PERM<NPERM; PERM++)
				if(enrich[nGeneset*PERM+gs] >= 0)
					enrich[nGeneset*PERM+gs]/=sumX;
		}

		if(nNeg > 0){
			sumY = fabs(sumY/nNeg);
			for(PERM=0; PERM<NPERM; PERM++)
				if(enrich[nGeneset*PERM+gs]<0)
					enrich[nGeneset*PERM+gs]/=sumY;
		}

	}
	// estimating significance: normal p value, FDR
	for(gs=0; gs<nGeneset; gs++)
	{
		nominalP = 0.;
		nPos = nNeg = 0;
		FDRmo = FDRja = 0.;
		if(enrich[gs] >=0){
			//nominal P
			for(PERM=1; PERM<NPERM; PERM++)
			{
				if(enrich[nGeneset*PERM+gs] >=0){
					++nPos;
					if(enrich[nGeneset*PERM+gs] >= enrich[gs])
						++nominalP;
				}
			}
			// FDR
			for(k=0; k<nGeneset; k++)
			{
				if(enrich[gs] <= enrich[k]){
					++FDRmo;
				}
			}
			FDRmo /= orgPos;

			for(k=0; k<nGeneset; k++){
				for(PERM=1; PERM<NPERM; PERM++)
					if(enrich[gs] <= enrich[nGeneset*PERM+k])
						++FDRja;
			}
			FDRja /= allPos;
		} else {
			// nominal P
			for(PERM=1; PERM<NPERM; PERM++){
				if(enrich[gs] < 0){
					++nNeg;
					if(enrich[nGeneset*PERM+gs] <= enrich[gs])
						++nominalP;
				}
			}
			// FDR
			for(k=0; k<nGeneset; k++){
				if(enrich[gs] >= enrich[k])
					++FDRmo;
			}
			FDRmo/=orgNeg;

			for(k=0; k<nGeneset; k++){
				for(PERM=1; PERM<NPERM; PERM++)
					if(enrich[gs] >= enrich[nGeneset*PERM+k])
						++FDRja;
			}
			FDRja /= allNeg;
		}

		if(enrich[gs] >= 0){
			nominalP /= nPos;
		  nominalP = Rf_fprec(nominalP, 4);
			updown = "UP";
		} else {
			nominalP /= nNeg;
		  nominalP = Rf_fprec(nominalP, 4);
			updown = "DOWN";
		}

		FDR = FDRja/FDRmo;
		FDR = Rf_fprec(FDR, 4);
		// Result vectors
		if(FDR <= CUT_OFF){
			n = rowGeneset[gs].size();
			OUTPUT_GENESET.push_back(GenesetName[gs]);
			OUTPUT_SIZE.push_back(n);
			DIRECTION.push_back(updown);
			OUTPUT_NES.push_back(enrich[gs]);
			OUTPUT_NominalP.push_back(nominalP);
			OUTPUT_FDR.push_back(FDR);
		}
	}
	DataFrame df = DataFrame::create(Named("GenesetName", OUTPUT_GENESET),
							Named("Size", OUTPUT_SIZE),
							Named("NES", OUTPUT_NES),
							Named("Nominal P-value", OUTPUT_NominalP),
							Named("FDR Q-value", OUTPUT_FDR),
							Named("Direction", DIRECTION)
							);
	return wrap(df);
}
