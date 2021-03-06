% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/vis.R
\name{vis.immunr_gene_usage}
\alias{vis.immunr_gene_usage}
\title{Histograms and boxplots (general case / gene usage)}
\usage{
\method{vis}{immunr_gene_usage}(.data, .plot = c("hist", "box", "heatmap", "heatmap2", "circos"), ...)
}
\arguments{
\item{.data}{Output from the \link{geneUsage} function.}

\item{.plot}{String specifying the plot type:

- "hist" for histograms using \link{vis_hist};

- "heatmap" for heatmaps using \link{vis_heatmap};

- "heatmap2" for heatmaps using \link{vis_heatmap2};

- "circos" for circos plots using \link{vis_circos}.}

\item{...}{Other arguments passed to corresponding functions depending on the plot type:

- "hist" - passes arguments to \link{vis_hist};

- "box" - passes arguments to \link{vis_box};

- "heatmap" - passes arguments to \link{vis_heatmap};

- "heatmap2" - passes arguments to \link{vis_heatmap2} and \link{heatmap} from the "pheatmap" package;

- "circos" - passes arguments to \link{vis_circos} and \link{chordDiagram} from the "circlize" package.}
}
\value{
A ggplot2 object, pheatmap or circlize object.
}
\description{
Visualise distributions of genes using heatmaps or other plots.
}
\examples{
data(immdata)

gu <- geneUsage(immdata$data[[1]])
vis(gu)

gu <- geneUsage(immdata$data)
vis(gu, .by = "Status", .meta = immdata$meta)
vis(gu, "box", .by = "Status", .meta = immdata$meta)
}
\seealso{
\link{geneUsage}
}
\concept{gene_usage}
