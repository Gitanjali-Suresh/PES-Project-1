/******************************************************************************
*                                                                             *
*                       PRINCIPLES OF EMBEDDED SOFTWARE                       *
*                           PROJECT 1 - PROGRAM 2                             *
*                         File Name: Proj_1_Prog_2                            *
*   Project By:GITANJALI SURESH (GISU9983) & RUCHA BORWANKAR (RUBO1268)       *
*                   Cross Platform IDE: Code::Blocks                          *
*                       Compiler: MinGW/GNU gcc v8.2.0                        *
*                                                                             *
*******************************************************************************/

/***************** Header files *******************/
#include <stdio.h>
#include <ctype.h>                      /* [3] */
#include <stdint.h>
/***************** Main function *******************/
int main()
{
    uint32_t code;
    for (uint32_t i = 0; i < 20; i++)
    {
        scanf("%u",&code);
        printf("\n The entered ASCII code: %u",code);
        printf("\n Code: %u",code);
        printf("\t ASCII Char: %c",code);
        if(isupper(code))                            /*[1] [2]*/
        {
            printf("\t\tType: Upper Case\n");
        }
        else if(isspace(code) || iscntrl(code))      /*[1] [2]*/
        {
            printf("\t\tType: White Space\n");
        }
        else if(ispunct(code))                       /*[1] [2]*/
        {
            printf("\t\tType: Special character \n");
        }
        else if(islower(code))                       /*[1] [2]*/
        {
            printf("\t\tType: Lower Case\n");
        }
        else if(isdigit(code))                       /*[1] [2]*/
        {
            printf("\t\tType: Digit\n");
        }
    }
}

/********************************* References **********************************

[1] https://data-flair.training/blogs/header-files-in-c-cpp/
[2] https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
[3] https://www.includehelp.com/c-library-functions/ctype-example-programs.aspx

********************************************************************************/
