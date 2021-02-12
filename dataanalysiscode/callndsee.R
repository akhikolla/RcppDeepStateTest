arg.list <- list(
samples =c(1,2,345,6)
)
package_name <- "AGread"
fun <- get("zero2one", getNamespace(package_name))
ress <- do.call(fun,arg.list)
str(ress)
