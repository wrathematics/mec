# Missy Elliott Croptography [![Build Status](https://travis-ci.org/wrathematics/mec.png)](https://travis-ci.org/wrathematics/mec) [![License](http://img.shields.io/badge/license-BSD%202--Clause-orange.svg?style=flat)](http://opensource.org/licenses/BSD-2-Clause)


This implements the MECA, or [Missy Elliott Cryptography Algorithm](https://www.youtube.com/watch?v=UODX_pYpVxk).
Specifically, if you gotta big string, lemme search it

```r
01100001
```

shift yo bits down

```r
11000010
```

flip it 

```r
00111101
```

and reverse it.

```r
10111100
```

Inspired by the Ruby project [missy_elliott](https://github.com/tom-lord/missy_elliott),
which is itself inspired from an [ancient XKCD comic](https://xkcd.com/153/).


## Package Usage

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


