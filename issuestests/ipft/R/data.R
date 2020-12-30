#' Indoor localization training data set to test Indoor Positioning System that
#' rely on WLAN/WiFifingerprint. It was created during the Fingerprinting-based Indoor
#' Positioning tutorial of the seventh international conference on indoor Positioning and Indoor
#' Navigation (IPIN2016).
#'
#' @source UJI - Institute of New Imaging Technologies, Universitat Jaume I,
#' Avda. Vicente Sos Baynat S/N, 12071, Castellón, Spain. \url{http://www.init.uji.es/}
#' @format A data frame with columns:
#' \describe{
#'  \item{wap1, wap2, wap3, wap4, wap5, wap6, wap7, wap8, wap9, wap10, wap11, wap12, wap13, wap14, wap15, wap16, wap17, wap18, wap19, wap20, wap21, wap22, wap23, wap24, wap25, wap26, wap27, wap28, wap29, wap30, wap31, wap32, wap33, wap34, wap35, wap36, wap37, wap38, wap39, wap40, wap41, wap42, wap43, wap44, wap45, wap46, wap47, wap48, wap49, wap50, wap51, wap52, wap53, wap54, wap55, wap56, wap57, wap58, wap59, wap60, wap61, wap62, wap63, wap64,  wap65, wap66, wap67, wap68, wap69, wap70, wap71, wap72, wap73, wap74, wap75, wap76, wap77, wap78, wap79, wap80, wap81, wap82, wap83, wap84, wap85, wap86, wap87, wap88, wap89, wap90, wap91, wap92, wap93, wap94, wap95, wap96,  wap97, wap98, wap99, wap100, wap101, wap102, wap103, wap104, wap105, wap106, wap107, wap108, wap109, wap110, wap111, wap112, wap113, wap114, wap115, wap116, wap117, wap118, wap119, wap120, wap121, wap122, wap123, wap124,  wap125, wap126, wap127, wap128, wap129, wap130, wap131, wap132, wap133, wap134, wap135, wap136, wap137, wap138, wap139, wap140, wap141, wap142, wap143, wap144, wap145, wap146, wap147, wap148, wap149, wap150, wap151, wap152,  wap153, wap154, wap155, wap156, wap157, wap158, wap159, wap160, wap161, wap162, wap163, wap164, wap165, wap166, wap167, wap168}{Intensity value for WAPs. Negative integer values from -99 to 0. NA is used if WAP was not detected.}
#'  \item{X}{X coordinate in meters relative to the origin of a predefined Cartesian coordinate system. From -0.60 to 4.39}
#'  \item{Y}{Y coordinate in meters relative to the origin of a predefined Cartesian coordinate system. From 0.00 to 30.42}
#'  \item{FLOOR}{All the records of this dataset have been captured in the same floor. Therefore, the floor attribute is 0 to all the records.}
#'  \item{BUILDINGID}{All the records of this dataset have been captured in the same building. Therefore, the building attribute is 0 to all the records.}
#'  \item{SPACEID}{Internal ID number to identify the position at where the capture was taken.}
#'  \item{USERID}{User identifier. Students created the train dataset (UserID from 1 to 8), and professors the test one (UserID is 0 in this case).}
#'  \item{PHONEID}{All the records have 0 in this attribute. This attribute is not used in this dataset.}
#'  \item{TIMESTAMP}{UNIX Time when the capture was taken.}
#' }
#' @examples
#' \dontrun{
#'  ipftrain
#' }
"ipftrain"

#' Indoor localization test data set to test Indoor Positioning System that
#' rely on WLAN/WiFifingerprint. It was created during the Fingerprinting-based Indoor
#' Positioning tutorial of the seventh international conference on indoor Positioning and Indoor
#' Navigation (IPIN2016).
#'
#' @source UJI - Institute of New Imaging Technologies, Universitat Jaume I,
#' Avda. Vicente Sos Baynat S/N, 12071, Castellón, Spain. \url{http://www.init.uji.es/}
#' @format A data frame with columns:
#' \describe{
#'  \item{wap1, wap2, wap3, wap4, wap5, wap6, wap7, wap8, wap9, wap10, wap11, wap12, wap13, wap14, wap15, wap16, wap17, wap18, wap19, wap20, wap21, wap22, wap23, wap24, wap25, wap26, wap27, wap28, wap29, wap30, wap31, wap32, wap33, wap34, wap35, wap36, wap37, wap38, wap39, wap40, wap41, wap42, wap43, wap44, wap45, wap46, wap47, wap48, wap49, wap50, wap51, wap52, wap53, wap54, wap55, wap56, wap57, wap58, wap59, wap60, wap61, wap62, wap63, wap64,  wap65, wap66, wap67, wap68, wap69, wap70, wap71, wap72, wap73, wap74, wap75, wap76, wap77, wap78, wap79, wap80, wap81, wap82, wap83, wap84, wap85, wap86, wap87, wap88, wap89, wap90, wap91, wap92, wap93, wap94, wap95, wap96,  wap97, wap98, wap99, wap100, wap101, wap102, wap103, wap104, wap105, wap106, wap107, wap108, wap109, wap110, wap111, wap112, wap113, wap114, wap115, wap116, wap117, wap118, wap119, wap120, wap121, wap122, wap123, wap124,  wap125, wap126, wap127, wap128, wap129, wap130, wap131, wap132, wap133, wap134, wap135, wap136, wap137, wap138, wap139, wap140, wap141, wap142, wap143, wap144, wap145, wap146, wap147, wap148, wap149, wap150, wap151, wap152,  wap153, wap154, wap155, wap156, wap157, wap158, wap159, wap160, wap161, wap162, wap163, wap164, wap165, wap166, wap167, wap168}{Intensity value for WAPs. Negative integer values from -99 to 0. NA is used if WAP was not detected.}
#'  \item{X}{X coordinate in meters relative to the origin of a predefined Cartesian coordinate system. From -0.60 to 4.39}
#'  \item{Y}{Y coordinate in meters relative to the origin of a predefined Cartesian coordinate system. From 0.00 to 30.42}
#'  \item{FLOOR}{All the records of this dataset have been captured in the same floor. Therefore, the floor attribute is 0 to all the records.}
#'  \item{BUILDINGID}{All the records of this dataset have been captured in the same building. Therefore, the building attribute is 0 to all the records.}
#'  \item{SPACEID}{Internal ID number to identify the position at where the capture was taken.}
#'  \item{USERID}{User identifier. Students created the train dataset (UserID from 1 to 8), and professors the test one (UserID is 0 in this case).}
#'  \item{PHONEID}{All the records have 0 in this attribute. This attribute is not used in this dataset.}
#'  \item{TIMESTAMP}{UNIX Time when the capture was taken.}
#' }
#' @examples
#' \dontrun{
#'  ipftest
#' }
"ipftest"



#' Indoor localization data set with the positions of the wireless access points present
#' in the ipftrain and ipftest data sets. Unknown locations are stored as NAs.
#' Data from the positioning tutorial of the seventh international conference on indoor Positioning and Indoor
#' Navigation (IPIN2016).
#'
#' @source UJI - Institute of New Imaging Technologies, Universitat Jaume I,
#' Avda. Vicente Sos Baynat S/N, 12071, Castellón, Spain. \url{http://www.init.uji.es/}
#' @format A data frame with columns:
#' \describe{
#'  \item{X}{X coordinate in meters relative to the origin of a predefined Cartesian coordinate system. From -61 to 50}
#'  \item{Y}{Y coordinate in meters relative to the origin of a predefined Cartesian coordinate system. From 8.5 to 117.5}
#' }
#' @examples
#' \dontrun{
#'  ipfpwap
#' }
"ipfpwap"

