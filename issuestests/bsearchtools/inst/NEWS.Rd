\name{NEWS}
\title{News for Package \pkg{bsearchtools}}
\newcommand{\ghissue}{\href{https://github.com/digEmAll/bsearchtools/issues/#1}{##1}}

\section{Changes in bsearchtools version 0.0.61 (2017-02-22)}{
  \itemize{
   
    \item Bug Fixes :
    \itemize{
      \item Fixed: R \code{v3.4+} requires native symbols registration (\ghissue{9})
    }
   
  }
}

\section{Changes in bsearchtools version 0.0.59 (2017-01-22)}{
  \itemize{
   
    \item Bug Fixes :
    \itemize{
      \item Fixed: \code{print.DFI.FEXPR} not actually printing but just returning the string (\ghissue{6})
      \item Fixed: \code{NOT} condition not working anymore in version 0.0.47 (\ghissue{7})
    }
    
    \item New Features :
    \itemize{
      \item Added \code{EQNA} condition to select NA values in DFI objects. (\ghissue{8})
      \item Improved \code{unionIndexesList},\code{OR},\code{IN} performances
    }
    
  }
}


\section{Changes in bsearchtools version 0.0.47 (2016-12-12)}{
  \itemize{
    \item Breaking Changes :
    \itemize{
      \item Standard \code{data.frame}/\code{matrix} subset and replacement operators do not work anymore on \code{DFI} objects but you need perform them on \code{DFI.unWrap(DFIobj)}.
            This decision has been made to avoid wrong unnoticed results when \code{DFI} objects are modified. Also, the internal representation has changed and it
            may be subjected to further changes in the future, so the users should not rely on the current structure but only use the provided functions. (\ghissue{5})
    }
    
    \item Bug Fixes :
    \itemize{
      \item Fixed: \code{print.DFI} not working properly when \code{DFI} wraps a \code{matrix} (\ghissue{1})
      \item Fixed: \code{DFI.subset} ignoring \code{return.indexes=FALSE} when \code{filter=NULL} (\ghissue{2})
    }
    
    \item New Features :
    \itemize{
      \item Added drop argument support in \code{DFI.subset} function. (\ghissue{3})
    }
    
  }
}