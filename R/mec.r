encode1 <- function(str) .Call(R_mec_encode, str)

#' encode
#' 
#' Encode a string according to the MECA (Missy Elliott Cryptographic
#' Algorithm).  Namely, we shift the bits down, flip it, and reverse
#' it.
#' 
#' @param str
#' A string vector.
#' 
#' @return
#' A string vector of the same length as the input.
#' 
#' @examples
#' str <- "a b a c a b b"
#' encode(str)
#' 
#' @export
encode <- function(str)
{
  if (!is.character(str))
    stop("feed me strings")
  
  if (length(str) > 1)
    sapply(str, encode1)
  else
    encode1(str)
}



decode1 <- function(str) .Call(R_mec_decode, str)

#' decode
#' 
#' Decode a string according to the MECA (Missy Elliott Cryptographic
#' Algorithm).  It's the reverse process of the MECA encoding.
#' 
#' @param str
#' A string vector.
#' 
#' @return
#' A string vector of the same length as the input.
#' 
#' @examples
#' str <- "a b a c a b b"
#' decode(str)
#' 
#' @export
decode <- function(str)
{
  if (!is.character(str))
    stop("feed me strings")
  
  if (length(str) > 1)
    sapply(str, decode1)
  else
    decode1(str)
}



bitprint1 <- function(str) invisible(.Call(R_mec_print, str))

#' bitprint
#' 
#' Prints the bits of a string.  Useful to see that \code{encode()}
#' does indeed do what the docs say it does.
#' 
#' @param str
#' A string vector.
#' 
#' @examples
#' str <- "a b a c a b b"
#' bitprint(str)
#' 
#' @export
bitprint <- function(str)
{
  if (!is.character(str))
    stop("feed me strings")
  
  if (length(str) > 1)
    sapply(str, bitprint1)
  else
    bitprint1(str)
}

