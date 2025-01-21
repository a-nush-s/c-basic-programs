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

int insertNode(struct Node** node, int num){
    struct Node* ptr = *node;
    struct Node* prev = NULL;
    int val = num;
    while (ptr!=NULL){
        if (val>ptr->data){
            prev = ptr;
            ptr = ptr->next;
            continue;
        } else if (val==ptr->data){
            return 0;
        } else {
            struct Node* newNode = createNode(val);
            newNode->next = ptr;
            if (prev!=NULL) {
                prev->next = newNode;
            } else {
                *node = newNode;
            }
            return 1;
        }
    }
    struct Node* newNode = createNode(val);
    prev->next = newNode;
    return 1;
}

int deleteNode(struct Node** node, int num){
    struct Node* ptr = *node;
    struct Node* prev = NULL;
    int val = num;
    while (ptr!=NULL){
        if (val>ptr->data){
            prev = ptr;
            ptr = ptr->next;
            continue;
        } else if (val<ptr->data){
            return 0;
        } else {
            struct Node* temp = ptr;
            ptr = ptr->next;
            if (prev!=NULL) {
                prev->next = ptr;
            } else {
                *node = ptr;
            }
            free(temp);
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv){
    FILE* inp = fopen(argv[1], "r");
    struct Node* head = NULL;
    char iod[20];
    int num;
    if (inp==NULL) {
        printf("error\n");
        return EXIT_SUCCESS;
    }
    int isEmpty = fscanf(inp, "%s %d", iod, &num);
    if (isEmpty==0) {
        printf("0\n");
        fclose(inp);
        return EXIT_SUCCESS;
    }

    int total = 0;

    do {
        if (iod[0] == 'i'){
            if (total==0) {
                head = createNode(num);
                total += 1;
            } else {
                total += insertNode(&head, num);
            }
        } else {
            if (total!=0){
                total -= deleteNode(&head, num);
            }
        }

        isEmpty = fscanf(inp, "%s %d", iod, &num);
    } while (isEmpty!=EOF);
    fclose(inp);

    printf("%d\n", total);
    if (total==0) return EXIT_SUCCESS;

    while (head!=NULL){
        if (head->next!=NULL){
            printf("%d\t", head->data);
        } else{
            printf("%d\n", head->data);
        }
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}