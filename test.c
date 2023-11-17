#include <stdio.h>
#include <string.h>

char *gets(char *);

void other(){
    printf("Done\n");
}
int hello(){
    char buff[4];
    gets(buff);

    return 2;
}
int main(){

    int a = 10;
    int b = hello();
    char* h = "helx";

    int c = b+a;
    
    return 0;
}


/**
 rip = 0x555555555155 in hello (test.c:8); 
    saved rip = 0x555555555185
 called by frame at 0x7fffffffdcc0
 Saved registers:

rip at 0x7fffffffdc88
rbp at 0x7fffffffdc80,  Locals at 0x7fffffffdc80,



*/