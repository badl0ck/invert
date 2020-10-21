#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>
#include <string.h>
 
    // replace lines:
    // create a buffer with 256 lines (256 symbols for each line)
    // move cursor to the last line
    // read lines in current file from the end
    // put them into begin of file
 
char lineListBuffer[256][256];
 
int main()
{
    char* locale = setlocale(LC_ALL, "");
    FILE* filePointer = 0x0;
    uint32_t symbolCode = 0x0;
    char lineBuffer[256];
 
    if ((filePointer = fopen("testLine.txt", "a+")) == NULL)
    {
        perror("Couldn't open that file");
        exit(0);
    }
 
    int lineListCounter = 0;
    while (fgets(lineListBuffer[lineListCounter], 256, filePointer) != NULL)
    {
        lineListCounter++; // how many lines file contains
    }
 
    // printf("%s\n", lineListBuffer[5]); 
    // printf("%s\n", lineListBuffer[8]); 
    // printf("%s\n", lineListBuffer[65]);
    
    printf("Count of lines: %d\n", lineListCounter);
 
    memset(filePointer, 0, sizeof filePointer);
 
    if ((filePointer = fopen("testLine.txt", "w+")) == NULL)
    {
        perror("Something went wrong");
        exit(0);
    }
 
    lineListCounter--;
    while (lineListCounter >= 0)
    {
        fputs(lineListBuffer[lineListCounter], filePointer);
        lineListCounter--;
    }
    
    fclose(filePointer);
 
    return 0;
}