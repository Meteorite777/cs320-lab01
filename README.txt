CS320 - Computer Architecture
Author: Nicholas Frank
09/13/2026

This purpose of this lab is to get you comfortable using the Linux terminal,
compiling software, git, the C language.

-----------------
hangman-broken.c is a simple implementation of the game 'hangman' where
you must guess the letters contained in a hidden word before your lives
run out.

I've added 4 errors in the code for you to hopefully debug.

1) Variable / Compiler error
2) Output error in drawHangman()
3) Logical error in drawHangman()
4) wordBank issue

OBJECTIVE: How would we go about extending this game to add functionality?
Can you think of a way to handle upper and lower case letters?

Use the tolowercase() function provided to sanitize the input provided by
scanf()

OBJECTIVE: Implement a method to give the user a hint / freebie letter if
they enter '?' instead of a character without taking away a life.

----------------
player-struct.c is just a piece of example code I've included for you to
mess around with pointers and structs, as well as accessing or modifying
the values contained within them.

TO COMPILE:
gcc <code-file>.c -o <executable-name>  
