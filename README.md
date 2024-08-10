# graveler.c

See https://github.com/arhourigan/graveler for context.<br>
<br>
Basically:<br>
Python = No No<br>
C = Yes Yes<br>
<br>
In this code example, all versions ran 100000 Sessions, with 231 iterations of a d4 in each.<br>
<br>
## Method #1
Replaced list shenanigans with [rand() % 4], simple as.<br>
It took ~450ms to run, or 0.45s.<br>
<br>
This Version is labeled "v1.c".<br>
<br>
## Method #2
Inspired by @kgaughan method of getting 2 random bits (4 possible outcomes/random of 4),<br>
The rand() generates a random 16 bit integer, or in other words, 8 pairs of 2 bits.<br>
Due to a limitation where the last bit of the number is always 0 (due to signed/unsigned int),<br>
Only 7 "Dice Throws" could  be extracted from 1 rand() call.<br>
<br>
This method reduced the time taken to run to ~150ms, or 0.15s.<br>
<br>
This Version is labeled "main.c".<br>
<br>
## Overall
Moving to C was a MAJOR improvement to run speed (obviously).<br>
And Method #2 is x3 faster the Method #1,<br>
So in total (assuming base version took 5 min for 1000000, a.k.a , 3000s for 100000),
My fastest version is 200 times faster then base.
