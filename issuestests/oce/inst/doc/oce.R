## ---- echo = FALSE------------------------------------------------------------
knitr::opts_chunk$set(collapse = TRUE, comment = "#>")

## ----eval=FALSE---------------------------------------------------------------
#  ?`[[,oce-method`

## ----eval=FALSE---------------------------------------------------------------
#  ?`[[,ctd-method`

## ----eval=FALSE---------------------------------------------------------------
#  S <- d[['salinity']]

## ----eval=FALSE---------------------------------------------------------------
#  data <- d[['data']]

## ----eval=FALSE---------------------------------------------------------------
#  data$temperature

## ----eval=FALSE---------------------------------------------------------------
#  data(ctd)
#  ctd[["temperatureAboveFreezing"]] <- ctd[["temperature"]] - swTFreeze(ctd)

## ----eval=FALSE---------------------------------------------------------------
#  ?"[[<-,oce-method"

## ----extractExample, eval=FALSE-----------------------------------------------
#  ctd[["metadata"]]$scientist <- "Dalhousie Oceanography 4120/5120 Class of 2003"

## ----eval=FALSE---------------------------------------------------------------
#  ctd <- oceSetMetadata(ctd, name="scientist",
#                        value="Dalhousie Oceanography 4120/5120 Class of 2003",
#                        note="give credit where it's due")

## ----eval=FALSE---------------------------------------------------------------
#  ctd <- oceSetData(ctd, name="temperatureAboveFreezing",
#                        value=ctd[["temperature"]] - swTFreeze(ctd),
#                        unit=list(unit=expression(degree*C), scale="ITS-90"),
#                        originalName="-",
#                        note="add temperatureAboveFreezing, for ice-related calculations")

## ----eval=FALSE---------------------------------------------------------------
#  library(oce)
#  d <- read.oce("station1.cnv")
#  summary(d)
#  plot(d)

## ----eval=FALSE---------------------------------------------------------------
#  data(section)
#  plot(section, which=c(1, 2, 3, 99))

## ----fig.cap="**Figure 4.** Portion of the CTD section designated A03, showing the Gulf Sream region.  The square on the cruise track corresponds to zero distance on the section.", fig.width=4, fig.height=4, dpi=72, dev.args=list(pointsize=12)----
library(oce)
data(section)
GS <- subset(section, 102 <= stationId & stationId <= 124)
GSg <- sectionGrid(GS, p=seq(0, 1600, 25))
plot(GSg, which=c(1,99), map.xlim=c(-85,-(64+13/60)))

## ----fig.cap="**Figure 9.** Sea-level timeseries measured in 2003 in Halifax Harbour.", fig.width=5, fig.height=4, dpi=72, dev.args=list(pointsize=16)----
library(oce)
data(sealevel)
plot(sealevel)

## ----fig.cap="**Figure 10.** Measurements made with a bottom-mounted ADP in the St Lawrence Estuary. The line near the surface indicates pressure measured by the ADP.", fig.width=4, fig.height=2, dpi=72----
library(oce)
data(adp)
plot(adp, which=1)
lines(adp[['time']], adp[['pressure']], lwd=2)

## ----fig.keep="none"----------------------------------------------------------
library(oce)
Sys.setenv(LANGUAGE="fr")
data(ctd)
plot(ctd)

## ----echo=FALSE---------------------------------------------------------------
Sys.setenv(LANGUAGE="en")

## ----fig.width=5, fig.height=5, fig.keep="none"-------------------------------
library(oce)
swRho(34, 10, 100, eos="unesco")
swTheta(34, 10, 100, eos="unesco")
swRho(34, swTheta(34, 10, 100, eos="unesco"), 0, eos="unesco")
swRho(34, swTheta(34, 10, 100, 200, eos="unesco"), 200, eos="unesco")
plotTS(as.ctd(c(30,40),c(-2,20),rep(0,2)), eos="unesco", grid=TRUE, col="white")

## ----fig.width=5, fig.height=5, fig.keep="none"-------------------------------
library(oce)
data(section)
s <- handleFlags(section, flags=list(c(1, 3:9)))
ctd <- as.ctd(s[["salinity"]], s[["temperature"]], s[["pressure"]],
              longitude=s[["longitude"]], latitude=s[["latitude"]])
col <- ifelse(s[["longitude"]] > -30, "black", "gray")
plotTS(ctd, col=col, eos="gsw")

## ----fig.width=5, fig.height=3, fig.keep="none"-------------------------------
library(oce)
data(section)
GS <- subset(section, 102 <= stationId & stationId <= 124)
dh <- swDynamicHeight(GS)
par(mfrow=c(2,1), mar=c(3, 3, 1, 1), mgp=c(2, 0.7, 0))
plot(dh$distance, dh$height, type="l", xlab="", ylab="Dyn. Height [m]")
grid()
# 1e3 metres per kilometre
latMean <- mean(GS[["latitude"]])
f <- coriolis(latMean)
g <- gravity(latMean)
v <- diff(dh$height)/diff(dh$distance) * g / f / 1e3
plot(dh$distance[-1], v, type="l", xlab="Distance [km]", ylab="Velocity [m/s]")
grid()
abline(h=0, col='red')

## ----fig.width=7, fig.height=3, fig.keep="none"-------------------------------
library(oce)
data(sealevel)
# Focus on 2003-Sep-28 to 29th, the time when Hurricane Juan caused flooding
plot(sealevel,which=1,xlim=as.POSIXct(c("2003-09-24","2003-10-05"), tz="UTC"))
abline(v=as.POSIXct("2003-09-29 04:00:00", tz="UTC"), col="red")
mtext("Juan", at=as.POSIXct("2003-09-29 04:00:00", tz="UTC"), col="red")

## ----results="hide", fig.keep="none"------------------------------------------
library(oce)
data(sealevel)
m <- tidem(sealevel)
oce.plot.ts(sealevel[['time']], sealevel[['elevation']] - predict(m),
            ylab="Detided sealevel [m]", 
            xlim=c(as.POSIXct("2003-09-20"), as.POSIXct("2003-10-08")))

