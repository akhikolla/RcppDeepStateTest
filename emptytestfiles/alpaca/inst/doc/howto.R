## ---- eval = FALSE------------------------------------------------------------
#  data(psid, package = "bife")
#  head(psid)

## ---- eval = FALSE------------------------------------------------------------
#  ##    ID LFP KID1 KID2 KID3     INCH AGE TIME
#  ## 1:  1   1    1    1    1 58807.81  26    1
#  ## 2:  1   1    1    0    2 41741.87  27    2
#  ## 3:  1   1    0    1    2 51320.73  28    3
#  ## 4:  1   1    0    1    2 48958.58  29    4
#  ## 5:  1   1    0    1    2 53634.62  30    5
#  ## 6:  1   1    0    0    3 50983.13  31    6

## ---- eval = FALSE------------------------------------------------------------
#  library(alpaca)
#  stat <- feglm(LFP ~ KID1 + KID2 + KID3 + log(INCH) | ID + TIME, psid, binomial("probit"))
#  summary(stat)

## ---- eval = FALSE------------------------------------------------------------
#  ## binomial - probit link
#  ##
#  ## LFP ~ KID1 + KID2 + KID3 + log(INCH) | ID + TIME
#  ##
#  ## Estimates:
#  ##            Estimate Std. error z value Pr(> |z|)
#  ## KID1      -0.676905   0.056301 -12.023   < 2e-16 ***
#  ## KID2      -0.344383   0.049896  -6.902  5.13e-12 ***
#  ## KID3      -0.007039   0.035344  -0.199     0.842
#  ## log(INCH) -0.234136   0.054403  -4.304  1.68e-05 ***
#  ## ---
#  ## Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1
#  ##
#  ## residual deviance= 6069.65,
#  ## null deviance= 8152.05,
#  ## n= 5976, l= [664, 9]
#  ##
#  ## ( 7173 observation(s) deleted due to perfect classification )
#  ##
#  ## Number of Fisher Scoring Iterations: 6

## ---- eval = FALSE------------------------------------------------------------
#  apes.stat <- getAPEs(stat)
#  summary(apes.stat)

## ---- eval = FALSE------------------------------------------------------------
#  ## Estimates:
#  ##             Estimate Std. error z value Pr(> |z|)
#  ## KID1      -0.0880159  0.0394090  -2.233    0.0255 *
#  ## KID2      -0.0447791  0.0234544  -1.909    0.0562 .
#  ## KID3      -0.0009152  0.0110216  -0.083    0.9338
#  ## log(INCH) -0.0304440  0.0209490  -1.453    0.1462
#  ## ---
#  ## Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

## ---- eval = FALSE------------------------------------------------------------
#  stat.bc <- biasCorr(stat)
#  summary(stat.bc)

## ---- eval = FALSE------------------------------------------------------------
#  ## binomial - probit link
#  ##
#  ## LFP ~ KID1 + KID2 + KID3 + log(INCH) | ID + TIME
#  ##
#  ## Estimates:
#  ##            Estimate Std. error z value Pr(> |z|)
#  ## KID1      -0.596292   0.056301 -10.591   < 2e-16 ***
#  ## KID2      -0.303358   0.049896  -6.080   1.2e-09 ***
#  ## KID3      -0.006111   0.035344  -0.173  0.862733
#  ## log(INCH) -0.207068   0.054403  -3.806  0.000141 ***
#  ## ---
#  ## Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1
#  ##
#  ## residual deviance= 6069.65,
#  ## null deviance= 8152.05,
#  ## n= 5976, l= [664, 9]
#  ##
#  ## ( 7173 observation(s) deleted due to perfect classification )
#  ##
#  ## Number of Fisher Scoring Iterations: 6

## ---- eval = FALSE------------------------------------------------------------
#  apes.stat.bc <- getAPEs(stat.bc)
#  summary(apes.stat.bc)

## ---- eval = FALSE------------------------------------------------------------
#  ## Estimates:
#  ##            Estimate Std. error z value Pr(> |z|)
#  ## KID1      -0.096502   0.035943  -2.685   0.00726 **
#  ## KID2      -0.049094   0.022014  -2.230   0.02574 *
#  ## KID3      -0.000989   0.011099  -0.089   0.92900
#  ## log(INCH) -0.033511   0.020299  -1.651   0.09877 .
#  ## ---
#  ## Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

## ---- eval = FALSE------------------------------------------------------------
#  library(data.table)
#  setDT(psid)
#  psid[, LLFP := shift(LFP), by = ID]

## ---- eval = FALSE------------------------------------------------------------
#  dyn <- feglm(LFP ~ LLFP + KID1 + KID2 + KID3 + log(INCH) | ID + TIME, psid, binomial("probit"))
#  dyn.bc <- biasCorr(dyn, L = 1L)
#  summary(dyn.bc)

## ---- eval = FALSE------------------------------------------------------------
#  ## binomial - probit link
#  ##
#  ## LFP ~ LLFP + KID1 + KID2 + KID3 + log(INCH) | ID + TIME
#  ##
#  ## Estimates:
#  ##           Estimate Std. error z value Pr(> |z|)
#  ## LLFP       1.01608    0.04695  21.643   < 2e-16 ***
#  ## KID1      -0.45389    0.06787  -6.687  2.27e-11 ***
#  ## KID2      -0.15737    0.06031  -2.610   0.00907 **
#  ## KID3       0.01562    0.04331   0.361   0.71839
#  ## log(INCH) -0.18834    0.06165  -3.055   0.00225 **
#  ## ---
#  ## Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1
#  ##
#  ## residual deviance= 4777.58,
#  ## null deviance= 6549.14,
#  ## n= 4792, l= [599, 8]
#  ##
#  ## ( 1461 observation(s) deleted due to missingness )
#  ## ( 6896 observation(s) deleted due to perfect classification )
#  ##
#  ## Number of Fisher Scoring Iterations: 6

## ---- eval = FALSE------------------------------------------------------------
#  apes.dyn.bc <- getAPEs(dyn.bc)
#  summary(apes.dyn.bc)

## ---- eval = FALSE------------------------------------------------------------
#  ## Estimates:
#  ##            Estimate Std. error z value Pr(> |z|)
#  ## LLFP       0.186312   0.071057   2.622   0.00874 **
#  ## KID1      -0.072324   0.031894  -2.268   0.02335 *
#  ## KID2      -0.025075   0.018730  -1.339   0.18063
#  ## KID3       0.002489   0.011888   0.209   0.83419
#  ## log(INCH) -0.030011   0.019928  -1.506   0.13207
#  ## ---
#  ## Signif. codes:  0 ‘***’ 0.001 ‘**’ 0.01 ‘*’ 0.05 ‘.’ 0.1 ‘ ’ 1

