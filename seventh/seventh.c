#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv){
    for (int j = 1; j<argc; j++){
        int lastarg = -1;
        int k = 0;
        while(argv[j][k]!='\0'){
            lastarg++;
            k++;
        }
        printf("%c", argv[j][lastarg]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}