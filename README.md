# PES-Project-1

PROJECT BY:Gitanjali Suresh and Rucha Borwankar

PROGRAM 1

The code takes in input from the user of the number,radix and operand.
The radix is a number that represents the type of input i.e decimal,octal or hexadecimal.
The operand determines size of the output. 
Depending on the type of the number that is obtained from the user the input is then converted to equivalent 
binary,decimal and octal values mentioning the maximum and minimum values.

PROGRAM 2
The code is based on determination of an ASCII character from its character code.
The ASCII characters range from 0 to 127.
The code initiates with a user input of the character number.
For this code to execute,we use a header file i.e ctype.h in standard C library that have a series of functions 
that checks whether the character from the user is white space,numeric,special character,lower case,upper case 
or punctuation.

PROGRAM 3

This code initiates with a pre determined integer input of 51966.
This integer is then converted to hexadecimal number i.e CAFE.
The last nibble of this code is then checked for a condition i.e if 3 or the 4 bits contain 1 then the binary value 
of the last nibble is printed.
After this,the updated hexadecimal value is reversed with byte order and again checked for the above condition and prints the binary value of the last bit.
We then rotate the value by 4 bits to the left and we print the hexadecimal value.
Again,we use the last nibble of updated hexadecimal value to check the test condition and accordingly the last 4 bits are printed.
We then rotate the updated hexadecimal value by 8 bits to the right and then we check for the condition and print last 4 bits in binary accordingly.


The above programs are written on CODEBLOCKS IDE and executed on GCC compiler.
