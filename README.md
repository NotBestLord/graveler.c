# graveler.c

Basically:<br>
Python = No No<br>
C = Yes Yes<br>
<br>
## Method #1
Replaced list shenanigans with [rand() % 4], simple as.<br>
100000 Sessions takes ~450ms to run, or 0.45s.<br>
<br>
## Method #2
Inspired by @kgaughan method of getting 2 random bits (4 possible outcomes/random of 4),<br>
The rand() generates a random 16 bit integer, or in other words, 8 pairs of 2 bits.<br>
Due to a limitation where the last bit of the number is always 0 (due to signed/unsigned int),<br>
Only 7 "Dice Throws" could  be extracted from 1 rand() call.<br>
<br>
This method reduced the time taken to run 100000 Sessions,<br>
to ~150ms, or 0.15s.<br>
