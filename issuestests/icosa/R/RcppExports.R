# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

Collapse_ <- function(vect) {
    .Call(`_icosa_Collapse_`, vect)
}

ArcDist_ <- function(coord1, coord2, origin, method) {
    .Call(`_icosa_ArcDist_`, coord1, coord2, origin, method)
}

SymmetricArcDistMat_ <- function(xyzMat, origin, method) {
    .Call(`_icosa_SymmetricArcDistMat_`, xyzMat, origin, method)
}

ArcDistMat_ <- function(gridPoints, queries, origin, method) {
    .Call(`_icosa_ArcDistMat_`, gridPoints, queries, origin, method)
}

ArcDistMany_ <- function(p0, p1, origin, method) {
    .Call(`_icosa_ArcDistMany_`, p0, p1, origin, method)
}

whichMinVector_ <- function(one) {
    .Call(`_icosa_whichMinVector_`, one)
}

Aggregate_ <- function(gridPoints, queries, origin) {
    .Call(`_icosa_Aggregate_`, gridPoints, queries, origin)
}

edges_ <- function(v, e, origin, method) {
    .Call(`_icosa_edges_`, v, e, origin, method)
}

SphericalTriangleSurface_ <- function(coord1, coord2, coord3, origin, pi) {
    .Call(`_icosa_SphericalTriangleSurface_`, coord1, coord2, coord3, origin, pi)
}

spherTriSurfs <- function(v, f, origin, pi) {
    .Call(`_icosa_spherTriSurfs`, v, f, origin, pi)
}

surfConvHullTri <- function(v, cent, origin, pi) {
    .Call(`_icosa_surfConvHullTri`, v, cent, origin, pi)
}

SplitArc_ <- function(coord1, coord2, center, breaks, onlyNew) {
    .Call(`_icosa_SplitArc_`, coord1, coord2, center, breaks, onlyNew)
}

GreatCircle_ <- function(coord1, coord2, origin, breaks, pi) {
    .Call(`_icosa_GreatCircle_`, coord1, coord2, origin, breaks, pi)
}

NeighbourOfOneFace_ <- function(faces, faceNo) {
    .Call(`_icosa_NeighbourOfOneFace_`, faces, faceNo)
}

DirectNeighboursTri_ <- function(faces) {
    .Call(`_icosa_DirectNeighboursTri_`, faces)
}

AllNeighboursTri_ <- function(allFaces, div) {
    .Call(`_icosa_AllNeighboursTri_`, allFaces, div)
}

GetPatch_ <- function(faceNeighbours, activeFaces, startFace, maxRound) {
    .Call(`_icosa_GetPatch_`, faceNeighbours, activeFaces, startFace, maxRound)
}

Partition_ <- function(faceNeighbours, activeFaces, maxRound) {
    .Call(`_icosa_Partition_`, faceNeighbours, activeFaces, maxRound)
}

Refine2d_ <- function(From, breaks) {
    .Call(`_icosa_Refine2d_`, From, breaks)
}

SphericalTriangleCenter_ <- function(v0, v1, v2, origin) {
    .Call(`_icosa_SphericalTriangleCenter_`, v0, v1, v2, origin)
}

EdgesFromPoints_ <- function(verts, howMany, origin) {
    .Call(`_icosa_EdgesFromPoints_`, verts, howMany, origin)
}

stl_sort <- function(x) {
    .Call(`_icosa_stl_sort`, x)
}

EdgesToFaces_ <- function(edges) {
    .Call(`_icosa_EdgesToFaces_`, edges)
}

TriangleTesselation_ <- function(v0, v1, v2, origin, lineBreak) {
    .Call(`_icosa_TriangleTesselation_`, v0, v1, v2, origin, lineBreak)
}

SizeEstimate_ <- function(tesselation) {
    .Call(`_icosa_SizeEstimate_`, tesselation)
}

IcosahedronTesselation_ <- function(oldV, oldF, tesselation, origin) {
    .Call(`_icosa_IcosahedronTesselation_`, oldV, oldF, tesselation, origin)
}

expandFacesToEdges_ <- function(faces) {
    .Call(`_icosa_expandFacesToEdges_`, faces)
}

orderTriGrid_ <- function(faces, neigh, startFaces, startVert, nBelts, nV) {
    .Call(`_icosa_orderTriGrid_`, faces, neigh, startFaces, startVert, nBelts, nV)
}

allTriangleCenters_ <- function(v, f, origin) {
    .Call(`_icosa_allTriangleCenters_`, v, f, origin)
}

CreateHexaSubfaces_ <- function(n, f, nV) {
    .Call(`_icosa_CreateHexaSubfaces_`, n, f, nV)
}

HexaFaces_ <- function(fOrd) {
    .Call(`_icosa_HexaFaces_`, fOrd)
}

RetrieveIndexMat_ <- function(indices) {
    .Call(`_icosa_RetrieveIndexMat_`, indices)
}

InverseWeightByFaceCenter_ <- function(fcNew, loc, n, fcOld, values, origin, deg) {
    .Call(`_icosa_InverseWeightByFaceCenter_`, fcNew, loc, n, fcOld, values, origin, deg)
}

OccupiedCellUpSampling_ <- function(values, loc) {
    .Call(`_icosa_OccupiedCellUpSampling_`, values, loc)
}

ExpandBoundariesToCols_ <- function(f, v, res, origin, pent) {
    .Call(`_icosa_ExpandBoundariesToCols_`, f, v, res, origin, pent)
}

ShapeTri_ <- function(p0, p1, p2) {
    .Call(`_icosa_ShapeTri_`, p0, p1, p2)
}

AllShapeTri_ <- function(v, f) {
    .Call(`_icosa_AllShapeTri_`, v, f)
}

expandEdges_ <- function(eExp, center, res) {
    .Call(`_icosa_expandEdges_`, eExp, center, res)
}

ExpandEdgesByFacesTri_ <- function(origV, origSubF, center, breaks) {
    .Call(`_icosa_ExpandEdgesByFacesTri_`, origV, origSubF, center, breaks)
}

edgeListFromNeighbours_ <- function(outN) {
    .Call(`_icosa_edgeListFromNeighbours_`, outN)
}

EvenInterpolation_ <- function(xyz, origin, critValue) {
    .Call(`_icosa_EvenInterpolation_`, xyz, origin, critValue)
}

centroidPoints_ <- function(coords, combin, center, breaks) {
    .Call(`_icosa_centroidPoints_`, coords, combin, center, breaks)
}

projectCloseToPoint_ <- function(coords, toPoint, center, breaks) {
    .Call(`_icosa_projectCloseToPoint_`, coords, toPoint, center, breaks)
}

xxxxyyyyzzzz_ <- function(v, f) {
    .Call(`_icosa_xxxxyyyyzzzz_`, v, f)
}

xyz1xyz1xyz1xyz1_ <- function(v, f) {
    .Call(`_icosa_xyz1xyz1xyz1xyz1_`, v, f)
}

xyz1 <- function(q) {
    .Call(`_icosa_xyz1`, q)
}

edgeMatTri_ <- function(v, e) {
    .Call(`_icosa_edgeMatTri_`, v, e)
}

triMatTri_ <- function(v, f) {
    .Call(`_icosa_triMatTri_`, v, f)
}

pointLayerColorOrder_ <- function(f) {
    .Call(`_icosa_pointLayerColorOrder_`, f)
}

