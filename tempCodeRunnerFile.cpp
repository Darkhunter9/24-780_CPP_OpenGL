# include <stdio.h>
# include <iostream>
# include <stdlib.h>
using namespace std;

int main(void)
{
    /* code */
    int a[] = {12, 34, 56, 78};
    printf("%d\n",a[0]);
    std::cout << a[1] << "\n" << sizeof(a)/sizeof(a[0]);
    return 0;
}
