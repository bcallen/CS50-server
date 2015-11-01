#include <stdlib.h>
#include <stdio.h>
//#include <cs50.h>
#include <string.h>
#include <strings.h>

char* scan(char *word, char delim, char* line, int instance);

//Tests the use and implementation of strchr, strcpy, and strstr functions

int main(void)
{
    char* line = "I'm a dinosaur!";
    printf("%s\n", line);

    int len = strlen(line);
    char *res = NULL;
    res = (char*)malloc((len + 1) * sizeof(char));

    printf("%s\n", scan(res, ' ',line,1));
    printf("%s\n", scan(res, ' ',line,2));
    printf("%s\n", scan(res, ' ',line,3));
    printf("%s\n", scan(res, ' ',line,4));

    //break the line into its parts
    //char* SP1 = strchr(line, ' ');
    //char* SP2 = strchr(SP1+1, ' ');
    //printf("%d\n", SP1-line);    
//
//    //printf("%s\n", SP2);
//    //int index1 = SP1-line;
//    //char *method;
//    //method = (char*)malloc((index1+1) * sizeof(char));
//
//    //memcpy(method, line, index1);
//    //method[index1] = '\0';
//    //printf("length: %d", strlen(method));
//
//    //strncpy(method, line, index1);
//    //
//    //printf("method: %s\n", method);
    //printf("length: %d\n", strlen(method));
    free(res);
}


char* scan(char *word, char delim, char* line, int instance)
{
    char *first = NULL; char *last = NULL;
    int i; int len;

    len = strlen(line);
    first = line;
    last = line;

    for (i=1; i<=instance; i++) {
        last = strchr(last, delim);
        if (i == instance) {
            if (last == NULL) last = line + len;
            memcpy(word, first, last - first);
            word[last - first] = '\0';
            return word;
        } else if (last == NULL || instance < 1){
            memcpy(word, line, len);
            word[len] = '\0';
            return word;
        } else {
            last++;
            first = last;
        }
    }
}