#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 4096
#define MAX_ARG 10

typedef struct{
    char* command;
    char** argv;
    int argc;
}Command;

typedef struct{
    char* name;
    void (*fun)(Command*);

}Builtin;

void read_comand(char* buffer);
void parse_comand(char* buffer, Command* cmmd);
void built_in_exit(Command* cmmd);
int is_builtin(Command* cmmd, Builtin* bltin);

int main() {
    
    Builtin bltin[] = 
    {
        {"exit", built_in_exit},
        {NULL, NULL}
    };

    Command* cmmd = malloc(sizeof(Command));
    cmmd->command = NULL;
    cmmd->argv = malloc(sizeof(char*)*MAX_ARG);
    cmmd->argc = 0;
    char buffer [MAX_LINE];

    while (1){

        read_comand(buffer);
        parse_comand(buffer, cmmd);

        if(!is_builtin(cmmd, bltin)){
            printf("Not builtin\n");
        }
    }

}

void read_comand(char* buffer){
    
    char line [MAX_LINE];

    do{
        printf(">");
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

    }while(line[0] == '\0');
    

    strcpy(buffer, line);
}    

void parse_comand(char* buffer, Command* cmmd){

    char* token = strtok(buffer, " ");
    cmmd->command = token;
    token = strtok(NULL, " ");

    int i = 0;
    while(token != NULL){
        cmmd->argv[i] = token;
        token = strtok(NULL, " ");
        i++;
    }

    cmmd->argv[i] = NULL;
    cmmd->argc = i;
}

void built_in_exit(Command* cmmd){

    printf("Quiting...\n");

    exit(1);
}

int is_builtin(Command* cmmd, Builtin* bltin){

    int i = 0;

    while(bltin[i].name != NULL){
        if(strcmp(bltin[i].name, cmmd->command) == 0){
            bltin[i].fun(cmmd);
            return 0;
        }
        i++;
    }
    return -1;

    
}