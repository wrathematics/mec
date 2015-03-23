#' @export
encode <- function(str)
{
  if (!is.character(str))
    stop("feed me strings")
  
  ### TODO vectors
  
  .Call(R_mec_encode, str)
}



#' @export
decode <- function(str)
{
  if (!is.character(str))
    stop("feed me strings")
  
  ### TODO vectors
  
  .Call(R_mec_decode, str)
}



#' @export
bitprint <- function(str)
{
  if (!is.character(str))
    stop("feed me strings")
  
  ### TODO vectors
  
  invisible(.Call(R_mec_print, str))
}

