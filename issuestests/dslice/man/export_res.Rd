\name{export_res}
\alias{export_res}
\title{
  Export gene set analysis result
}
\description{
  Export gene set analysis result.
}
\usage{
  export_res(ds_gsa_obj, file = "", ..., cutoff = 1, decreasing = FALSE, 
             type = c("name", "size", "DS", "p-value", "FDR", "slice"))
}
\arguments{
  \item{ds_gsa_obj}{Object returned by \code{ds_gsa} function.}
  \item{file}{Either a character string naming a file or a connection open for writing. "" indicates output to the console.}
  \item{...}{Parameters of \code{write.table}.}
  \item{cutoff}{threshold for selecting gene set analysis result according to parameter \code{type}.}
  \item{decreasing}{Ranking results decreasingly (default) or ascendingly.}
  \item{type}{Opitons for ranking results by gene set name (``name''), gene set size (``size''), value of dynamic slicing statistic ("\code{DS}"), \emph{p}-value ("\code{p-value}"), false discovery rate ("\code{FDR}") or number of slices ("\code{slice}").}
}
\details{
  The usage of \code{export_res} is similar to \code{write.table}.
}
\seealso{
The `R Data Import/Export' manual.
}
\examples{
\dontrun{
ds_gsa_obj <- ds_gsa(expdat, geneset, label, fc, lambda = 1.2, bycol = TRUE,
                 minsize = 15, maxsize = 500, randseed = 11235, rounds = 100)
export_res(ds_gsa_obj, "ds_gsa_res.txt", sep = "\t", type = "DS", cutoff = 0,
           row.names = F, col.names = T, quote = F, append = F)
}
}

