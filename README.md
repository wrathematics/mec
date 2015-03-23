# Missy Elliott Croptography [![Build Status](https://travis-ci.org/wrathematics/mec.png)](https://travis-ci.org/wrathematics/mec) [![License](http://img.shields.io/badge/license-BSD%202--Clause-orange.svg?style=flat)](http://opensource.org/licenses/BSD-2-Clause)


This implements the MECA, or [Missy Elliott Cryptography Algorithm](https://www.youtube.com/watch?v=UODX_pYpVxk).

Inspired by the Ruby project [missy_elliott](https://github.com/tom-lord/missy_elliott),
which is itself inspired from an [ancient XKCD comic](https://xkcd.com/153/).


## Package Usage

Shift yo bits down, flip it and reverse it.

```r
library(mec)

str <- "abc"
str
# [1] "abc"

enc <- encode(str)
enc
# [1] "\xbcܜ"

dec <- decode(enc)
dec
# [1] "abc"
```

There is also a utility you can use to convince yourself that
it really does work the way I say it does:

```r
bitprint(str)
# 01100001
# 01100010
# 01100011

bitprint(enc)
# 10111100
# 11011100
# 10011100
```


## Installation

```r
devtools::install_github("wrathematics/mec")
```


