#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

char* search(int key, struct Node* buc[]){
    int hash = key%100;
    if (hash<0) hash = hash*-1;

    if (buc[hash]==NULL) return "absent";
    struct Node* ptr = buc[hash];
    while(ptr!=NULL){
        if (ptr->data==key) return "present";
        ptr = ptr->next;
    }
    return "absent";
}

int hash(int key, struct Node* buc[]){
    int hash = key%100;
    if (hash<0) hash = hash*-1;

    if (buc[hash]==NULL){
        buc[hash] = createNode(key);
        return 0;
    }

    char* isHere = search(key, buc);
    if (isHere[0]=='a'){
        struct Node* newNode = createNode(key);
        newNode->next = buc[hash];
        buc[hash] = newNode;
        return 0;
    } else {
        return 1;
    }
}

void release(struct Node* buc[]){
    for (int i = 0; i<100; i++){
        struct Node* ptr = buc[i];
        struct Node* temp;
        while (ptr!=NULL){
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
}

int main(int argc, char** argv){
    FILE* ptr = fopen(argv[1], "r");
    struct Node* buc[100];
    for (int i = 0; i<100; i++){
        buc[i] = NULL;
    }

    int dims;
    fscanf(ptr, "%d\n", &dims);
    int elk[dims][dims];

    int curr;
    for (int i = 0; i<dims; i++){
        for (int j = 0; j<dims; j++){
            if (j==dims-1){
                fscanf(ptr, "%d\n", &curr);
            } else {
                fscanf(ptr, "%d\t", &curr);
            }
            elk[i][j] = curr;
            if(hash(curr, buc)==1){
                printf("not-magic\n");
                release(buc);
                fclose(ptr);
                return EXIT_SUCCESS;
            }
        }
    }

    release(buc);
    fclose(ptr);

    int length = dims*2+2;
    int sums[length];
    int sum1 = 0;
    int sum2 = 0;
    int k = 0;
    for (int i = 0; i<dims; i++){
        for (int j = 0; j<dims; j++){
            sum1 += elk[i][j];
            sum2 += elk[j][i];
        }
    sums[k] = sum1;
    sums[k+1] = sum2;
    sum1 = 0;
    sum2 = 0;
    k+=2;
    }

    for (int i = 0; i<dims; i++){
        sum1 += elk[i][i];
        sum2 += elk[i][dims-i-1];
    }
    sums[length-1] = sum1;
    sums[length-2] = sum2;

    for (int i = 1; i<length; i++){
        if (sums[i]!=sums[i-1]){
            printf("not-magic\n");
            return EXIT_SUCCESS;
        }
    }
    printf("magic\n");
    return EXIT_SUCCESS;
}