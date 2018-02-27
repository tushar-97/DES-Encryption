# DES-Encryption

This code was written as part of an assignment to implement DES algorithm for my college course on cryptography. This will take in the message and key (both 64bit in hex) and print the corresponding 16 keys as well as the permutation produced after one feistel round.

The values of the matrices `PC1`,`PC2`,`IP`,`E(Expansion)`,`SBox` and `PBox` have been taken from the Chapter 3 of the textbook `Cryptography & Network Security` by William Stallings. The code can be expanded to produce the 16 permutations after 16 feistel rounds and the resulting encrypted text using `IP-1` matrix.

I found [this](http://page.math.tu-berlin.de/~kant/teaching/hess/krypto-ws2006/des.htm) webpage to be a good resource for this algorithm
