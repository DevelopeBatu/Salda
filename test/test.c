#include <stdio.h>

#define VAR(name, init) typeof(init) name = init
int main(){
    VAR(x,"12+22");
    printf("%d",x);
}