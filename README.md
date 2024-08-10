# graveler.c

Basically:
Python = No No
C = Yes Yes

# Method #1
Replaced list shenanigans with [rand() % 4], simple as.\n
100000 Sessions takes ~450ms to run, or 0.45s.

# Method #2
Inspired by @kgaughan method of getting 2 random bits (4 possible outcomes/random of 4),
The rand() generates a random 16 bit integer, or in other words, 8 pairs of 2 bits.
Due to a limitation where the last bit of the number is always 0 (due to signed/unsigned int),
Only 7 "Dice Throws" could  be extracted from 1 rand() call.

This method reduced the time taken to run 100000 Sessions,
to ~150ms, or 0.15s.
