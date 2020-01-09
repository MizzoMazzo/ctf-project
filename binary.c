//
// Created by krypton on 09.01.20.
//

#include "binary.h"
#include<stdio.h>
void print_secret(){
    int i;
    FILE *fp;
    fp = fopen("flag.txt", "r");
    printf("Oh you found my Flag!!!\n");
    if (fp) {
        while ((i = getc(fp)) != EOF)
            putchar(i);
        fclose(fp);
    }
}











int main() {
    printf("Hello World\n");
    print_secret();
    return 0;
}