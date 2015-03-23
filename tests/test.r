library(mec)

str <- "abc"
str
bitprint(str)

enc <- encode(str)
enc
bitprint(enc)

dec <- decode(enc)
dec

all.equal(dec, str)
