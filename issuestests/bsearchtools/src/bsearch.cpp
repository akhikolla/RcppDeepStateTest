#include <Rcpp.h>

/************************* NUMERIC *************************/
// [[Rcpp::export(rng=false)]]
int lbNumeric(Rcpp::NumericVector sortedValues, double valueToSearch){
	//if(Rcpp::NumericVector::is_na(valueToSearch))
	//	return Rcpp::IntegerVector::get_na();
	int lbIndex = std::lower_bound(sortedValues.begin(),sortedValues.end(),valueToSearch) - sortedValues.begin();
	return lbIndex + 1;
}
// [[Rcpp::export(rng=false)]]
int ubNumeric(Rcpp::NumericVector sortedValues, double valueToSearch){
	//if(Rcpp::NumericVector::is_na(valueToSearch))
	//	return Rcpp::IntegerVector::get_na();
	int lbIndex = std::upper_bound(sortedValues.begin(),sortedValues.end(),valueToSearch) - sortedValues.begin();
	return lbIndex + 1;
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesInRangeNumeric( Rcpp::NumericVector sortedValues, double lbInclusive, double ubInclusive, SEXP indexesRemap = R_NilValue){

	int lbIndex = lbNumeric(sortedValues,lbInclusive);
	int ubIndex = ubNumeric(sortedValues,ubInclusive);

	int n = ubIndex > lbIndex ? ubIndex - lbIndex : 0;
	Rcpp::IntegerVector out(n);
	if(indexesRemap != R_NilValue){
		Rcpp::IntegerVector indexesRemapInt = Rcpp::as<Rcpp::IntegerVector>(indexesRemap);
		for(int i = 0; i < n; i++){
			out[i] = indexesRemapInt[i+lbIndex-1];
		}
	}else{
		for(int i = 0; i < n; i++){
			out[i] = i+lbIndex;
		}
	}
	return out;
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesEqualToNumeric(Rcpp::NumericVector sortedValues, double valueToSearch, SEXP indexesRemap = R_NilValue){
	return indexesInRangeNumeric(sortedValues,valueToSearch,valueToSearch,indexesRemap);
}


/************************* INTEGER *************************/
// [[Rcpp::export(rng=false)]]
int lbInteger( Rcpp::IntegerVector sortedValues, int valueToSearch){
	if(Rcpp::IntegerVector::is_na(valueToSearch))
		return 1;
	int lbIndex = std::lower_bound(sortedValues.begin(),sortedValues.end(),valueToSearch) - sortedValues.begin();
	return lbIndex + 1;
}
// [[Rcpp::export(rng=false)]]
int ubInteger(Rcpp::IntegerVector sortedValues, int valueToSearch){
	if(Rcpp::IntegerVector::is_na(valueToSearch))
		return (int)sortedValues.size()+1;
	int lbIndex = std::upper_bound(sortedValues.begin(),sortedValues.end(),valueToSearch) - sortedValues.begin();
	return lbIndex + 1;
}

// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesInRangeInteger( Rcpp::IntegerVector sortedValues, int lbInclusive, int ubInclusive, SEXP indexesRemap = R_NilValue){

	int lbIndex = lbInteger(sortedValues,lbInclusive);
	int ubIndex = ubInteger(sortedValues,ubInclusive);

	int n = ubIndex > lbIndex ? ubIndex - lbIndex : 0;
	Rcpp::IntegerVector out(n);
	if(indexesRemap != R_NilValue){
		Rcpp::IntegerVector indexesRemapInt = Rcpp::as<Rcpp::IntegerVector>(indexesRemap);
		for(int i = 0; i < n; i++){
			out[i] = indexesRemapInt[i+lbIndex-1];
		}
	}else{
		for(int i = 0; i < n; i++){
			out[i] = i+lbIndex;
		}
	}
	return out;
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesEqualToInteger(Rcpp::IntegerVector sortedValues, int valueToSearch, SEXP indexesRemap = R_NilValue){
	return indexesInRangeInteger(sortedValues,valueToSearch,valueToSearch,indexesRemap);
}

/************************* CHARACTER *************************/
// [[Rcpp::export(rng=false)]]
int lbCharacter( Rcpp::CharacterVector sortedValues, Rcpp::CharacterVector valueToSearch){
	if(valueToSearch.size() != 1)
		Rcpp::stop("Error: expecting one value in argument valueToSearch");
	if(Rcpp::CharacterVector::is_na(valueToSearch[0]))
		return (1);
	int lbIndex = std::lower_bound(sortedValues.begin(),sortedValues.end(),valueToSearch[0]) - sortedValues.begin();
	return (lbIndex + 1);
}
// [[Rcpp::export(rng=false)]]
int ubCharacter( Rcpp::CharacterVector sortedValues, Rcpp::CharacterVector valueToSearch){
	if(valueToSearch.size() != 1)
		Rcpp::stop("Error: expecting one value in argument valueToSearch");
	if(Rcpp::CharacterVector::is_na(valueToSearch[0]))
		return ((int)sortedValues.size()+1);
	int lbIndex = std::upper_bound(sortedValues.begin(),sortedValues.end(),valueToSearch[0]) - sortedValues.begin();
	return (lbIndex + 1);
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesInRangeCharacter(Rcpp::CharacterVector  sortedValues, Rcpp::CharacterVector lbInclusive, Rcpp::CharacterVector ubInclusive, SEXP indexesRemap = R_NilValue){
	if(lbInclusive.size() != 1 || ubInclusive.size() != 1)
		Rcpp::stop("Error: expecting one value in argument lbInclusive and ubInclusive");

	int lbIndex = (lbCharacter(sortedValues,lbInclusive));
	int ubIndex = (ubCharacter(sortedValues,ubInclusive));

	int n = ubIndex > lbIndex ? ubIndex - lbIndex : 0;
	Rcpp::IntegerVector out(n);
	if(indexesRemap != R_NilValue){
		Rcpp::IntegerVector indexesRemapInt = Rcpp::as<Rcpp::IntegerVector>(indexesRemap);
		for(int i = 0; i < n; i++){
			out[i] = indexesRemapInt[i+lbIndex-1];
		}
	}else{
		for(int i = 0; i < n; i++){
			out[i] = i+lbIndex;
		}
	}
	return out;
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesEqualToCharacter(Rcpp::CharacterVector sortedValues, Rcpp::CharacterVector valueToSearch, SEXP indexesRemap = R_NilValue){
	return indexesInRangeCharacter(sortedValues,valueToSearch,valueToSearch,indexesRemap);
}

/************************* LOGICAL *************************/
// [[Rcpp::export(rng=false)]]
int lbLogical(Rcpp::LogicalVector sortedValues, int valueToSearch){
	if(Rcpp::LogicalVector::is_na(valueToSearch))
		return (1);
	int lbIndex = std::lower_bound(sortedValues.begin(),sortedValues.end(),valueToSearch) - sortedValues.begin();
	return (lbIndex + 1);
}
// [[Rcpp::export(rng=false)]]
int ubLogical( Rcpp::LogicalVector  sortedValues, int valueToSearch){
	if(Rcpp::LogicalVector::is_na(valueToSearch))
		return ((int)sortedValues.size()+1);
	int lbIndex = std::upper_bound(sortedValues.begin(),sortedValues.end(),valueToSearch) - sortedValues.begin();
	return (lbIndex + 1);
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesInRangeLogical(Rcpp::LogicalVector sortedValues, int lbInclusive, int ubInclusive, SEXP indexesRemap = R_NilValue){

	int lbIndex = (lbLogical(sortedValues,lbInclusive));
	int ubIndex = (ubLogical(sortedValues,ubInclusive));

	int n = ubIndex > lbIndex ? ubIndex - lbIndex : 0;
	Rcpp::IntegerVector out(n);
	if(indexesRemap != R_NilValue){
		Rcpp::IntegerVector indexesRemapInt = Rcpp::as<Rcpp::IntegerVector>(indexesRemap);
		for(int i = 0; i < n; i++){
			out[i] = indexesRemapInt[i+lbIndex-1];
		}
	}else{
		for(int i = 0; i < n; i++){
			out[i] = i+lbIndex;
		}
	}
	return out;
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesEqualToLogical(Rcpp::LogicalVector sortedValues, int valueToSearch, SEXP indexesRemap = R_NilValue){
	return indexesInRangeLogical(sortedValues,valueToSearch,valueToSearch,indexesRemap);
}

/************************* GENERIC *************************/
// [[Rcpp::export(rng=false)]]
int lb(SEXP sortedValues, SEXP valueToSearch){
	int type = TYPEOF(sortedValues);
	switch(type)
	{
	case INTSXP:
		return lbInteger(Rcpp::as<Rcpp::IntegerVector>(sortedValues), Rcpp::as<int>(valueToSearch));
	case REALSXP:
		return lbNumeric(Rcpp::as<Rcpp::NumericVector>(sortedValues), Rcpp::as<double>(valueToSearch));
	case STRSXP:
		return lbCharacter(Rcpp::as<Rcpp::CharacterVector>(sortedValues), Rcpp::as<Rcpp::CharacterVector>(valueToSearch));
	case LGLSXP:
		return lbLogical(Rcpp::as<Rcpp::LogicalVector>(sortedValues), Rcpp::as<int>(valueToSearch));
	default:
		Rcpp::stop("sortedValues has the wrong type: only integer, numeric, logical and character vectors are supported");
	}
	return (0);
}
// [[Rcpp::export(rng=false)]]
int ub(SEXP sortedValues, SEXP valueToSearch){
	int type = TYPEOF(sortedValues);
	switch(type)
	{
	case INTSXP:
		return ubInteger(Rcpp::as<Rcpp::IntegerVector>(sortedValues), Rcpp::as<int>(valueToSearch));
	case REALSXP:
		return ubNumeric(Rcpp::as<Rcpp::NumericVector>(sortedValues), Rcpp::as<double>(valueToSearch));
	case STRSXP:
		return ubCharacter(Rcpp::as<Rcpp::CharacterVector>(sortedValues), Rcpp::as<Rcpp::CharacterVector>(valueToSearch));
	case LGLSXP:
		return ubLogical(Rcpp::as<Rcpp::LogicalVector>(sortedValues), Rcpp::as<int>(valueToSearch));
	default:
		Rcpp::stop("sortedValues has the wrong type: only integer, numeric, logical and character vectors are supported");
	}
	return (0);
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesInRange(SEXP sortedValues, SEXP lbInclusive, SEXP ubInclusive, SEXP indexesRemap = R_NilValue){
	int type = TYPEOF(sortedValues);
	switch(type)
	{
	case INTSXP:
		return indexesInRangeInteger(Rcpp::as<Rcpp::IntegerVector>(sortedValues), Rcpp::as<int>(lbInclusive), Rcpp::as<int>(ubInclusive),indexesRemap);
	case REALSXP:
		return indexesInRangeNumeric(Rcpp::as<Rcpp::NumericVector>(sortedValues), Rcpp::as<double>(lbInclusive), Rcpp::as<double>(ubInclusive),indexesRemap);
	case STRSXP:
		return indexesInRangeCharacter(Rcpp::as<Rcpp::CharacterVector>(sortedValues), Rcpp::as<Rcpp::CharacterVector>(lbInclusive), Rcpp::as<Rcpp::CharacterVector>(ubInclusive),indexesRemap);
	case LGLSXP:
		return indexesInRangeLogical(Rcpp::as<Rcpp::LogicalVector>(sortedValues), Rcpp::as<int>(lbInclusive), Rcpp::as<int>(ubInclusive),indexesRemap);
	default:
		Rcpp::stop("sortedValues has the wrong type: only integer, numeric, logical and character vectors are supported");
	}
	return Rcpp::wrap(0);
}
// [[Rcpp::export(rng=false)]]
Rcpp::IntegerVector indexesEqualTo(SEXP sortedValues, SEXP valueToSearch, SEXP indexesRemap = R_NilValue){
	int type = TYPEOF(sortedValues);
	switch(type)
	{
	case INTSXP:
		return indexesEqualToInteger(Rcpp::as<Rcpp::IntegerVector>(sortedValues), Rcpp::as<int>(valueToSearch),indexesRemap);
	case REALSXP:
		return indexesEqualToNumeric(Rcpp::as<Rcpp::NumericVector>(sortedValues), Rcpp::as<double>(valueToSearch),indexesRemap);
	case STRSXP:
		return indexesEqualToCharacter(Rcpp::as<Rcpp::CharacterVector>(sortedValues), Rcpp::as<Rcpp::CharacterVector>(valueToSearch),indexesRemap);
	case LGLSXP:
		return indexesEqualToLogical(Rcpp::as<Rcpp::LogicalVector>(sortedValues), Rcpp::as<int>(valueToSearch),indexesRemap);
	default:
		Rcpp::stop("sortedValues has the wrong type: only integer, numeric, logical and character vectors are supported");
	}
	return Rcpp::wrap(0);
}


/************************* DFI class *************************/


// [[Rcpp::export(rng=false,name=".intersectInteger")]]
Rcpp::IntegerVector intersectInteger(Rcpp::IntegerVector x, Rcpp::IntegerVector y) {  
  Rcpp::IntegerVector table = y ;
  Rcpp::sugar::IndexHash<INTSXP> h( table );
  h.fill();
  std::set<int> foundIndexes;
  for(int i = 0; i < x.size(); i++){
    int searchedVal = x[i];
    int oneBasedIndex = h.get_index(x[i]);
    if(!Rcpp::IntegerVector::is_na(oneBasedIndex))
      foundIndexes.insert(searchedVal);
  }
  Rcpp::IntegerVector output(foundIndexes.size());
  std::copy(foundIndexes.begin(),foundIndexes.end(),output.begin());
  return output;
}


// [[Rcpp::export(rng=false,name=".unionInteger")]]
Rcpp::IntegerVector unionInteger(Rcpp::IntegerVector vec1, Rcpp::IntegerVector vec2){
  int len1 = vec1.size();
  int len2 = vec2.size();
  Rcpp::IntegerVector merged = Rcpp::IntegerVector(len1+len2);
  for(int i = 0; i < len1; i++){
    merged[i] = vec1[i];
  }
  for(int i = 0; i < len2; i++){
    merged[i+len1] = vec2[i];
  }
  return Rcpp::unique(merged);
}

// [[Rcpp::export(rng=false,name=".unionIntegerList")]]
Rcpp::IntegerVector unionIntegerList(Rcpp::List list){
  int len = list.size();
  if(len == 0){
    return Rcpp::IntegerVector(0);
  }else{
    Rcpp::IntegerVector currentVec = Rcpp::IntegerVector(0);
    for(int i = 0; i < len; i++){
      currentVec = unionInteger(currentVec,Rcpp::as<Rcpp::IntegerVector>(list[i]));
    }
    return currentVec;
  }
}




