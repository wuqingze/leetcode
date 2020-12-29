#include <stdio.h>
#include <stdlib.h>

int main(){
    char a = 0xff;
    char b = -1;
    int c = 1;
    printf("%c\n", a);
    printf("%d\n", b==-1);
    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(c));
    return 0;
}
