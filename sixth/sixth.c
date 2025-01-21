#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
    char** this = argv; 
    int voc;
    for (int j = 1; j<argc; j++){
        int arglength = 0;
        int k = 0;
        while(argv[j][k]!='\0'){
            arglength++;
            k++;
        }
        int i = 0;
        char* cons = malloc(sizeof(char));
        int length = 1;
        if (this[j][i]=='\0') continue;
        if (this[j][i]=='a'||this[j][i]=='e'||this[j][i]=='i'||this[j][i]=='o'||this[j][i]=='u'||this[j][i]=='A'||this[j][i]=='E'||this[j][i]=='I'||this[j][i]=='O'||this[j][i]=='U'){
            voc = 1;
        } else {
            voc = 0;
            while (!(this[j][i]=='a'||this[j][i]=='e'||this[j][i]=='i'||this[j][i]=='o'||this[j][i]=='u'||this[j][i]=='\0'||this[j][i]=='A'||this[j][i]=='E'||this[j][i]=='I'||this[j][i]=='O'||this[j][i]=='U')){
                cons[length-1] = this[j][i];
                cons = realloc(cons, sizeof(char)*(length+1));
                length++;
                i++;
            }
            cons[length-1] = '\0';
        }
        while (i<arglength){
            printf("%c", this[j][i]);
            i++;
        }
        if (voc==1){
            printf("yay ");
        } else {
            printf("%say ", cons);
        } 
        free(cons);
        } 
    printf("\n");
    return EXIT_SUCCESS;
}