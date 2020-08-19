BayesClassification = function(Data,Means,SDs,Weights,IsLogDistribution=Means*0,
                               ClassLabels=c(1:length(Means))){
# Cls = BayesClassification(Data,M,S,W) 
# [Cls, DecisonBoundaries] = BayesClassification(Data,M,S,W,IsLogDistribution,ClassLabels) 
# Bayes Klassifikation den Daten zuordnen
# INPUT
# Data(1:n,1:d)             Data
# Means(1:L),SDs(1:L),Weights(1:L)      parameters of the Gaussians/LogNormals
# 
# OPTIONAL
# IsLogDistribution(1:L)   ==1 if distribution(i) is a LogNormal, default Zeros
#
# OUTPUT
# Cls
# DecisonBoundaries(1:L-1)



DecisionBoundaries = BayesDecisionBoundaries(Means,SDs,Weights,IsLogDistribution) 
Cls = ClassifyByDecisionBoundaries(Data,DecisionBoundaries,ClassLabels) 

return(list(Cls=Cls, DecisionBoundaries=DecisionBoundaries))
}