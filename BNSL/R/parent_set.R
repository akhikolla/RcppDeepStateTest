parent.set=function(df,h,tw=0,proc=1){
N=ncol(df);
for(i in 1:N)df[[i]]=as.integer(df[[i]]);
df=as.matrix(df);
df=parent(df,h,tw,proc);
if(tw==0)tw=N-1;
S=1; for(j in 1:tw)S=S+choose(N-1,j)
df[1:S,]
}

FFtable=function(df){
N=ncol(df);
for(i in 1:N)df[[i]]=as.integer(df[[i]]);
df=as.matrix(df);
tb=table(df[,ncol(df)])
m=length(tb); 
fftable(df,m)
}
