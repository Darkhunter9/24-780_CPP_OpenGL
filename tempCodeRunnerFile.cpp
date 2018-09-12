#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>

int main(void)
{
    char str[256];
    strcpy(str,"ABCDEFG");
    str[5]=0;
    printf("%s\n",str);
    system("pause");
    return 0;
}