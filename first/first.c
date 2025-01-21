#include <stdio.h>
#include <stdlib.h>

int truncprime(int a){
    while (a>1){
        if (a==2) return 1; 
        for (int i = 2; i < a; i++){
            if (a%i==0){
                return 0;
            }
        }
            a = a/10;
            if (a==0){
                return 1;
            }
    } 
    return 0;
}


int main(int argc, char** argv){
    FILE* ptr = fopen(argv[1], "r");
    int n;
    fscanf(ptr, "%d", &n);
    int val;
    //int* tof = malloc(sizeof(int)*n);
    
    for (int i = 0; i < n; i++){
        fscanf(ptr, "%d", &val);
        if (truncprime(val)==1){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    fclose(ptr);

    //free(tof);
    return EXIT_SUCCESS;
}