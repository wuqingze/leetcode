#include <stdio.h>
int i =0;

int f(){
    return i++;
}

int main(){
    printf("%d",f());
    printf("%d",f());
    printf("%d",f());
    printf("%d",f());
    return 0;
}
