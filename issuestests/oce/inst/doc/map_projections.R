## ---- echo = FALSE------------------------------------------------------------
knitr::opts_chunk$set(collapse = TRUE, comment = "#>")

## -----------------------------------------------------------------------------
library(oce)
data(coastlineWorld)
lon <- coastlineWorld[["longitude"]]
lat <- coastlineWorld[["latitude"]]
par(mar=c(4, 4, 0.5, 0.5))
plot(lon, lat, type="l",
     xlim=c(-130, -50), ylim=c(40, 50))

## -----------------------------------------------------------------------------
par(mar=c(4, 4, 0.5, 0.5))
plot(lon, lat, type="l",
     xlim=c(-130, -50), ylim=c(40, 50), asp=1/cos(45*pi/180))

## -----------------------------------------------------------------------------
plot(coastlineWorld,
     longitudelim=c(-130, -50), latitudelim=c(40, 50))

## -----------------------------------------------------------------------------
data(coastlineWorld)

## ----fig.cap="World coastline with default (Mollweide) projection.", fig.width=5, fig.height=2.7, dpi=72, dev.args=list(pointsize=10)----
par(mar=c(1.5, 1.5, 0.5, 0.5))
mapPlot(coastlineWorld)

## ----fig.cap="Polar view with stereographic projection.", fig.width=5, fig.height=5, dpi=72, dev.args=list(pointsize=10)----
par(mar=c(1.5, 1.5, 0.5, 0.5))
mapPlot(coastlineWorld, longitudelim=c(-130, 50), latitudelim=c(60, 120),
       projection="+proj=stere +lat_0=90", col='gray')

## -----------------------------------------------------------------------------
par(mar=c(1.5, 1.5, 0.5, 0.5))
mapPlot(coastlineWorld,
         longitudelim=c(-130,-55), latitudelim=c(35, 60),
         projection="+proj=lcc +lat_0=30 +lat_1=60 +lon_0=-100", col='gray')

## ----fig.cap="World coastline with Robinson projection.", fig.width=5, fig.height=2.7, dpi=72, dev.args=list(pointsize=10)----
par(mar=rep(0.5, 4))
mapPlot(coastlineWorld, col="lightgray", projection="+proj=robin")

## ----fig.cap="World topography with Mollweide projection.", fig.width=5, fig.height=2.7, dpi=72, dev.args=list(pointsize=10)----
par(mar=c(1.5, 1, 1.5, 1))
data(topoWorld)
topo <- decimate(topoWorld, 2) # coarsen grid: 4X faster plot
lon <- topo[["longitude"]]
lat <- topo[["latitude"]]
z <- topo[["z"]]
cm <- colormap(name="gmt_globe")
drawPalette(colormap=cm)
mapPlot(coastlineWorld, projection="+proj=moll", grid=FALSE, col="lightgray")
mapImage(lon, lat, z, colormap=cm)

## -----------------------------------------------------------------------------
par(mar=c(1.5, 1.5, 0.5, 0.5))
mapPlot(coastlineWorld, longitudelim=c(-180, 180), latitudelim=c(-130, -50),
       projection="+proj=stere +lat_0=-90", col='gray', grid=15)

## ----fig.cap="Eastern North Atlantic with Mercator projection.", fig.width=5, fig.height=5, dpi=72, dev.args=list(pointsize=10)----
par(mar=c(1.5, 1.5, 0.5, 0.5))
mapPlot(coastlineWorld, col="lightgray",
        projection="+proj=merc",
        longitudelim=c(-80, -40), latitudelim=c(20, 60))

## ----fig.cap="Eastern North Atlantic with Albers equal-area projection.", fig.width=5, fig.height=5, dpi=72, dev.args=list(pointsize=10)----
par(mar=c(1.5, 1.5, 0.5, 0.5))
mapPlot(coastlineWorld, col="lightgray",
        projection="+proj=aea +lat_1=30 +lat_2=50 +lon_0=-60",
        longitudelim=c(-80, -40), latitudelim=c(20, 60))

## ----fig.cap="SST contours with the Goode projection", fig.width=5, fig.height=2.7, dpi=72, dev.args=list(pointsize=10)----
par(mar=rep(0.5, 4))
mapPlot(coastlineWorld, projection="+proj=goode", col="lightgray")
if (requireNamespace("ocedata", quietly=TRUE)) {
    data(levitus, package="ocedata")
    mapContour(levitus[['longitude']], levitus[['latitude']], levitus[['SST']])
}

