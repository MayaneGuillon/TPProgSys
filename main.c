#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define WELCOME_MSG "Bienvenue dans le Shell ENSEA\nPour quitter tapez 'exit'\nenseash % "
int main() {
    write(STDOUT_FILENO,WELCOME_MSG,strlen(WELCOME_MSG));
    return 0;
}
