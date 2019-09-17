/******************************************************************************
*                                                                             *
*                       PRINCIPLES OF EMBEDDED SOFTWARE                       *
*                           PROJECT 1 - PROGRAM 3                             *
*                         File Name: Proj_1_Prog_3                            *
*   Project By:GITANJALI SURESH (GISU9983) & RUCHA BORWANKAR (RUBO1268)       *
*                   Cross Platform IDE: Code::Blocks                          *
*                       Compiler: MinGW/GNU gcc v8.2.0                        *
*                                                                             *
*******************************************************************************/

/***************** Header files *******************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
/***************** Global variable declaration ******************/
int32_t dec = 51966;
int32_t hex_i;
char hex[16], last, bin[16], arr[4];
/***************** Function Declaration ******************/
void dec_hex(int32_t dec);
void hex_bin(char b);
void check(char bin[]);
void reverse(char hex[]);
void rotate_left4(char arr[]);
void rotate_right8(char arr[]);
/***************** Main function *******************/
int main()
{
    printf("\n The given integer input is 51966.\n");       /* Input integer is 51966 */
    dec_hex(dec);                                           /* Decimal to hex conversion [1] */
    printf(" The last nibble value is %c.",last);           /* the last nibble is stored in the variable last */
    hex_bin(last);                                          /* convert from hex to binary [2] */
    check(bin);                                             /* condition to check if 3 or 4 bits are on */
    reverse(hex);                                           /* reversing byte order [3] */
    printf("\n The last nibble value is %c.",last);
    hex_bin(last);
    check(bin);
    rotate_left4(arr);                                      /* rotate left by 4 bits  [4] */
    printf("\n The last nibble value is %c.",last);
    hex_bin(last);
    check(bin);
    rotate_right8(arr);                                     /* rotate right by 8 bits [4] */
    printf("\n The last nibble value is %c.",last);
    hex_bin(last);
    check(bin);
}

/******************* Function for decimal to hexadecimal conversion [1] ******************/
void dec_hex(int32_t dec)
{
    int32_t i, rem, temp = dec;
    hex_i = 0;
    while (temp != 0)
    {
        rem = 0;
        rem = temp % 16;
        if (rem<10)
        {
            hex[hex_i] = rem + 48;
            hex_i++;
        }
        else
        {
            hex[hex_i] = rem + 55;
            hex_i++;
        }
        temp /= 16;
    }
    last = hex[0];
    printf(" The hexadecimal value is ");
    for(i = hex_i-1;i >= 0;i--)
    {
      printf("%c",hex[i]);

    }
    printf(".");
    printf("\n");
}
/******************* Hexadecimal to Binary Conversion [2] *******************/
void hex_bin(char last)
{
    switch(last)
    {
            case '0': strcpy(bin, "0000");
                      break;
            case '1': strcpy(bin, "0001");
                      break;
            case '2': strcpy(bin, "0010");
                      break;
            case '3': strcpy(bin, "0011");
                      break;
            case '4': strcpy(bin, "0100");
                      break;
            case '5': strcpy(bin, "0101");
                      break;
            case '6': strcpy(bin, "0110");
                      break;
            case '7': strcpy(bin, "0111");
                      break;
            case '8': strcpy(bin, "1000");
                      break;
            case '9': strcpy(bin, "1001");
                      break;
            case 'a':
            case 'A': strcpy(bin, "1010");
                      break;
            case 'b':
            case 'B': strcpy(bin, "1011");
                      break;
            case 'c':
            case 'C': strcpy(bin, "1100");
                      break;
            case 'd':
            case 'D': strcpy(bin, "1101");
                      break;
            case 'e':
            case 'E': strcpy(bin, "1110");
                      break;
            case 'f':
            case 'F': strcpy(bin, "1111");
                      break;
            default: printf(" Invalid hexadecimal input.");
    }
    printf("\n Binary representation = %s\n", bin);
}
/******************* Check: If 3 of 4 last bits are ON *******************/
void check(char bin[])
{
    int32_t i = 0, counter = 0;
    for(i=0;i<3;i++)
    {
        if(bin[i] == '1')
            counter++;
    }
    if(counter == 3)
        printf("\n 3 bits are ON in the last 4 bits: TRUE\n");
    else
        printf("\n 3 bits are ON in the last 4 bits: FALSE\n");

}
/******************* Reversing byte order [3] *******************/
void reverse(char hex[])
{
    int32_t i, j, n;
    n = strlen(hex);
    for (i=0, j=0;i<=n/2;i+=2,j+=2)
    {
        arr[i] = hex[j+1];
        arr[i+1] = hex[j];
    }
    printf("\n The reversed byte is %s.",arr);
    last = arr[n-1];
}
/******************* Rotate Left by 4 bits [4] *******************/
void rotate_left4(char arr[])
{
    int32_t i;
    char temp;
    temp = arr[0];
    for(i=0;i<4;i++)
    {
        arr[i] = arr[i+1];
    }
    arr[i-1] = temp;
    printf("\n The rotated value by 4 bits to the left is %s.",arr);
    last = arr[3];
}
/******************* Rotate right by 8 bits [4] *******************/
void rotate_right8(char arr[])
{
    int32_t i;
    char temp;
    for(i=0;i<2;i++)
    {
        temp = arr[i+2];
        arr[i+2] = arr[i];
        arr[i] = temp;
    }
    printf("\n The rotated value by 8 bits to the right is %s.",arr); /* [4] */
    last = arr[3];
}

/********************************************** References **************************************************

[1] http://scanftree.com/programs/c/c-code-to-convert-decimal-to-hexadecimal/
[2] https://codeforwin.org/2015/08/c-program-to-convert-hexadecimal-to-binary-number-system.html
[3] https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
[4] https://codeforwin.org/2017/03/c-program-to-left-rotate-array.html

*************************************************************************************************************/
