//
// Created by Anders Schnack, 21-09-2021
//

#include "HelpCommand.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>  // added line

int main() {        // added line

    Help();



    return 0;       // added line
}                   // added line

void Help() {
    printf("\nThis is the help function. Here is a list of possible commands: ");
    printf("\n");
    printf("\nHelp()                     -  lists commands with basic desriptions");
    printf("\nCreatePipes(int numPipes)  -  creates specified number of pipes and returns them in an array");
}

