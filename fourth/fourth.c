#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
    FILE* inp = fopen(argv[1], "r");
    int rowOne;
    int colOne;
    fscanf(inp, "%d \t %d \n", &rowOne, &colOne);
    int arrOne[rowOne][colOne];
    for (int i = 0; i<rowOne; i++){
        for (int j = 0; j<colOne; j++){
            int temp;
            if(j==colOne-1){
                fscanf(inp, "%d \n", &temp);
            } else{
                fscanf(inp, "%d \t", &temp);
            }
            arrOne[i][j] = temp;
        }
    }
    int rowTwo;
    int colTwo;
    fscanf(inp, "%d \t %d \n", &rowTwo, &colTwo);
    if ((rowTwo==colOne)){} else{
        printf("bad-matrices \n");
        return EXIT_SUCCESS;
    }
        

    int arrTwo[rowTwo][colTwo];
    for (int i = 0; i<rowTwo; i++){
        for (int j = 0; j<colTwo; j++){
            int temp;
            if(j==colTwo-1){
                fscanf(inp, "%d \n", &temp);
            } else{
                fscanf(inp, "%d \t", &temp);
            }
            arrTwo[i][j] = temp;
        }
    }

    for (int i = 0; i<rowOne; i++){
        for (int j = 0; j<colTwo; j++){
            int sum = 0;
            for (int k = 0; k<rowTwo; k++){
                sum += arrOne[i][k] * arrTwo[k][j];
            }
            if (j==colTwo-1){
                printf("%d", sum);
            } else {
                printf("%d\t", sum);
            }
        }
        if (!(i==rowOne-1)){
            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}