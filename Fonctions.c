#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Fonctions.h"

#define WELCOME_MSG "Bienvenue dans le Shell ENSEA\nPour quitter tapez 'exit'\nenseash % "
#define MAXSIZE 1024
#define ENSEA "\nenseash % "
#define EXIT_MSG "enseash % exit \nBye bye... \n$"

void Question1_Acceuil() {
    write(STDOUT_FILENO, WELCOME_MSG, strlen(WELCOME_MSG));
}
void Question2_Cmd() {
    char cmd[MAXSIZE] = {0};
    ssize_t nbChar;
    nbChar = read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar - 1] = '\0';
    pid_t pid;
    int status;
    pid = fork(); //to create a child

    if (pid == 0) { // for the child program
        execlp(cmd, cmd, NULL);//execlp replace process in progress by the command sent
        exit(EXIT_FAILURE);//the child program is shut down
    } else { // the father program continues here (thanks to the while loop in the main.c code)
        wait(&status);
        write(STDOUT_FILENO, ENSEA, strlen(ENSEA));
    }
}
void Question3_exit(){
        char cmd[MAXSIZE]={0};
        ssize_t nbChar;
        nbChar=read(STDIN_FILENO, cmd, MAXSIZE);
        cmd[nbChar-1]='\0';
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // program stop it if the message sent is "exit" or ""
        // strcmp compare two string element: if they are different the result is 1 AND if they are same the result is 0
        if(strcmp(cmd, "exit")==0||strcmp(cmd, "")==0){
            write(STDOUT_FILENO,EXIT_MSG, strlen(EXIT_MSG));
            exit(EXIT_SUCCESS);
        }
        // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
        pid_t pid;
        int status;
        pid=fork();

        if(pid==0){
            execlp(cmd,cmd,NULL);
            exit(EXIT_FAILURE);
        }
        else{
            wait(&status);
            write(STDOUT_FILENO,ENSEA, strlen(ENSEA));
        }
}
void Question4_return(){
    char cmd[MAXSIZE]={0};
    ssize_t nbChar;
    nbChar=read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar-1]='\0';
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // program stop it if the message sent is "exit" or ""
    // strcmp compare two string element: if they are different the result is 1 AND if they are same the result is 0
    if(strcmp(cmd, "exit")==0||strcmp(cmd, "")==0){
        write(STDOUT_FILENO,EXIT_MSG, strlen(EXIT_MSG));
        exit(EXIT_SUCCESS);
    }
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pid_t pid;
    int status;
    pid=fork();

    if(pid==0){
        execlp(cmd,cmd,NULL);
        exit(EXIT_FAILURE);
    }
    else{
        wait(&status);
        //write(STDOUT_FILENO,ENSEA, strlen(ENSEA));
        if(WIFEXITED(status)){
            sprintf(cmd,"%s[code exit : %d]\t" ,ENSEA, WEXITSTATUS(status));
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
        else if(WIFSIGNALED(status)){
            sprintf(cmd, "%s[signal exit : %d]\t",ENSEA, WTERMSIG(status));
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
    }
}
void Question5_temps(){
    char cmd[MAXSIZE]={0};
    ssize_t nbChar;
    struct timespec TimeStart, TimeStop;

    nbChar=read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar-1]='\0';
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // program stop it if the message sent is "exit" or ""
    // strcmp compare two string element: if they are different the result is 1 AND if they are same the result is 0
    if(strcmp(cmd, "exit")==0||strcmp(cmd, "")==0){
        write(STDOUT_FILENO,EXIT_MSG, strlen(EXIT_MSG));
        exit(EXIT_SUCCESS);
    }
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pid_t pid;
    int status;
    pid=fork();
    clock_gettime(CLOCK_REALTIME, &TimeStart);

    if(pid==0){
        execlp(cmd,cmd,NULL);
        exit(EXIT_FAILURE);
    }
    else{
        wait(&status);
        clock_gettime(CLOCK_REALTIME,&TimeStop);
        //write(STDOUT_FILENO,ENSEA, strlen(ENSEA));
        int time=(TimeStop.tv_sec-TimeStart.tv_sec)*1000+(TimeStop.tv_nsec-TimeStart.tv_nsec)/1000000; //time conversion in ms
        if(WIFEXITED(status)){
            sprintf(cmd,"%s[code exit : %d | %d ms]\t" ,ENSEA, WEXITSTATUS(status), time);
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
        else if(WIFSIGNALED(status)){
            sprintf(cmd, "%s[signal exit : %d | %d ms]\t",ENSEA, WTERMSIG(status), time);
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
    }
}
void Question6_complexe(){
    char cmd[MAXSIZE]={0};
    ssize_t nbChar;
    struct timespec TimeStart, TimeStop;

    nbChar=read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar-1]='\0';
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // program stop it if the message sent is "exit" or ""
    // strcmp compare two string element: if they are different the result is 1 AND if they are same the result is 0
    if(strcmp(cmd, "exit")==0||strcmp(cmd, "")==0){
        write(STDOUT_FILENO,EXIT_MSG, strlen(EXIT_MSG));
        exit(EXIT_SUCCESS);
    }
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pid_t pid;
    int status;
    pid=fork();
    clock_gettime(CLOCK_REALTIME, &TimeStart);

    char* elements[10];
    elements[0]=strtok(cmd," ");
    int i;
    for(i=1;i<10;i++){elements[i]=strtok(NULL," ");}

    if(pid==0){
        execvp(elements[0],elements);
        exit(EXIT_FAILURE);
    }
    else{
        wait(&status);
        clock_gettime(CLOCK_REALTIME,&TimeStop);
        //write(STDOUT_FILENO,ENSEA, strlen(ENSEA));
        int time=(TimeStop.tv_sec-TimeStart.tv_sec)*1000+(TimeStop.tv_nsec-TimeStart.tv_nsec)/1000000; //time conversion in ms
        if(WIFEXITED(status)){
            sprintf(cmd,"%s[code exit : %d | %d ms]\t" ,ENSEA, WEXITSTATUS(status), time);
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
        else if(WIFSIGNALED(status)){
            sprintf(cmd, "%s[signal exit : %d | %d ms]\t",ENSEA, WTERMSIG(status), time);
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
    }
}
void Question7_redirection(){
    char cmd[MAXSIZE]={0};
    ssize_t nbChar;
    struct timespec TimeStart, TimeStop;

    nbChar=read(STDIN_FILENO, cmd, MAXSIZE);
    cmd[nbChar-1]='\0';
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // program stop it if the message sent is "exit" or ""
    // strcmp compare two string element: if they are different the result is 1 AND if they are same the result is 0
    if(strcmp(cmd, "exit")==0||strcmp(cmd, "")==0){
        write(STDOUT_FILENO,EXIT_MSG, strlen(EXIT_MSG));
        exit(EXIT_SUCCESS);
    }
    // /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    pid_t pid;
    int status;
    pid=fork();
    clock_gettime(CLOCK_REALTIME, &TimeStart);

    char* elements[10];
    elements[0]=strtok(cmd," ");
    int i;
    for(i=1;i<10;i++){
        if(strcmp(elements[i-1], "<") == 0) {
            elements[i] = strtok(NULL, " \t\n"); // Get the next token (filename for input)
            int fd_in = open(elements[i], O_RDONLY);
            if (fd_in == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            //dup2(fd_in, STDIN_FILENO);
            close(fd_in);
        }else if(strcmp(elements[i-1], ">") == 0) {
            elements[i] = strtok(NULL, " \t\n"); // Get the next token (filename for output)
            int fd_out = open(elements[i], O_WRONLY | O_CREAT | O_TRUNC, 0666);
            if (fd_out == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd_out, STDOUT_FILENO);
            close(fd_out);
        }else{elements[i]=strtok(NULL," ");}
    }
    if(pid==0){
        execvp(elements[0],elements);
        exit(EXIT_FAILURE);
    }
    else{
        wait(&status);
        clock_gettime(CLOCK_REALTIME,&TimeStop);
        //write(STDOUT_FILENO,ENSEA, strlen(ENSEA));
        int time=(TimeStop.tv_sec-TimeStart.tv_sec)*1000+(TimeStop.tv_nsec-TimeStart.tv_nsec)/1000000; //time conversion in ms
        if(WIFEXITED(status)){
            sprintf(cmd,"%s[code exit : %d | %d ms]\t" ,ENSEA, WEXITSTATUS(status), time);
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
        else if(WIFSIGNALED(status)){
            sprintf(cmd, "%s[signal exit : %d | %d ms]\t",ENSEA, WTERMSIG(status), time);
            write(STDOUT_FILENO,cmd, strlen(cmd));
        }
    }
}
