#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* createNode(int data, int height){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = height;
    return newNode;
}

int insert(int key, struct Node* head){
    struct Node* ptr = head;
    int height = 1;
    while (ptr!=NULL){
        height++;
        if (key<ptr->data){
            if (ptr->left==NULL){
                ptr->left = createNode(key, height);
                break;
            } else {
                ptr = ptr->left;
                continue;
            }
        } else if (key>ptr->data) {
            if (ptr->right==NULL){
                ptr->right = createNode(key, height);
                break;
            } else {
                ptr = ptr->right;
                continue;
            }
       } else {
        return 0;
       }
    }
    return height;
}

int search(int key, struct Node* head){
    struct Node* ptr = head;
    int height = 0;
    while (ptr!=NULL){
        height++;
        if (key<ptr->data){
            ptr = ptr->left;
        } else if (key>ptr->data){
            ptr = ptr->right;
        } else {
            return height;
        }
    }
    return 0;
}

void clear(struct Node* node){
    if (node == NULL){
        return;
    }
    clear(node->left);

    clear(node->right);

    free(node);
}

int main(int argc, char** argv){
    FILE* inp = fopen(argv[1], "r");
    if (inp==NULL) {
        printf("error");
        return EXIT_SUCCESS;
    }
    char ios; 
    int val;
    int isEmpty = fscanf(inp, "%c\t%d\n", &ios, &val);
    struct Node* head = NULL;
    while (isEmpty!=EOF){
        int height;
        if (ios == 'i'){
            if (head==NULL) {
                head = createNode(val, 1);
                printf("inserted 1\n");
            } else {
                height = insert(val, head);
                if (height == 0) {
                    printf("duplicate\n");
                } else {
                    printf("inserted %d\n", height);
                }
            }
        } else {
            height = search(val, head);
            if (height == 0){
                printf("absent\n");
            } else {
                printf("present %d\n", height);
            }
        }
        isEmpty = fscanf(inp, "%c\t%d\n", &ios, &val);
    }

    clear(head);
    fclose(inp);
    return EXIT_SUCCESS;
}