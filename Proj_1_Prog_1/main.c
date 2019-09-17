/******************************************************************************
*                                                                             *
*                       PRINCIPLES OF EMBEDDED SOFTWARE                       *
*                           PROJECT 1 - PROGRAM 1                             *
*                         File Name: Proj_1_Prog_1                            *
*   Project By:GITANJALI SURESH (GISU9983) & RUCHA BORWANKAR (RUBO1268)       *
*                   Cross Platform IDE: Code::Blocks                          *
*                       Compiler: MinGW/GNU gcc v8.2.0                        *
*                                                                             *
*******************************************************************************/

/************* Header File Declarations *************/
#include <stdio.h>
#include <stdlib.h>     /* for abs() */
#include <string.h>     /* for strcpy() */
#include <math.h>       /* for pow() */
#include <stdint.h>
/************* Global Variable Declarations *************/
int32_t dec, bin[20], oct, op, hex_i, bin_i, max_dec;
int32_t inum;
int32_t o_bin[20], t_bin[20], s_mag[20];
char hex[20];
/************* Function Prototype Declarations *************/
void dec_oct(int32_t dec);
void dec_bin(int32_t dec);
void dec_hex(int32_t dec);
void oct_dec(int32_t oct);
void hex_dec(char hex[]);
void ones_c(int32_t bin[]);
void twos_c(int32_t o_bin[]);
void sign_mag(int32_t bin[]);
/************* Main Function *************/
int main()
{
    int32_t rad;
    char cnum[10];
    /********** Inputs **********/
    for(int32_t i = 0; i<10; i++)
    {
        scanf("%c",&cnum[i]);
        if(cnum[i] == ',')
        {
            cnum[i] = '\0';
            break;
        }
    }
    scanf("%d,%d", &rad, &op);
    printf ("\nInput: \t\t\t\t Value=%s \t\t Radix=%d \t\t Operand=%d \n", cnum, rad, op);
    if(op == 4 || op == 8 || op == 16)      /* Limiting the operand sizes to 4,8 and 16 */
    {
        if (rad == 8 || rad == 10)
            inum = atoi(cnum);              /* Converting string into integer for decimal and octal values [1] */
        if (rad == 10)
        {
            if((abs(inum)) >= (pow(2,op)))  /* Checking if given decimal input is within the given bit size [2] */
            {
                printf("\nWrong input value for the given operand size.\n");
                exit(0);
            }
        }
        switch (rad)                    /* Performing the various conversions based on the input radix */
        {
            case 8: oct = abs(inum);
                    oct_dec(oct);
                    dec_bin(dec);
                    dec_hex(dec);
                    break;
            case 10: dec = abs(inum);
                     dec_bin(dec);
                     dec_oct(dec);
                     dec_hex(dec);
                     break;
            case 16: strcpy(hex,cnum);
                     hex_dec(hex);
                     dec_bin(dec);
                     dec_oct(dec);
                     break;
            default: printf("\nWrong radix input!!\n");
                     exit(0);
                     break;
        }
        /********************************************** Outputs **********************************************/
        printf("\n----------------------------------------------------------------------------------------------------");
        printf("\nOutput: \t\t\t Value \t\t\t Maximum \t\t Minimum");
        printf("\n----------------------------------------------------------------------------------------------------");
        printf("\nBinary(abs) \t\t\t 0b");          /* Printing Binary Values */
        for(bin_i=op-1;bin_i>=0;bin_i--)
        {
            printf("%d",bin[bin_i]);                /* Absolute Binary Value */
        }
        if(op == 16)
            printf(" \t 0b");
        else if(op == 4 || op == 8)
            printf(" \t\t 0b");
        for(bin_i=0;bin_i<op;bin_i++)
        {
            printf("%d",1);                         /* Maximum Binary Value */
        }
        if(op == 16)
            printf(" \t 0b");
        else if(op == 4 || op == 8)
            printf(" \t\t 0b");
        for(bin_i=0;bin_i<op;bin_i++)
        {
            printf("%d",0);                         /* Minimum Binary Value */
        }
        printf("\nOctal(abs) \t\t\t 0%d",oct);        /* Printing Absolute Octal Value */
        max_dec = pow(2,op)-1;                        /* [2] */
        dec_oct(max_dec);                             /* Finding maximum value in octal */
        if(op == 16)
            printf(" \t\t 0%d \t\t 0",oct);               /* Maximum and Minimum Octal Values */
        else if(op == 4 || op == 8)
            printf(" \t\t\t 0%d \t\t\t 0",oct);               /* Maximum and Minimum Octal Values */
        printf("\nDecimal(abs) \t\t\t %d \t\t\t %d \t\t\t 0",dec,max_dec);      /* Printing Decimal Values */
        printf("\nHexdecimal(abs) \t\t 0x");           /* Printing Hexadecimal Values */
        if(rad == 16)
        {
            for(int32_t i=2;hex[i]!='\0';i++)
                printf("%c",hex[i]);                    /* Absolute Hexadecimal Value */
        }
        for(hex_i=hex_i-1;hex_i>=0;hex_i--)
        {
            printf("%c",hex[hex_i]);                    /* Absolute Hexadecimal Value */
        }
        dec_hex(max_dec);                               /* Finding maximum value in hexadecimal */
        if(op == 16)
            printf(" \t\t 0x");
        else if(op == 4 || op == 8)
            printf(" \t\t\t 0x");
        for(hex_i=hex_i-1;hex_i>=0;hex_i--)
        {
            printf("%c",hex[hex_i]);                    /* Maximum Hexadecimal Value */
        }
        if(op == 16)
            printf(" \t\t 0x0");                            /* Minimum Hexadecimal Value */
        else if(op == 4 || op == 8)
            printf(" \t\t\t 0x0");                            /* Minimum Hexadecimal Value */
        if(rad == 10 && (inum != dec))          /* Performing sign functions only for negative decimal values */
        {
                ones_c(bin);
                twos_c(o_bin);
                sign_mag(bin);
        }
        else
        {
            for(int32_t i = 0;i < op;i++)
            {
                o_bin[i] = bin[i];
                t_bin[i] = bin[i];
                s_mag[i] = bin[i];
            }
        }
        printf("\nSigned One's Complement");                            /* Printing Signed One's Complement Values */
        if((inum <= (-(pow(2,(op-1))))) || (dec >= pow(2,op-1)))     /* Printing 'Error' if one's complement cannot be computed */
        {
            printf(" \t Error \t\t\t Error \t\t\t Error");
        }
        else
        {
            printf(" \t 0b");
            for(int32_t i = op-1;i>=0;i--)
            {
                printf("%d",o_bin[i]);              /* Signed One's Complement */
            }
            if(op == 16)
                printf(" \t 0b0");
            else if(op == 4 || op == 8)
                printf(" \t\t 0b0");
            for(int32_t i = op-2;i>=0;i--)
            {
                printf("%d",1);                     /* Maximum Value */
            }
            if(op == 16)
                printf(" \t 0b1");
            else if(op == 4 || op == 8)
                printf(" \t\t 0b1");
            for(int32_t i = op-2;i>=0;i--)
            {
                printf("%d",0);                     /* Minimum Value */
            }
        }
        printf("\nSigned Two's Complement");                        /* Printing Signed Two's Complement Values */
        if((inum < (-(pow(2,(op-1))))) || (dec >= pow(2,op-1)))  /* Printing 'Error' if two's complement cannot be computed */
        {
            printf(" \t Error \t\t\t Error \t\t\t Error");
        }
        else
        {
            printf(" \t 0b");
            for(int32_t i = op-1;i>=0;i--)
            {
                printf("%d",t_bin[i]);              /* Signed Two's Complement */
            }
            if(op == 16)
                printf(" \t 0b0");
            else if(op == 4 || op == 8)
                printf(" \t\t 0b0");
            for(int32_t i = op-2;i>=0;i--)
            {
                printf("%d",1);                     /* Maximum Value */
            }
            if(op == 16)
                printf(" \t 0b1");
            else if(op == 4 || op == 8)
                printf(" \t\t 0b1");
            for(int32_t i = op-2;i>=0;i--)
            {
                printf("%d",0);                     /* Minimum Value */
            }
        }
        printf("\nSign-Magnitude");                                      /* Printing Sign-Magnitude Values */
        if((inum <= (-(pow(2,(op-1))))) || (dec >= pow(2,op-1)))      /* Printing 'Error' if sign-magnitude cannot be computed */
        {
            printf(" \t\t\t Error \t\t\t Error \t\t\t Error");
        }
        else
        {
            printf(" \t\t\t 0b");
            for(int32_t i = op-1;i>=0;i--)
            {
                printf("%d",s_mag[i]);              /* Sign-magnitude */
            }
            if(op == 16)
                printf(" \t 0b0");
            else if(op == 4 || op == 8)
                printf(" \t\t 0b0");
            for(int32_t i = op-2;i>=0;i--)
            {
                printf("%d",1);                     /* Maximum Value */
            }
            if(op == 16)
                printf(" \t 0b1");
            else if(op == 4 || op == 8)
                printf(" \t\t 0b1");
            for(int32_t i = op-2;i>=0;i--)
            {
                printf("%d",1);                     /* Minimum Value */
            }
        }
        printf("\n----------------------------------------------------------------------------------------------------");
        printf("\n");
    }
    else
    {
        printf("\nWrong operand value!\n");
    }
    return 0;
}
/*********** Decimal to Octal Conversion [3] ***********/
void dec_oct(int32_t dec)
{
    int32_t i = 1, temp = dec;
    oct = 0;
    while (temp != 0)
    {
        oct += (temp % 8)*i;
        temp /= 8;
        i *= 10;
    }
}
/*********** Decimal to Binary Conversion [4] ***********/
void dec_bin(int32_t dec)
{
    int32_t temp = dec;
    bin_i = 0;
    while (temp != 0)
    {
        bin[bin_i] = temp % 2;
        temp /= 2;
        bin_i++;
    }
    if (bin_i > op)
    {
        printf("\nBinary representation exceeding the operand size...Error!");
        exit(0);
    }
}
/*********** Decimal to Hexadecimal Conversion [5] ***********/
void dec_hex(int32_t dec)
{
    int32_t rem, temp = dec;
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
}
/*********** Octal to Decimal Conversion [6] ***********/
void oct_dec(int32_t oct)
{
    int32_t i = 0, temp = oct;
    dec = 0;
    while (temp != 0)
    {
        dec += ((temp%10) * pow(8,i));
        i++;
        temp /= 10;
    }
    if(dec >= (pow(2,op)))
    {
        printf("\nWrong input value for the given operand size.\n");
        exit(0);
    }
}
/*********** Hexadecimal to Decimal Conversion [7] ***********/
void hex_dec(char hex[])
{
    int32_t len = strlen(hex);
    int32_t temp = 1;
    dec = 0;
    for (hex_i = len-1; hex_i>=0; hex_i--)
    {
        if(hex[hex_i] >= '0' && hex[hex_i] <= '9')
        {
            dec += (hex[hex_i] - 48) * temp;
            temp *= 16;
        }
        else if(hex[hex_i] >= 'A' && hex[hex_i] <= 'F')
        {
            dec += (hex[hex_i] - 55) * temp;
            temp *= 16;
        }
    }
    if(dec >= (pow(2,op)))
    {
        printf("\nWrong input value for the given operand size.\n");
        exit(0);
    }
}
/*********** Signed One's Complement [8] ***********/
void ones_c(int32_t bin[])
{

    for(int32_t i = 0;i < op;i++)
    {
        if(bin[i] == 1)
            o_bin[i] = 0;
        else
            o_bin[i] = 1;
    }
}
/*********** Signed Two's Complement [9] ***********/
void twos_c(int32_t o_bin[])
{
    int32_t c = 1;
    for(int32_t i = 0;i < op;i++)
    {
        if(o_bin[i] == 1 && c == 1)
            t_bin[i] = 0;
        else if(o_bin[i] == 0 && c == 1)
        {
            t_bin[i] = 1;
            c = 0;
        }
        else
            t_bin[i] = o_bin[i];
    }
}
/*********** Sign-Magnitude Complement ***********/
void sign_mag(int32_t bin[])
{
    s_mag[--bin_i] = 1;
    for(bin_i = op-2; bin_i >=0; bin_i--)
        s_mag[bin_i] = bin[bin_i];
}

/************************************************** References ********************************************************
[1] https://www.geeksforgeeks.org/converting-strings-numbers-cc/
[2] https://medium.com/@nickteixeira/how-to-explain-to-my-wife-what-i-do-how-do-you-get-the-maximum-and-minimum-values-
    for-integer-befdc263a3a2
[3] https://www.geeksforgeeks.org/program-decimal-octal-conversion/
[4] https://www.geeksforgeeks.org/program-decimal-binary-conversion/
[5] https://www.geeksforgeeks.org/program-decimal-hexadecimal-conversion/
[6] https://www.programiz.com/c-programming/examples/octal-decimal-convert
[7] https://www.geeksforgeeks.org/program-hexadecimal-decimal/
[8] https://stackoverflow.com/questions/35278819/sign-magnitude-ones-complement-twos-complement/41097343
[9] https://codeforwin.org/2015/08/c-program-to-find-twos-complement-of-binary-number.html
************************************************************************************************************************/
