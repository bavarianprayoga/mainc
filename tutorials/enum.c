#include <stdio.h>

typedef enum {Mon, Tue, Wed, Thu, Fri, Sat, Sun} Day;
//penamaan integer gitu

int main(){

    Day today = Mon;

    printf("Today is %d\n", today);

    return 0;
}