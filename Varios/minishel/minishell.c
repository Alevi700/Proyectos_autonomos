#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 4096
#define MAX_ARG 10
#define MAX_ARG_LEN 128

typedef struct{
    char command[MAX_ARG_LEN];
    char args[MAX_ARG][MAX_ARG_LEN];
}Command;

void read_comand(char* buffer);
void parse_comand(char* buffer, Command* cmmd);



int main(int argc, char *argv[]) {
    
    Command* cmmd = malloc(sizeof(Command)) ;
    char buffer [MAX_LINE];

    while (1){

        read_comand(buffer);
        parse_comand(buffer, cmmd);        
    }

}

void read_comand(char* buffer){
    
    char line [MAX_LINE];

    do{
        printf(">");
        fgets(line, sizeof(line), stdin);
        if(strcmp(line,"\n") == 0) line[0] = '\0';

    }while(line[0] == '\0');
    

    strcpy(buffer, line);
}    

void parse_comand(char* buffer, Command* cmmd){

    char* token = strtok(buffer, " ");
    strcpy(cmmd->command, token);
    token = strtok(NULL, " ");

    int i = 0;
    while(token != NULL){
        strcpy(cmmd->args[i], token);
        token = strtok(NULL, " ");
        i++;
    }

    for(int j = 0; j<i; j++){
        printf("%s", cmmd->args[j]);
    }
}