// C++ code for doing the block update
#include <cmath>
#include <Rcpp.h>

// Macro variables for numerical tolerances
#define tol1 1e-8
#define tol2 1e-6

using namespace Rcpp;
using namespace std;

// [[Rcpp::plugins("cpp11")]]

// Two structs containing variables that we need
// var_struct contains the variables that we need to change after their declaratoin
// ab_struct can be treated as constant after its declaration
struct var_struct
{
  int CurrentPiece, RangePiece;
  double y, MinimizerA, MinimizerB, MinimizerC;
  NumericVector CoefA, CoefB, CoefC, LeftKnot, RightKnot;
  int MinimizerWhich, MinimizerPiece;
  int KnotTracker;
  NumericVector KnotLocation;
  IntegerVector WhichAdd, PieceAdd, WhichRemove, PieceRemove;
  bool Scratch, NewMinimizerKnown, WasLastIntersect, LastIntersectUpperRootTrue;
  int LastIntersectWhich, LastIntersectPiece;
  int ActiveA;
  LogicalVector ActiveB;
  NumericVector IntersectLocation;
  IntegerVector IntersectWhich, IntersectPiece, IntersectOrder;
  LogicalVector IntersectActive, IntersectUpperRootTrue;
  IntegerVector IntersectIndex;
  int IntersectHowMany, IntersectCounter;
  bool ActiveIntersectA, ActiveIntersectC;
  LogicalVector ActiveIntersectB;
  int OutputCounter;
  NumericVector OCoefA, OCoefB, OCoefC, OLeftKnot, ORightKnot;
  NumericMatrix OutputMatrixB;
  int IterationCounter;
  bool FinishIteratation;
  var_struct();
};


var_struct::var_struct()
{
  CurrentPiece = 0;
  RangePiece = 0;
  y = 0.0;
  MinimizerA = 0.0;
  MinimizerB = 0.0;
  MinimizerC = 0.0;
  MinimizerWhich = 0;
  MinimizerPiece = 0;
  KnotTracker = 0;
  Scratch = FALSE;
  NewMinimizerKnown = FALSE;
  WasLastIntersect = FALSE;
  LastIntersectUpperRootTrue = FALSE;
  LastIntersectWhich = 0;
  LastIntersectPiece = 0;
  ActiveA = 0;
  IntersectHowMany = 0;
  IntersectCounter = 0;
  ActiveIntersectA = FALSE;
  ActiveIntersectC = FALSE; 
  OutputCounter = 0;
  IterationCounter = 0;
  FinishIteratation = FALSE;
}




struct ab_struct
{
  NumericVector TypeAKnot, TypeAValue, TypeBLeftKnot, TypeBRightKnot, TypeBCoefA, TypeBCoefB, TypeBCoefC;
  LogicalVector IsTypeA, IsTypeB, TypeBEnding;
};





void DoIteration( const double& NextWeight, const double& NextResponse, const int& IterationCounter, const double& gamma, const double& lambda,
                  NumericVector& CoefA, NumericVector& CoefB, NumericVector& CoefC, NumericVector& LeftKnot, NumericVector& RightKnot,
                  NumericMatrix& InputMatrixB );
void KnotMatrixCreator( const ab_struct& zs, var_struct& vs, const double& gamma, const double& lambda );
void KnotDecide( const ab_struct& zs, var_struct& vs, NumericMatrix& InputMatrixB, const double& gamma, const double& lambda );
void Decide( const ab_struct& zs, var_struct& vs, NumericMatrix& InputMatrixB, const double& gamma, const double& lambda );
int WhichPiece( const NumericVector LeftKnot, double y );
IntegerVector InversePermutation( const IntegerVector Permutation );
IntegerVector OrderOfVector( NumericVector x );
IntegerVector WhichMinimizes( double y, int& ActiveA, LogicalVector& ActiveB, int& CurrentPiece, int& RangePiece,
                              const NumericVector& CoefA, const NumericVector& CoefB, const NumericVector& CoefC,
                              const NumericVector& TypeAValue, const NumericVector& TypeBCoefA, const NumericVector& TypeBCoefB,
                              const NumericVector& TypeBCoefC );
void ConstructIntersects( const int& UpperBoundPieces, const ab_struct& zs, var_struct& vs, const double& gamma, const double& lambda );
void IntersectAddOuter( int Which, int Piece,
                        const ab_struct& zs, var_struct& vs, const double& gamma, const double& lambda );
void IntersectAdd( double Location, int Which, int Piece, bool UpperRootTrue,
                   var_struct& vs, const double& gamma, const double& lambda );
void IntersectRemove( int Which, int Piece,
                      var_struct& vs, const double& gamma, const double& lambda );
void OrderIntersectOrder( IntegerVector& IntersectOrder, const NumericVector& IntersectLocation, LogicalVector& IntersectActive,
                          const int& IntersectCounter, IntegerVector& IntersectIndex, const int& IntersectHowMany );
double LowerRoot( double A1, double B1, double C1, double A2, double B2, double C2 );
double UpperRoot( double A1, double B1, double C1, double A2, double B2, double C2 );
bool IsBetter( double OldA, double OldB, double OldC, double NewA, double NewB, double NewC, const double& y );
void UpdateOutput( const int NewMinimizerWhich, const int NewMinimizerPiece, const ab_struct& zs, var_struct& vs,
                   NumericMatrix& InputMatrixB, const double& gamma, const double& lambda );
int ShouldAddIntersect( double y, int MinimizerWhich, int MinimizerPiece, int CandidateWhich,
                        int CandidatePiece, double MinimizerA, double MinimizerB,
                        double MinimizerC, double CandidateA, double CandidateB, double CandidateC,
                        bool WasLastIntersect, int LastIntersectWhich, int LastIntersectPiece,
                        bool LastIntersectUpperRootTrue );
void Compute( const int& UpperBoundPieces, const ab_struct& zs, var_struct& vs, NumericMatrix& InputMatrixB, const double& gamma, const double& lambda );

NumericVector DoBlock( const NumericVector weight, const NumericVector response, const double gamma, const double lambda );




// [[Rcpp::export]]
NumericVector DoBlock( const NumericVector weight, const NumericVector response, const double gamma, const double lambda )
{
  // This is the only function that is exported. It takes the inputs and then initialises some variables before performing the iterations
  // It then performs the backwards pass at the end to compute the estimates
  IntegerVector ResponseOrder = OrderOfVector(response);
  NumericVector ResponseClone = clone(response).sort();
  NumericVector BackPass;
  double NullConsistencyBound;
  if ( gamma < 4 ) {
    NullConsistencyBound = 2 * std::sqrt(gamma) * lambda;
  }
  else
  {
    NullConsistencyBound = 4 * lambda;
  }
  if ( max(response) - min(response) <= NullConsistencyBound )
  {
    double OverallMean = 0;
    for ( int i = 0; i < response.size(); ++i )
    {
      OverallMean += weight[ i ] * response[ i ];
    }
    return NumericVector(response.size(), OverallMean); //Skip all computation if we satisfy the conditions of null-consistency lemma
  }
  else
  {
    NumericVector WeightClone = weight[ ResponseOrder ];
    NumericVector CoefA(1), CoefB(1), CoefC(1), LeftKnot(1), RightKnot(1), TypeAKnot(1), TypeAValue(1), TypeBLeftKnot(1), TypeBRightKnot(1),
    TypeBCoefA(1), TypeBCoefB(1), TypeBCoefC(1);
    LogicalVector IsTypeA(1), IsTypeB(1), TypeBEnding(1);
    NumericMatrix InputMatrixB;
    CoefA[ 0 ] = 0.5 * WeightClone[ 0 ];
    CoefB[ 0 ] = - WeightClone[ 0 ] * ResponseClone[ 0 ];
    CoefC[ 0 ] = 0.5 * WeightClone[ 0 ] * pow(ResponseClone[ 0 ], 2);
    LeftKnot[ 0 ] = -INFINITY;
    RightKnot[ 0 ] = INFINITY;
    int IterationNumber = ResponseClone.size();

    // This is the main loop where we perform the forwards passes
    if ( IterationNumber > 1 )
    {
      for ( int IterationCounter = 2; IterationCounter <= IterationNumber; ++IterationCounter )
      {
        DoIteration(WeightClone[ IterationCounter - 1 ], ResponseClone[ IterationCounter - 1 ], IterationCounter, gamma, lambda,
                    CoefA, CoefB, CoefC, LeftKnot, RightKnot, InputMatrixB );
      }
      // After performing iterations we need to perform the backwards pass

      //Need to compute information for Type A minimizers of the final output to compute the \hat{\beta}_last
      int FinalPieceNumber = CoefA.size();
      NumericVector FinalAKnot(FinalPieceNumber), FinalAValue(FinalPieceNumber);
      LogicalVector IsFinalA(FinalPieceNumber);


      for ( int i = 0; i < FinalPieceNumber; ++i )
      {
        FinalAKnot[ i ] = - CoefB[ i ] / ( 2 * CoefA[ i ] ) + ( gamma * lambda );
        if ( CoefA[ i ] > 0 )
        {
          IsFinalA[ i ] = ( ( FinalAKnot[ i ] - ( gamma * lambda ) <= RightKnot[ i ] )
                              and ( FinalAKnot[ i ] - ( gamma * lambda ) >= LeftKnot[ i ] ) );
          if ( IsFinalA[ i ] == TRUE )
          {
            FinalAValue[ i ] = - ( pow(CoefB[ i ], 2) ) / ( 4 * CoefA[ i ] ) + CoefC[ i ] + ( 0.5 * gamma * pow(lambda, 2) );
          }

        }
      }
      //Have now encoded all the relevant information for Type A minimizers
      double FinalMinValue = INFINITY;
      int FinalMinPiece = 0;
      for ( int i = 0; i < FinalPieceNumber; ++i )
      {
        if ( IsFinalA[ i ] == TRUE )
        {
          if ( FinalAValue[ i ] - FinalMinValue < 0 )
          {
            FinalMinValue = FinalAValue[ i ];
            FinalMinPiece = i;
          }
        }
      }
      // Now we know what the final \hat{\beta}_last is, we can compute the rest of the estimate vector
      BackPass = InputMatrixB( _, FinalMinPiece );

      for ( int k = IterationNumber - 2; k > 0; --k )
      {
        BackPass[ 2 * k - 1 ] += BackPass[ 2 * k + 1 ] * BackPass[ 2 * k - 2 ];
        BackPass[ 2 * k - 2 ] *= BackPass[ 2 * k ];
      }

      NumericVector Estimates(IterationNumber);
      for ( int k = 0; k < IterationNumber - 1; ++k )
      {
        Estimates[ k ] = BackPass[ 2 * k ] * ( FinalAKnot[ FinalMinPiece ] - ( gamma * lambda ) ) + BackPass[ ( 2 * k ) + 1 ];
      }
      Estimates[ IterationNumber - 1 ] = FinalAKnot[ FinalMinPiece ] - gamma * lambda;

      //Retrieve the original ordering of the estimates by inverting the permutation we obtained at the start
      ResponseOrder = InversePermutation(ResponseOrder);
      NumericVector FinalEstimates(IterationNumber);
      for ( int i = 0; i < IterationNumber; ++i )
      {
        FinalEstimates[ i ] = Estimates[ ResponseOrder[ i ] ];
      }
      return FinalEstimates;
    }
    else
    {
      return response;
    }
  }
}



void DoIteration( const double& NextWeight, const double& NextResponse, const int& IterationCounter, const double& gamma, const double& lambda,
                  NumericVector& CoefA, NumericVector& CoefB, NumericVector& CoefC, NumericVector& LeftKnot, NumericVector& RightKnot,
                  NumericMatrix& InputMatrixB )
{
  // We initilaise all the variables first, before scanning from -INFINITY to INFINITY finding the knots in the output
  int NumberOfPieces = CoefA.size();
  int UpperBoundPieces = 4 * NumberOfPieces;

  // First we initiliase the var_struct
  var_struct vs;
  vs.IterationCounter = IterationCounter;
  vs.CurrentPiece = 0;
  vs.RangePiece = 0;

  vs.CoefA = CoefA;
  vs.CoefB = CoefB;
  vs.CoefC = CoefC;
  vs.LeftKnot = LeftKnot;
  vs.RightKnot = RightKnot;

  vs.KnotTracker = 0;
  vs.KnotLocation = NumericVector(UpperBoundPieces);
  vs.WhichAdd = IntegerVector(UpperBoundPieces);
  vs.PieceAdd = IntegerVector(UpperBoundPieces);
  vs.WhichRemove = IntegerVector(UpperBoundPieces);
  vs.PieceRemove = IntegerVector(UpperBoundPieces);

  vs.Scratch = TRUE;
  vs.NewMinimizerKnown = TRUE;

  vs.ActiveA = -1;
  vs.ActiveB = LogicalVector(NumberOfPieces, FALSE);

  vs.IntersectLocation = NumericVector(UpperBoundPieces);
  vs.IntersectWhich = IntegerVector(UpperBoundPieces);
  vs.IntersectPiece = IntegerVector(UpperBoundPieces);
  vs.IntersectOrder = IntegerVector(UpperBoundPieces);
  vs.IntersectActive = LogicalVector(UpperBoundPieces);
  vs.IntersectUpperRootTrue = LogicalVector(UpperBoundPieces);

  vs.IntersectIndex = Range(0, UpperBoundPieces - 1);
  vs.IntersectHowMany = 0;
  vs.IntersectCounter = -1;

  vs.ActiveIntersectA = FALSE;
  vs.ActiveIntersectB = LogicalVector(NumberOfPieces, FALSE);
  vs.ActiveIntersectC = FALSE;

  vs.OutputCounter = -1;

  vs.OCoefA = NumericVector(UpperBoundPieces);
  vs.OCoefB = NumericVector(UpperBoundPieces);
  vs.OCoefC = NumericVector(UpperBoundPieces);
  vs.OLeftKnot = NumericVector(UpperBoundPieces);
  vs.ORightKnot = NumericVector(UpperBoundPieces);

  vs.OutputMatrixB = NumericMatrix(2 * vs.IterationCounter - 2, UpperBoundPieces);
  vs.OLeftKnot[ 0 ] = -INFINITY;
  vs.FinishIteratation = FALSE;

  // This next short section ensures that the basic properties of continuity, and semicontinuity of the first derivative, hold
  // (and fix them if they don't). This is not strictly needed
  double LeftValue, RightValue, LeftDerivative, RightDerivative;
  for ( int i = 1; i < NumberOfPieces; ++i )
  {
    LeftDerivative = 2 * CoefA[ i - 1 ] * LeftKnot[ i ] + CoefB[ i - 1 ];
    RightDerivative = 2 * CoefA[ i ] * LeftKnot[ i ] + CoefB[ i ];
    if ( RightDerivative - LeftDerivative - 0.01 * tol1 > 0 )
    {
      CoefB[ i ] += LeftDerivative - RightDerivative;
      CoefC[ i ] += ( RightDerivative - LeftDerivative ) * LeftKnot[ i ];
      LeftDerivative = 2 * CoefA[ i - 1 ] * LeftKnot[ i ] + CoefB[ i - 1 ];
      RightDerivative = 2 * CoefA[ i ] * LeftKnot[ i ] + CoefB[ i ];
    }
    LeftValue = CoefA[ i - 1 ] * pow(LeftKnot[ i ], 2) + CoefB[ i - 1 ] * LeftKnot[ i ] + CoefC[ i - 1];
    RightValue = CoefA[ i ] * pow(LeftKnot[ i ], 2) + CoefB[ i ] * LeftKnot[ i ] + CoefC[ i ];
    if ( fabs(RightValue - LeftValue) - 0.01*tol1 > 0 )
    {
      CoefC[ i ] += LeftValue - RightValue;
    }
  }

  // Now we set the variables in the second variable structure, ab_struct
  ab_struct zs;
  zs.TypeAKnot = NumericVector(NumberOfPieces);
  zs.TypeAValue = NumericVector(NumberOfPieces);
  zs.TypeBLeftKnot = NumericVector(NumberOfPieces);
  zs.TypeBRightKnot = NumericVector(NumberOfPieces);
  zs.TypeBCoefA = NumericVector(NumberOfPieces);
  zs.TypeBCoefB = NumericVector(NumberOfPieces);
  zs.TypeBCoefC = NumericVector(NumberOfPieces);
  zs.IsTypeA = LogicalVector(NumberOfPieces);
  zs.IsTypeB = LogicalVector(NumberOfPieces);
  zs.TypeBEnding = LogicalVector(NumberOfPieces);

  // First we compute the information about Type A minimizers
  for ( int i = 0; i < NumberOfPieces; ++i )
  {
    if ( CoefA[ i ] > 0 )
    {
      zs.TypeAKnot[ i ] = - CoefB[ i ] / ( 2 * CoefA[ i ] ) + ( gamma * lambda );
      zs.IsTypeA[ i ] = ( ( zs.TypeAKnot[ i ] - ( gamma * lambda ) <= RightKnot[ i ] )
                            and ( zs.TypeAKnot[ i ] - ( gamma * lambda ) >= LeftKnot[ i ] ) );
      if ( zs.IsTypeA[ i ] == TRUE )
      {
        zs.TypeAValue[ i ] = - ( pow(CoefB[ i ], 2) ) / ( 4 * CoefA[ i ] ) + CoefC[ i ] + ( 0.5 * gamma * pow(lambda, 2) );
      }
    }

    // Now we look at the information for Type B minimizers
    if ( 2 * CoefA[ i ] - ( 1 / gamma ) > 0 )
    {
      zs.TypeBLeftKnot[ i ] = max(gamma * ( lambda - CoefB[ i ] ) - ( 2 * CoefA[ i ] * gamma - 1) * RightKnot[ i ],
                                  ( lambda - CoefB[ i ] ) / ( 2 * CoefA[ i ]) );
      zs.TypeBRightKnot[ i ] = min(gamma * ( lambda - CoefB[ i ] ) - ( 2 * CoefA[ i ] * gamma - 1) * LeftKnot[ i ],
                                   gamma * lambda - ( CoefB[ i ] / ( 2 * CoefA[ i ] ) ));
      zs.IsTypeB[ i ] = ( zs.TypeBLeftKnot[ i ] - zs.TypeBRightKnot[ i ] + tol1 < 0 );
      if ( zs.IsTypeB[ i ] == TRUE )
      {
        zs.TypeBEnding[ i ] = ( gamma * lambda - ( CoefB[ i ] / ( 2 * CoefA[ i ] ) )
                                  < gamma * ( lambda - CoefB[ i ] ) - ( 2 * CoefA[ i ] * gamma - 1) * LeftKnot[ i ] );
        zs.TypeBCoefA[ i ] = CoefA[ i ] / ( 1 - 2 * CoefA[ i ] * gamma );
        zs.TypeBCoefB[ i ] = ( CoefB[ i ] - 2 * CoefA[ i ] * gamma * lambda ) / ( 1 - 2 * CoefA[ i ] * gamma );
        zs.TypeBCoefC[ i ] = CoefC[ i ] + ( gamma * pow(( CoefB[ i ] - lambda ), 2) ) / ( 2 * ( 1 - 2 * CoefA[ i ] * gamma ) );
      }
    }
  }

  if ( vs.IterationCounter > 1 )
  {
    KnotMatrixCreator( zs, vs, gamma, lambda );
    vs.y = vs.KnotLocation[ 0 ] - 1;
    vs.MinimizerWhich = 3;
    vs.MinimizerPiece = 0;
    vs.MinimizerA = CoefA[ 0 ];
    vs.MinimizerB = CoefB[ 0 ];
    vs.MinimizerC = CoefC[ 0 ];

    // Now we start at -INFINITY and quickly proceed until the first stationary minimum of the input function. Before this point,
    // the derivative is strictly negative, so we know that the minimizer will be of Type C (without any further calculation necessary)
    bool FoundA = FALSE;
    int JumpToPiece = -1;
    while ( ( FoundA == FALSE ) and ( JumpToPiece < NumberOfPieces - 1 ) )
    {
      ++JumpToPiece;
      if ( zs.IsTypeA[ JumpToPiece ] == TRUE )
      {
        FoundA = TRUE;
      }
    }
    if ( ( FoundA == TRUE ) and ( JumpToPiece > 0 ) )
    {
      for ( int i = 0 ; i < JumpToPiece; ++i )
      {
        vs.OCoefA[ i ] = CoefA[ i ];
        vs.OCoefB[ i ] = CoefB[ i ];
        vs.OCoefC[ i ] = CoefC[ i ];
        vs.OLeftKnot[ i ] = LeftKnot[ i ];
        vs.ORightKnot[ i ] = RightKnot[ i ];
        for ( int j = 0; j < vs.IterationCounter - 2 ; ++j )
        {
          vs.OutputMatrixB( 2 * j, i ) = InputMatrixB( 2 * j, i );
          vs.OutputMatrixB( ( 2 * j ) + 1, i ) = InputMatrixB( ( 2 * j ) + 1, i );
        }
        vs.OutputMatrixB( 2 * vs.IterationCounter - 4, i ) = 1;
        vs.OutputMatrixB( 2 * vs.IterationCounter - 3, i ) = 0;
        ++vs.OutputCounter;
      }
      vs.CurrentPiece = 0;
      vs.OLeftKnot[ JumpToPiece ] = vs.ORightKnot[ JumpToPiece - 1 ];
      while ( vs.CurrentPiece < JumpToPiece )
      {
        vs.y = vs.KnotLocation[ vs.KnotTracker ];
        if ( vs.WhichAdd[ vs.KnotTracker ] == 3 )
        {
          vs.CurrentPiece = vs.PieceAdd[ vs.KnotTracker ];
        }
        vs.RangePiece = WhichPiece(LeftKnot, vs.y - ( gamma * lambda ));
        switch (vs.WhichAdd[ vs.KnotTracker ])
        {
        case 0:
          break;
        case 1:
          vs.ActiveA = vs.PieceAdd[ vs.KnotTracker ];
          break;
        case 2:
          vs.ActiveB[ vs.PieceAdd[ vs.KnotTracker ] ] = TRUE;
          break;
        case 3:
          vs.CurrentPiece = vs.PieceAdd[ vs.KnotTracker ];
          break;
        }
        switch (vs.WhichRemove[ vs.KnotTracker ])
        {
        case 0:
          break;
        case 2:
          vs.ActiveB[ vs.PieceRemove[ vs.KnotTracker ] ] = FALSE;
          break;
        case 3:
          break;
        }
        ++vs.KnotTracker;
      }
      vs.MinimizerWhich = 3;
      vs.MinimizerPiece = vs.CurrentPiece;
      vs.MinimizerA = CoefA[ vs.CurrentPiece ];
      vs.MinimizerB = CoefB[ vs.CurrentPiece ];
      vs.MinimizerC = CoefC[ vs.CurrentPiece ];
      vs.Scratch = TRUE;
      vs.NewMinimizerKnown = TRUE;
    }

    // We now have the main loop of the iteration -- we continue this until we arrive at +INFINITY
    while ( vs.FinishIteratation == FALSE )
    {
      Compute(UpperBoundPieces, zs, vs, InputMatrixB, gamma, lambda);
    }

    // We now finalize the output and prepare variables for the next iteration
    UpdateOutput(vs.MinimizerWhich, vs.MinimizerPiece, zs, vs, InputMatrixB, gamma, lambda);

    CoefA = vs.OCoefA[ Range(0, vs.OutputCounter) ];
    CoefB = vs.OCoefB[ Range(0, vs.OutputCounter) ];
    CoefC = vs.OCoefC[ Range(0, vs.OutputCounter) ];
    LeftKnot = vs.OLeftKnot[ Range(0, vs.OutputCounter) ];
    RightKnot = vs.ORightKnot[ Range(0, vs.OutputCounter) ];
    InputMatrixB = NumericMatrix( 2 * IterationCounter - 2, vs.OutputCounter + 1);
    for ( int i = 0; i < 2 * IterationCounter - 2; ++i )
    {
      for ( int j = 0; j <= vs.OutputCounter; ++j )
      {
        InputMatrixB(i, j) = vs.OutputMatrixB(i, j);
      }
    }
    // The above is used (and not Rcpp sugar) because it was giving occasional errors. Below is the original line of code
    // InputMatrixB = vs.OutputMatrixB( Range(0, ( 2 * IterationCounter ) - 3), Range(0, vs.OutputCounter) );

    for ( int i = 0; i <= vs.OutputCounter; ++i )
    {
      CoefA[ i ] += 0.5 * NextWeight;
      CoefB[ i ] += - NextWeight * NextResponse;
      CoefC[ i ] += 0.5 * NextWeight * pow(NextResponse, 2);
    }
  }
}



void KnotMatrixCreator( const ab_struct& zs, var_struct& vs, const double& gamma, const double& lambda )
{
  // This function computes the points at which the active set changes, and what those changes are
  int KnotCounter = -1;

  // First deal with the Type C minimizers
  int NumberOfPieces = vs.CoefA.size();
  for ( int i = 0; i < NumberOfPieces - 1; ++i )
  {
    ++KnotCounter;
    vs.KnotLocation[ KnotCounter ] = vs.RightKnot[ i ];
    vs.WhichAdd[ KnotCounter ] = 3;
    vs.PieceAdd[ KnotCounter ] = i + 1;
    vs.WhichRemove[ KnotCounter ] = 3;
    vs.PieceRemove[ KnotCounter ] = i;
  }

  //Now deal with the subtler cases - for each piece, we consider (i) addition of
  //Type B minimizer, (ii) removal of Type B minimizer (possibly coincident with addition
  //of Type A), then addition of Type A (if not already added)
  for ( int i = 0; i < NumberOfPieces; ++i )
  {
    if ( zs.IsTypeB[ i ] == TRUE )
    {
      // Add in the Type B startpoint (the left knot)
      ++KnotCounter;
      vs.KnotLocation[ KnotCounter ] = zs.TypeBLeftKnot[ i ];
      vs.WhichAdd[ KnotCounter ] = 2;
      vs.PieceAdd[ KnotCounter ] = i;
      vs.WhichRemove[ KnotCounter ] = 0;
      vs.PieceRemove[ KnotCounter ] = 0;
      ++KnotCounter;
      // Add in the Type B endpoint (the right knot)
      vs.KnotLocation[ KnotCounter ] = zs.TypeBRightKnot[ i ];
      vs.WhichRemove[ KnotCounter ] = 2;
      vs.PieceRemove[ KnotCounter ] = i;
      // Now consider if the end of the Type B coincides with the introduction of a Type A
      if ( (zs.TypeBEnding[ i ] == TRUE) and (zs.IsTypeA[ i ] == TRUE) )
      {
        vs.WhichAdd[ KnotCounter ] = 1;
        vs.PieceAdd[ KnotCounter ] = i;
      }
      else if ( zs.IsTypeA[ i ] == TRUE )
      {
        // If not, then still want to add in a Type A for this piece if we have that one exists for this piece
        ++KnotCounter;
        vs.KnotLocation[ KnotCounter ] = zs.TypeAKnot[ i ];
        vs.WhichAdd[ KnotCounter ] = 1;
        vs.PieceAdd[ KnotCounter ] = i;
        vs.WhichRemove[ KnotCounter ] = 0;
        vs.PieceRemove[ KnotCounter ] = 0;
      }
    }
    else if ( zs.IsTypeA[ i ] == TRUE )
    {
      // If we have Type A but no Type B, we need to make sure that we still include that
      ++KnotCounter;
      vs.KnotLocation[ KnotCounter ] = zs.TypeAKnot[ i ];
      vs.WhichAdd[ KnotCounter ] = 1;
      vs.PieceAdd[ KnotCounter ] = i;
      vs.WhichRemove[ KnotCounter ] = 0;
      vs.PieceRemove[ KnotCounter ] = 0;
    }
  }

  vs.KnotLocation = vs.KnotLocation[ Range(0, KnotCounter) ];
  IntegerVector KnotOrder = OrderOfVector(vs.KnotLocation);
  vs.KnotLocation = vs.KnotLocation[ KnotOrder ];
  vs.WhichAdd = vs.WhichAdd[ KnotOrder ];
  vs.PieceAdd = vs.PieceAdd[ KnotOrder ];
  vs.WhichRemove = vs.WhichRemove[ KnotOrder ];
  vs.PieceRemove = vs.PieceRemove[ KnotOrder ];

  // This short routine combines two knots that are almost at the same location
  LogicalVector KnotCounterKeep(KnotCounter + 1, TRUE);
  int OldKnotCounter = KnotCounter;
  for ( int i = 0; i < OldKnotCounter; ++i )
  {
    if ( ( fabs(vs.KnotLocation[ i ] - vs.KnotLocation[ i + 1 ]) <  tol2 ) and ( ( vs.WhichAdd[ i ] == 0 ) or ( vs.WhichAdd[ i + 1 ] == 0 ) )
           and ( ( vs.WhichRemove[ i ] == 0 ) or ( vs.WhichRemove[ i + 1 ] == 0 ) ) and ( KnotCounterKeep[ i ] ) and ( KnotCounterKeep[ i + 1 ] ) )
    {
      vs.WhichAdd[ i ] += vs.WhichAdd[ i + 1 ];
      vs.PieceAdd[ i ] += vs.PieceAdd[ i + 1 ];
      vs.WhichRemove[ i ] += vs.WhichRemove[ i + 1 ];
      vs.PieceRemove[ i ] += vs.PieceRemove[ i + 1 ];
      KnotCounterKeep[ i + 1 ] = FALSE;
      KnotCounter -= 1;
    }
  }
  vs.KnotLocation = vs.KnotLocation[ KnotCounterKeep ];
  vs.WhichAdd = vs.WhichAdd[ KnotCounterKeep ];
  vs.PieceAdd = vs.PieceAdd[ KnotCounterKeep ];
  vs.WhichRemove = vs.WhichRemove[ KnotCounterKeep ];
  vs.PieceRemove = vs.PieceRemove[ KnotCounterKeep ];
}



void KnotDecide( const ab_struct& zs, var_struct& vs, NumericMatrix& InputMatrixB, const double& gamma, const double& lambda )
{
  // This function decides what should be done when the next event is a change in the active set
  bool JustAdd = FALSE;
  double CandidateA, CandidateB, CandidateC;
  vs.y = vs.KnotLocation[ vs.KnotTracker ];
  vs.RangePiece = WhichPiece(vs.LeftKnot, vs.y - ( gamma * lambda ));

  // First check if we remove something from the active set at the knot
  switch (vs.WhichRemove[ vs.KnotTracker ])
  {
  case 0:
    JustAdd = TRUE;
    break;
  case 2:
    if ( vs.ActiveB[ vs.PieceRemove[ vs.KnotTracker ] ] == TRUE )
    {
      vs.ActiveB[ vs.PieceRemove[ vs.KnotTracker ] ] = FALSE;
      if ( vs.ActiveIntersectB[ vs.PieceRemove[ vs.KnotTracker ] ] == TRUE )
      {
        IntersectRemove(2, vs.PieceRemove[ vs.KnotTracker ], vs, gamma, lambda);
      }
      if ( ( vs.MinimizerWhich == 2 ) and ( vs.MinimizerPiece == vs.PieceRemove[ vs.KnotTracker ] ) ) // if we're removing the current minimizer
      {
        if ( vs.WhichAdd[ vs.KnotTracker ] == 1 )
        {
          vs.ActiveA = vs.PieceAdd[ vs.KnotTracker ];
          UpdateOutput(1, vs.ActiveA, zs, vs, InputMatrixB, gamma, lambda);
          vs.Scratch = TRUE;
          vs.NewMinimizerKnown = TRUE;
          vs.WasLastIntersect = FALSE;
        }
        else if ( vs.WhichAdd[ vs.KnotTracker ] == 2 )
        {
          vs.ActiveB[ vs.PieceAdd[ vs.KnotTracker ] ] = TRUE;
          UpdateOutput(2, vs.PieceAdd[ vs.KnotTracker ], zs, vs, InputMatrixB, gamma, lambda);
          vs.Scratch = TRUE;
          vs.NewMinimizerKnown = TRUE;
          vs.WasLastIntersect = FALSE;
        }
        else
        {
          vs.Scratch = TRUE; // Scratch tells Compute that it needs to construct the entire new set of intersections
          vs.NewMinimizerKnown = FALSE;
          vs.WasLastIntersect = FALSE;
        }
      }
      else if ( vs.WhichAdd[ vs.KnotTracker ] == 1 )
      {
        //This is if we add a Type A here, but the previous Type B wasn't the current
        //minimizer. We need to add it to the active set, and add its intersection with the current minimizer to Intersects.
        if ( vs.ActiveA == -1 )
        {
          vs.ActiveA = vs.PieceAdd[ vs.KnotTracker ];
          IntersectAddOuter(1, vs.ActiveA, zs, vs, gamma, lambda);
        }
        else if ( zs.TypeAValue[ vs.PieceAdd[ vs.KnotTracker ] ] - zs.TypeAValue[ vs.ActiveA ] < 0 )
        {
          vs.ActiveA = vs.PieceAdd[ vs.KnotTracker ];
          IntersectAddOuter(1, vs.ActiveA, zs, vs, gamma, lambda);

        }
      }
      else if ( vs.WhichAdd[ vs.KnotTracker ] == 2 )
      {
        // If we also add in a type B minimizer but we weren't on the current minimizer before
        vs.ActiveB[ vs.PieceAdd[ vs.KnotTracker ] ] = TRUE;
        IntersectAddOuter(2, vs.PieceAdd[ vs.KnotTracker ], zs, vs, gamma, lambda);
      }
    }
    break;
  case 3:
    // Now we have the case for the removal of the Type C minimizer. We know here that this will always correspond to the
    // addition of a new Type C minimizer (for the next piece), so we need not do any more
    vs.CurrentPiece = vs.PieceAdd[ vs.KnotTracker ];
    if ( ( vs.MinimizerWhich == 3 ) and ( vs.MinimizerPiece == vs.PieceRemove[ vs.KnotTracker ] ) )
    {
      UpdateOutput(3, vs.PieceAdd[ vs.KnotTracker ], zs, vs, InputMatrixB, gamma, lambda);
      vs.Scratch = TRUE;
      vs.NewMinimizerKnown = TRUE;
      vs.WasLastIntersect = FALSE;
    }
    else if ( vs.ActiveIntersectC == TRUE )
    {
      IntersectRemove(3, vs.PieceRemove[ vs.KnotTracker ], vs, gamma, lambda);
      IntersectAddOuter(3, vs.PieceAdd[ vs.KnotTracker ], zs, vs, gamma, lambda);
    }
    else
    {
      IntersectAddOuter(3, vs.PieceAdd[ vs.KnotTracker ], zs, vs, gamma, lambda);
    }
    break;
  }

  if ( JustAdd == TRUE )
  {
    switch (vs.WhichAdd[ vs.KnotTracker ])
    {
    case 1:
      if ( vs.ActiveA == -1 )
      {
        vs.ActiveA = vs.PieceAdd[ vs.KnotTracker ];
        CandidateA = 0;
        CandidateB = 0;
        CandidateC = zs.TypeAValue[ vs.ActiveA ];
        if (  IsBetter(vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC, vs.y) == TRUE )
        {
          UpdateOutput(1, vs.ActiveA, zs, vs, InputMatrixB, gamma, lambda);
          vs.Scratch = TRUE;
          vs.NewMinimizerKnown = TRUE;
        }
        else
        {
          IntersectAddOuter(1, vs.ActiveA, zs, vs, gamma, lambda);
        }
      }
      else if ( zs.TypeAValue[ vs.PieceAdd[ vs.KnotTracker ] ] - zs.TypeAValue[ vs.ActiveA ] < 0 )
      {
        vs.ActiveA = vs.PieceAdd[ vs.KnotTracker ];
        CandidateA = 0;
        CandidateB = 0;
        CandidateC = zs.TypeAValue[ vs.ActiveA ];
        if ( IsBetter( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC, vs.y) == TRUE )
        {
          UpdateOutput(1, vs.ActiveA, zs, vs, InputMatrixB, gamma, lambda);
          vs.Scratch = TRUE;
          vs.NewMinimizerKnown = TRUE;
        }
        else
        {
          IntersectAddOuter(1, vs.ActiveA, zs, vs, gamma, lambda);
        }
      }
      break;
    case 2:
      vs.ActiveB[ vs.PieceAdd[ vs.KnotTracker ] ] = TRUE;
      CandidateA = zs.TypeBCoefA[ vs.PieceAdd[ vs.KnotTracker ] ];
      CandidateB = zs.TypeBCoefB[ vs.PieceAdd[ vs.KnotTracker ] ];
      CandidateC = zs.TypeBCoefC[ vs.PieceAdd[ vs.KnotTracker ] ];
      if ( IsBetter(vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC, vs.y) == TRUE )
      {
        UpdateOutput(2, vs.PieceAdd[ vs.KnotTracker ], zs, vs, InputMatrixB, gamma, lambda);
        vs.Scratch = TRUE;
        vs.NewMinimizerKnown = TRUE;
      }
      else
      {
        IntersectAddOuter(2, vs.PieceAdd[ vs.KnotTracker ], zs, vs, gamma, lambda);
      }
      break;
    }
  }

  vs.WasLastIntersect = FALSE;
  ++vs.KnotTracker;
}



void Decide( const ab_struct& zs, var_struct& vs, NumericMatrix& InputMatrixB, const double& gamma, const double& lambda )
{
  // Highest-level decision function
  // Works out if next event is intersection or knot. If intersection, deals with the entire process. If knot, calls KnotDecide
  if ( vs.IntersectHowMany > 0 )
  {
    if ( vs.KnotTracker < vs.KnotLocation.size() )
    {
      if ( vs.IntersectLocation[ vs.IntersectOrder[ 0 ] ] < vs.KnotLocation[ vs.KnotTracker ] )
      {
        vs.WasLastIntersect = TRUE;
        vs.LastIntersectUpperRootTrue = vs.IntersectUpperRootTrue[ vs.IntersectOrder[ 0 ] ];
        vs.LastIntersectWhich = vs.MinimizerWhich;
        vs.LastIntersectPiece = vs.MinimizerPiece;
        vs.y = vs.IntersectLocation[ vs.IntersectOrder[ 0 ] ];
        vs.RangePiece = WhichPiece(vs.LeftKnot, vs.y - ( gamma * lambda ));
        UpdateOutput(vs.IntersectWhich[ vs.IntersectOrder[ 0 ] ], vs.IntersectPiece[ vs.IntersectOrder[ 0 ] ], zs, vs, InputMatrixB, gamma, lambda);
        vs.Scratch = TRUE;
        vs.NewMinimizerKnown = TRUE;
      }
      else
      {
        KnotDecide(zs, vs, InputMatrixB, gamma, lambda);
      }
    }
    else
    {
      vs.WasLastIntersect = TRUE;
      vs.LastIntersectUpperRootTrue = vs.IntersectUpperRootTrue[ vs.IntersectOrder[ 0 ] ];
      vs.LastIntersectWhich = vs.MinimizerWhich;
      vs.LastIntersectPiece = vs.MinimizerPiece;
      vs.y = vs.IntersectLocation[ vs.IntersectOrder[ 0 ] ];
      vs.RangePiece = WhichPiece(vs.LeftKnot, vs.y - ( gamma * lambda ));
      UpdateOutput(vs.IntersectWhich[ vs.IntersectOrder[ 0 ] ], vs.IntersectPiece[ vs.IntersectOrder[ 0 ] ], zs, vs, InputMatrixB, gamma, lambda);
      vs.Scratch = TRUE;
      vs.NewMinimizerKnown = TRUE;

    }
  }
  else if ( vs.KnotTracker < vs.KnotLocation.size() )
  {
    KnotDecide(zs, vs, InputMatrixB, gamma, lambda);
  }
  else
  {
    vs.FinishIteratation = TRUE;
  }
}



int WhichPiece( const NumericVector LeftKnot, double y )
{
  // Tells us which piece point y lies in (binary search)
  int NumberOfPieces = LeftKnot.size();
  int i = 0, j = NumberOfPieces - 1;
  while ( i < j - 1 )
  {
    int k = ( i + j + 1 ) / 2;
    if ( LeftKnot[ k ] <= y )
    {
      i = k;
    }
    else
    {
      j = k;
    }
  }
  if ( j == i + 1 )
  {
    if ( LeftKnot[ j ] <= y )
    {
      return j;
    }
    else
    {
      return i;
    }
  }
  else
  {
    return j;
  }
}



IntegerVector InversePermutation( const IntegerVector Permutation )
{
  IntegerVector InvPerm(Permutation.size());
  for ( int i = 0; i < Permutation.size(); ++i )
  {
    InvPerm[ Permutation[ i ] ] = i;
  }
  return InvPerm;
}



IntegerVector OrderOfVector( NumericVector x )
{
  // Returns integer vector giving the order of the entries of the input. Uses section copied from stackoverflow
  vector<double> data(x.size());
  vector<int> index(x.size());
  IntegerVector y(x.size());
  for ( int i = 0; i < x.size(); ++i )
  {
    data[ i ] = x[ i ];
  }
  for ( int i = 0; i < index.size(); ++i ) {
    index[ i ] = i;
  }
  sort(index.begin(), index.end(),
       [&](const int& a, const int& b) {
         return (data[a] < data[b]);
       }
  );
  for ( int i = 0; i < x.size(); ++i )
  {
    y[ i ] = index[ i ];
  }
  return y;
}



IntegerVector WhichMinimizes( double y, int& ActiveA, LogicalVector& ActiveB, int& CurrentPiece, int& RangePiece,
                              const NumericVector& CoefA, const NumericVector& CoefB, const NumericVector& CoefC,
                              const NumericVector& TypeAValue, const NumericVector& TypeBCoefA, const NumericVector& TypeBCoefB,
                              const NumericVector& TypeBCoefC )
{
  // Searches through the active set and returns the identity of the minimizer at point y
  IntegerVector BestCouple(2);
  double BestSoFar = INFINITY;
  double ProspectiveValue;
  int BestWhich, BestPiece;
  double BestMargin = INFINITY;

  // First check Type A minimizer
  if ( ActiveA != -1 )
  {
    BestSoFar = TypeAValue[ ActiveA ];
    BestWhich = 1;
    BestPiece = ActiveA;
  }

  // Now check Type B minimizers
  for ( int i = RangePiece; i <= CurrentPiece; ++i )
  {
    if ( ActiveB[ i ] == TRUE )
    {
      ProspectiveValue = TypeBCoefA[ i ] * pow(y, 2) + TypeBCoefB[ i ] * y + TypeBCoefC[ i ];
      if ( ProspectiveValue - BestSoFar < 0 )
      {
        BestMargin = BestSoFar - ProspectiveValue;
        BestSoFar = ProspectiveValue;
        BestWhich = 2;
        BestPiece = i;
      }
    }
  }

  //Lastly look at the Type C minimizer
  ProspectiveValue = CoefA[ CurrentPiece ] * pow(y, 2) + CoefB[ CurrentPiece ] * y + CoefC[ CurrentPiece ];
  if ( ProspectiveValue - BestSoFar < 0 )
  {
    BestMargin = BestSoFar - ProspectiveValue;
    BestSoFar = ProspectiveValue;
    BestWhich = 3;
    BestPiece = CurrentPiece;
  }
  BestCouple[ 0 ] = BestWhich;
  BestCouple[ 1 ] = BestPiece;

  if ( BestMargin - tol1 < 0 )
  {
    return WhichMinimizes(y + 0.1 * tol2, ActiveA, ActiveB, CurrentPiece, RangePiece, CoefA, CoefB, CoefC, TypeAValue, TypeBCoefA, TypeBCoefB,
                          TypeBCoefC);
  }
  else
  {
    return BestCouple;
  }
}



void ConstructIntersects( const int& UpperBoundPieces, const ab_struct& zs, var_struct& vs, const double& gamma, const double& lambda )
{
  // This searches through the active set, adding any intersections with the current minimizer
  vs.IntersectHowMany = 0;
  vs.IntersectCounter = -1;
  vs.IntersectActive = LogicalVector(UpperBoundPieces, FALSE);
  double CandidateA, CandidateB, CandidateC;
  double RootAdd;
  int NumberOfPieces = vs.CoefA.size();

  vs.ActiveIntersectA = FALSE;
  vs.ActiveIntersectB = LogicalVector(NumberOfPieces, FALSE);
  vs.ActiveIntersectC = FALSE;

  // First check Type A
  if ( vs.ActiveA != -1 )
  {
    CandidateA = 0;
    CandidateB = 0;
    CandidateC = zs.TypeAValue[ vs.ActiveA ];
    switch ( ShouldAddIntersect(vs.y, vs.MinimizerWhich, vs.MinimizerPiece, 1, vs.ActiveA, vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA,
                                CandidateB, CandidateC, vs.WasLastIntersect, vs.LastIntersectWhich, vs.LastIntersectPiece, vs.LastIntersectUpperRootTrue) )
    {
    case 0:
      break;
    case 1:
      RootAdd = LowerRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
      IntersectAdd(RootAdd, 1, vs.ActiveA, FALSE, vs, gamma, lambda);
      break;
    case 2:
      RootAdd = UpperRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
      IntersectAdd(RootAdd, 1, vs.ActiveA, TRUE, vs, gamma, lambda);
      break;
    }
  }

  // Now check Type B
  for ( int i = vs.RangePiece; i <= vs.CurrentPiece; ++i )
  {
    if ( vs.ActiveB[ i ] == TRUE )
    {
      CandidateA = zs.TypeBCoefA[ i ];
      CandidateB = zs.TypeBCoefB[ i ];
      CandidateC = zs.TypeBCoefC[ i ];
      switch ( ShouldAddIntersect(vs.y, vs.MinimizerWhich, vs.MinimizerPiece, 2, i, vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA,
                                  CandidateB, CandidateC, vs.WasLastIntersect, vs.LastIntersectWhich, vs.LastIntersectPiece, vs.LastIntersectUpperRootTrue) )
      {
      case 0:
        break;
      case 1:
        RootAdd = LowerRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
        IntersectAdd(RootAdd, 2, i, FALSE, vs, gamma, lambda);
        break;
      case 2:
        RootAdd = UpperRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
        IntersectAdd(RootAdd, 2, i, TRUE, vs, gamma, lambda);
        break;
      }
    }
  }

  // Now check Type C
  CandidateA = vs.CoefA[ vs.CurrentPiece ];
  CandidateB = vs.CoefB[ vs.CurrentPiece ];
  CandidateC = vs.CoefC[ vs.CurrentPiece ];
  switch ( ShouldAddIntersect(vs.y, vs.MinimizerWhich, vs.MinimizerPiece, 3, vs.CurrentPiece, vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA,
                              CandidateB, CandidateC, vs.WasLastIntersect, vs.LastIntersectWhich, vs.LastIntersectPiece, vs.LastIntersectUpperRootTrue) )
  {
  case 0:
    break;
  case 1:
    RootAdd = LowerRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
    IntersectAdd(RootAdd, 3, vs.CurrentPiece, FALSE, vs, gamma, lambda);
    break;
  case 2:
    RootAdd = UpperRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
    IntersectAdd(RootAdd, 3, vs.CurrentPiece, TRUE, vs, gamma, lambda);
    break;
  }

  OrderIntersectOrder(vs.IntersectOrder, vs.IntersectLocation, vs.IntersectActive, vs.IntersectCounter, vs.IntersectIndex, vs.IntersectHowMany);
}



void IntersectAdd( double Location, int Which, int Piece, bool UpperRootTrue, var_struct& vs, const double& gamma, const double& lambda )
{
  // Inner loop for adding intersection to the current intersection set
  ++vs.IntersectCounter;
  vs.IntersectLocation[ vs.IntersectCounter ] = Location;
  vs.IntersectWhich[ vs.IntersectCounter ] = Which;
  vs.IntersectPiece[ vs.IntersectCounter ] = Piece;
  vs.IntersectActive[ vs.IntersectCounter ] = TRUE;
  vs.IntersectUpperRootTrue[ vs.IntersectCounter ] = UpperRootTrue;
  switch ( Which )
  {
  case 1:
    vs.ActiveIntersectA = TRUE;
    break;
  case 2:
    vs.ActiveIntersectB[ Piece ] = TRUE;
    break;
  case 3:
    vs.ActiveIntersectC = TRUE;
    break;
  }
  ++vs.IntersectHowMany;
}



void IntersectAddOuter( int Which, int Piece,
                        const ab_struct& zs, var_struct& vs, const double& gamma, const double& lambda )
{
  // Outer wrapper for IntersectAdd. Decision is made here
  double CandidateA, CandidateB, CandidateC;
  double RootAdd;

  switch (Which)
  {
  case 1:
    CandidateA = 0;
    CandidateB = 0;
    CandidateC = zs.TypeAValue[ Piece ];
    switch ( ShouldAddIntersect(vs.y, vs.MinimizerWhich, vs.MinimizerPiece, 1, vs.ActiveA, vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA,
                                CandidateB, CandidateC, vs.WasLastIntersect, vs.LastIntersectWhich, vs.LastIntersectPiece, vs.LastIntersectUpperRootTrue) )
    {
    case 0:
      break;
    case 1:
      RootAdd = LowerRoot(vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
      IntersectAdd(RootAdd, 1, Piece, FALSE, vs, gamma, lambda);
      OrderIntersectOrder(vs.IntersectOrder, vs.IntersectLocation, vs.IntersectActive, vs.IntersectCounter, vs.IntersectIndex, vs.IntersectHowMany);
      break;
    case 2:
      RootAdd = UpperRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
      IntersectAdd(RootAdd, 1, Piece, TRUE, vs, gamma, lambda);
      OrderIntersectOrder(vs.IntersectOrder, vs.IntersectLocation, vs.IntersectActive, vs.IntersectCounter, vs.IntersectIndex, vs.IntersectHowMany);
      break;
    }
    break;
  case 2:
    CandidateA = zs.TypeBCoefA[ Piece ];
    CandidateB = zs.TypeBCoefB[ Piece ];
    CandidateC = zs.TypeBCoefC[ Piece ];
    switch ( ShouldAddIntersect(vs.y, vs.MinimizerWhich, vs.MinimizerPiece, 2, Piece, vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA,
                                CandidateB, CandidateC, vs.WasLastIntersect, vs.LastIntersectWhich, vs.LastIntersectPiece, vs.LastIntersectUpperRootTrue) )
    {
    case 0:
      break;
    case 1:
      RootAdd = LowerRoot(vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
      IntersectAdd(RootAdd, 2, Piece, FALSE, vs, gamma, lambda);
      OrderIntersectOrder(vs.IntersectOrder, vs.IntersectLocation, vs.IntersectActive, vs.IntersectCounter, vs.IntersectIndex, vs.IntersectHowMany);
      break;
    case 2:
      RootAdd = UpperRoot(vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
      IntersectAdd(RootAdd, 2, Piece, TRUE, vs, gamma, lambda);
      OrderIntersectOrder(vs.IntersectOrder, vs.IntersectLocation, vs.IntersectActive, vs.IntersectCounter, vs.IntersectIndex, vs.IntersectHowMany);
      break;
    }
    break;
  case 3:
    CandidateA = vs.CoefA[ vs.CurrentPiece ];
    CandidateB = vs.CoefB[ vs.CurrentPiece ];
    CandidateC = vs.CoefC[ vs.CurrentPiece ];
    switch ( ShouldAddIntersect(vs.y, vs.MinimizerWhich, vs.MinimizerPiece, 3, Piece, vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA,
                                CandidateB, CandidateC, vs.WasLastIntersect, vs.LastIntersectWhich, vs.LastIntersectPiece, vs.LastIntersectUpperRootTrue) )
    {
    case 0:
      break;
    case 1:
      RootAdd = LowerRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
      IntersectAdd(RootAdd, 3, Piece, FALSE, vs, gamma, lambda);
      OrderIntersectOrder(vs.IntersectOrder, vs.IntersectLocation, vs.IntersectActive, vs.IntersectCounter, vs.IntersectIndex, vs.IntersectHowMany);
      break;
    case 2:
      RootAdd = UpperRoot( vs.MinimizerA, vs.MinimizerB, vs.MinimizerC, CandidateA, CandidateB, CandidateC);
      IntersectAdd(RootAdd, 3, Piece, TRUE, vs, gamma, lambda);
      OrderIntersectOrder(vs.IntersectOrder, vs.IntersectLocation, vs.IntersectActive, vs.IntersectCounter, vs.IntersectIndex, vs.IntersectHowMany);
      break;
    }
    break;
  }
}



void IntersectRemove( int Which, int Piece, var_struct& vs, const double& gamma, const double& lambda )
{
  // Removes intersection from the current set of intersections
  int RemoveIdentifier = -1;
  int i = 0;

  while ( ( i <= vs.IntersectCounter ) and ( RemoveIdentifier == -1 ) )
  {
    if ( ( vs.IntersectPiece[ i ] == Piece ) and ( vs.IntersectWhich[ i ] == Which ) and ( vs.IntersectActive[ i ] == TRUE ) )
    {
      RemoveIdentifier = i;
    }
    ++i;
  }

  if ( RemoveIdentifier >= 0 )
  {
    vs.IntersectActive[ RemoveIdentifier ] = FALSE;
    switch ( Which )
    {
    case 1:
      vs.ActiveIntersectA = FALSE;
      break;
    case 2:
      vs.ActiveIntersectB[ Piece ] = FALSE;
      break;
    case 3:
      vs.ActiveIntersectC = FALSE;
      break;
    }
    --vs.IntersectHowMany;
    OrderIntersectOrder(vs.IntersectOrder, vs.IntersectLocation, vs.IntersectActive, vs.IntersectCounter, vs.IntersectIndex, vs.IntersectHowMany);
  }
}



void OrderIntersectOrder( IntegerVector& IntersectOrder, const NumericVector& IntersectLocation, LogicalVector& IntersectActive,
                          const int& IntersectCounter, IntegerVector& IntersectIndex, const int& IntersectHowMany )
{
  // Orders the intersections that are found
  if ( IntersectHowMany > 0 )
  {
    IntegerVector IndicesOfSubset = IntersectIndex[ IntersectActive ];
    NumericVector IntersectLocationSubset = IntersectLocation[ IntersectActive ];
    IntersectOrder = IndicesOfSubset[ OrderOfVector(IntersectLocationSubset) ];
  }
}




double LowerRoot ( double A1, double B1, double C1, double A2, double B2, double C2 )
{
  double a, b, c;
  a = ( A2 - A1 );
  b = ( B2 - B1 );
  c = ( C2 - C1 );

  //This ensures that LowerRoot is interpretable as the 'smaller' root, rather than just a choice of ±
  if ( a < 0 )
  {
    a = -a;
    b = -b;
    c = -c;
  }

  double Discriminant = pow(b, 2) - 4 * a * c;
  if ( ( abs(a) - tol1 > 0 ) and ( Discriminant - pow(tol1, 2) > 0 ) )
  {
    if ( b < 0 )
    {
      return ( - b - std::sqrt( Discriminant ) ) / ( 2 * a );
    }
    else
    {
      return (( 2 * c ) / ( - b + std::sqrt( Discriminant ) ));
    }
  }
  else if ( Discriminant - pow(tol1, 2) <= 0 )
  {
    return -INFINITY;
  }
  else if ( abs(b) - tol1 > 0 )
  {
    return - c / b;
  }
  else
  {
    return -INFINITY;
  }
}



double UpperRoot ( double A1, double B1, double C1, double A2, double B2, double C2 )
{
  double a, b, c, Discriminant;
  a = ( A2 - A1 );
  b = ( B2 - B1 );
  c = ( C2 - C1 );

  //This ensures that LowerRoot is interpretable as the 'smaller' root, rather than just a choice of ±
  if ( a < 0 )
  {
    a = -a;
    b = -b;
    c = -c;
  }

  Discriminant = pow(b, 2) - 4 * a * c;
  if ( ( abs(a) - tol1 > 0 ) and ( Discriminant - pow(tol1, 2) > 0 ) )
  {
    if ( b < 0 )
    {
      return ( - b + std::sqrt( Discriminant ) ) / ( 2 * a );
    }
    else
    {
      return (( 2 * c) / ( - b - std::sqrt( Discriminant ) ));
    }
  }
  else if ( Discriminant - pow(tol1, 2) <= 0 )
  {
    return -INFINITY;
  }
  else
  {
    return -INFINITY;
  }
}



bool IsBetter( double OldA, double OldB, double OldC, double NewA, double NewB, double NewC, const double& y )
{
  // Checks if new quadratic is lower than current quadratic (looking to higher derivatives in case of draw)
  double OldValue = OldA * pow(y, 2) + OldB * y + OldC;
  double NewValue = NewA * pow(y, 2) + NewB * y + NewC;
  double OldGradient, NewGradient, OldCurvature, NewCurvature;
  if ( NewValue - OldValue + tol1 < 0 )
  {
    return TRUE;
  }
  else if ( OldValue - NewValue + tol1 < 0 )
  {
    return FALSE;
  }
  else
  {
    OldGradient = 2 * OldA * y + OldB;
    NewGradient = 2 * NewA * y + NewB;
    if ( NewGradient - OldGradient + tol1 < 0 )
    {
      return TRUE;
    }
    else if ( OldGradient - NewGradient + tol1 < 0 )
    {
      return FALSE;
    }
    else
    {
      OldCurvature = 2 * OldA;
      NewCurvature = 2 * NewA;
      if ( NewCurvature - OldCurvature + tol1 < 0 )
      {
        return TRUE;
      }
      else if ( OldCurvature - NewCurvature + tol1 < 0 )
      {
        return FALSE;
      }
      else
      {
        return FALSE;
      }
    }
  }
}



void UpdateOutput( const int NewMinimizerWhich, const int NewMinimizerPiece, const ab_struct& zs, var_struct& vs,
                   NumericMatrix& InputMatrixB, const double& gamma, const double& lambda )
{
  // Updates the output whenever we change the quadratic piece
  ++vs.OutputCounter;
  vs.ORightKnot[ vs.OutputCounter ] = vs.y;
  vs.OCoefA[ vs.OutputCounter ] = vs.MinimizerA;
  vs.OCoefB[ vs.OutputCounter ] = vs.MinimizerB;
  vs.OCoefC[ vs.OutputCounter ] = vs.MinimizerC;

  if ( vs.FinishIteratation == FALSE )
  {
    vs.OLeftKnot[ vs.OutputCounter + 1 ] = vs.y;
  }
  else
  {
    vs.ORightKnot[ vs.OutputCounter ] = INFINITY;
  }

  // This updates the entries that are used for the backwards pass
  if ( vs.IterationCounter > 2 )
  {
    for ( int i = 0; i < vs.IterationCounter - 2 ; ++i )
    {
      vs.OutputMatrixB( 2 * i, vs.OutputCounter) = InputMatrixB( 2 * i, vs.MinimizerPiece );
      vs.OutputMatrixB( ( 2 * i ) + 1, vs.OutputCounter ) = InputMatrixB( ( 2 * i ) + 1, vs.MinimizerPiece );
    }
  }
  switch ( vs.MinimizerWhich )
  {
  case 1:
    vs.OutputMatrixB( ( 2 * vs.IterationCounter ) - 4, vs.OutputCounter ) = 0;
    vs.OutputMatrixB( ( 2 * vs.IterationCounter ) - 3, vs.OutputCounter ) = zs.TypeAKnot[ vs.MinimizerPiece ] - ( gamma * lambda );
    break;
  case 2:
    vs.OutputMatrixB( ( 2 * vs.IterationCounter ) - 4, vs.OutputCounter ) = 1 / ( 1 - 2 * vs.CoefA[ vs.MinimizerPiece ] * gamma );
    vs.OutputMatrixB( ( 2 * vs.IterationCounter ) - 3, vs.OutputCounter ) = ( gamma * ( vs.CoefB[ vs.MinimizerPiece ] - lambda ) )
      / ( 1 - 2 * vs.CoefA[ vs.MinimizerPiece ] * gamma );
    break;
  case 3:
    vs.OutputMatrixB( ( 2 * vs.IterationCounter ) - 4, vs.OutputCounter ) = 1;
    vs.OutputMatrixB( ( 2 * vs.IterationCounter ) - 3, vs.OutputCounter ) = 0;
    break;
  }

  // If this is not at the end of the iteration, prepare for the next computation
  if ( vs.FinishIteratation == FALSE )
  {
    vs.MinimizerWhich = NewMinimizerWhich;
    vs.MinimizerPiece = NewMinimizerPiece;
    switch ( vs.MinimizerWhich )
    {
    case 1:
      vs.MinimizerA = 0;
      vs.MinimizerB = 0;
      vs.MinimizerC = zs.TypeAValue[ vs.MinimizerPiece ];
      break;
    case 2:
      vs.MinimizerA = zs.TypeBCoefA[ vs.MinimizerPiece ];
      vs.MinimizerB = zs.TypeBCoefB[ vs.MinimizerPiece ];
      vs.MinimizerC = zs.TypeBCoefC[ vs.MinimizerPiece ];
      break;
    case 3:
      vs.MinimizerA = vs.CoefA[ vs.MinimizerPiece ];
      vs.MinimizerB = vs.CoefB[ vs.MinimizerPiece ];
      vs.MinimizerC = vs.CoefC[ vs.MinimizerPiece ];
      break;
    }
  }
}



int ShouldAddIntersect( double y, int MinimizerWhich, int MinimizerPiece, int CandidateWhich,
                        int CandidatePiece, double MinimizerA, double MinimizerB,
                        double MinimizerC, double CandidateA, double CandidateB, double CandidateC,
                        bool WasLastIntersect, int LastIntersectWhich, int LastIntersectPiece,
                        bool LastIntersectUpperRootTrue )
{
  // Should candidate intersection be added to the set of intersections with the current minimizer
  double ProspectiveRoot;
  bool EventuallyCandidate = FALSE;
  if ( CandidateA - MinimizerA < 0 )
  {
    EventuallyCandidate = TRUE;
  }

  if ( ( MinimizerWhich == CandidateWhich ) and ( MinimizerPiece == CandidatePiece ) )
  {
    return 0;
  }
  else
  {
    if ( ( EventuallyCandidate ) and ( ( WasLastIntersect == FALSE ) or ( LastIntersectWhich != CandidateWhich )
                                         or ( LastIntersectPiece != CandidatePiece ) or ( LastIntersectUpperRootTrue == FALSE ) ) )
    {
      ProspectiveRoot = UpperRoot( MinimizerA, MinimizerB, MinimizerC, CandidateA, CandidateB, CandidateC);
      if ( ProspectiveRoot - y > 0 )
      {
        return 2;
      }
      else
      {
        return 0;
      }
    }
    else if ( ( WasLastIntersect == FALSE ) or ( LastIntersectWhich != CandidateWhich )
                or ( LastIntersectPiece != CandidatePiece ) or ( LastIntersectUpperRootTrue == TRUE ) )
    {
      ProspectiveRoot = LowerRoot( MinimizerA, MinimizerB, MinimizerC, CandidateA, CandidateB, CandidateC);
      if ( ProspectiveRoot > y )
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
}



void Compute( const int& UpperBoundPieces, const ab_struct& zs, var_struct& vs, NumericMatrix& InputMatrixB, const double& gamma, const double& lambda )
{
  // Highest level function called in each iteration
  int NewMinimizerWhich, NewMinimizerPiece;
  IntegerVector BestCouple;
  if ( vs.Scratch == TRUE )
  {
    vs.RangePiece = WhichPiece(vs.LeftKnot, vs.y - ( gamma * lambda ));
    if ( vs.NewMinimizerKnown == FALSE )
    {

      BestCouple = WhichMinimizes(vs.y, vs.ActiveA, vs.ActiveB, vs.CurrentPiece, vs.RangePiece, vs.CoefA, vs.CoefB, vs.CoefC, zs.TypeAValue, zs.TypeBCoefA,
                                  zs.TypeBCoefB, zs.TypeBCoefC);
      NewMinimizerWhich = BestCouple[ 0 ];
      NewMinimizerPiece = BestCouple[ 1 ];
      UpdateOutput(NewMinimizerWhich, NewMinimizerPiece, zs, vs, InputMatrixB, gamma, lambda); //Update the output here as soon as we realise what we're moving over to.
    }
    ConstructIntersects(UpperBoundPieces, zs, vs, gamma, lambda);
    vs.Scratch = FALSE;
  }
  Decide(zs, vs, InputMatrixB, gamma, lambda);
}
