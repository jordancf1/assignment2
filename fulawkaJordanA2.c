#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/fulawkaJordanA2.h"

char * readFile (char * filename){
/*This functions takes a file, reads it in its entirety and returns its content as a string*/
    int numLines;
    numLines = 0;

    FILE * fPtr;
    fPtr = NULL;
    fPtr = fopen(filename, "r");

    /*string variable is used to store the entire file and is what is returned to the user*/
    char *string;
    string = malloc(sizeof(char) * (MAX_LENGTH * MAX_WORDS));

    /*tempString variable is used to store each line and then concatenates each line to the string variable*/
    char *tempString;
    tempString = malloc(sizeof(char) * (MAX_LENGTH * MAX_WORDS));

    while(!feof(fPtr))
    {
    /*If reading the first line, it is simply retrieved using fgets*/
    if(numLines == 0)
    {
    fgets(string, MAX_LENGTH * MAX_WORDS, fPtr);
    }

    else
    {
    /*If it is not the first line, then the string variable is realloced to be able to hold more than one line*/
        string = (char*)realloc(string, sizeof(char) * (MAX_LENGTH * MAX_WORDS) * (numLines+1));
        fgets(tempString, MAX_LENGTH * MAX_WORDS, fPtr);
        strcat(string, tempString);
    }
    numLines++;
    }
    return string;
}

char *stretchMe(char *aStringToStretch)
{
    /*This function takes a string and repeats each letter by input from the user*/
    int i;
    int j;
    int len;
    len = strlen(aStringToStretch);

    int *numForWord;
    numForWord = malloc(sizeof(int) * len);

    int totalChars;
    totalChars = 0;

    /*Takes input from the user on how many times to repeat each letter*/
    for(i = 0; i < len; i++)
    {
        scanf("%d", &numForWord[i]);
    }

    /*Finds out how many chars the string will be after the string is stretched so that the string can be allocated accordingly*/
    for(i = 0; i < len; i++)
    {
        totalChars = totalChars + numForWord[i];
    }

    char *newString;
    newString = malloc(sizeof(char) * totalChars);

    char *tempString;
    tempString = malloc(sizeof(char));

    /*tempString is used to stretch each letter individually and then concatenated it into the newString variable*/
    for(i = 0; i < len; i++)
    {
        tempString = NULL;
        tempString = realloc(tempString, sizeof(char) * numForWord[i]);
        for(j = 0; j < numForWord[i]; j++){
            tempString[j] = aStringToStretch[i];
        }
        strcat(newString, tempString);
    }
    return newString;
}

int splitMe (char * aStringToSplit, char static2D [MAX_WORDS][MAX_LENGTH])
{ 
    /*This function takes a string and stores each of its words in an array*/
    int i;

    int count;
    count = 0;

    char* tempString;
    tempString = malloc(sizeof(char) * strlen(aStringToSplit));
    strcpy(tempString, aStringToSplit);

    /*For loop to remove any \n characters*/
    for(i = 0; i < strlen(tempString); i++)
    {
        if(tempString[i] == '\n')
        {
            tempString[i] = ' ';
        }
    }

    /*strtok to split the string and store it in array*/
    char * token;
    token = strtok(tempString, " ");
    while(token != NULL)
    {
      strcpy(static2D[count], token);
      token = strtok(NULL, " ");
      count++;
   }
   return count;
}

int shrinkMe (char * aStringToShrink)
{
    /*This function takes a string and removes all punctuation with the exception of commas*/
    int i;
    int j;

    char* tempString;
    tempString = malloc(sizeof(char) * strlen(aStringToShrink));
    strcpy(tempString, aStringToShrink);

    int numFound;
    numFound = 0;

    int len;
    len = strlen(tempString);

    /*Iterates through each letter and checks if the current chaaracter is punctuation*/
    for(i = 0; i < len; i++)
    {
        if(tempString[i] == '.' || tempString[i] == ':' || tempString[i] == ';' || tempString[i] == '?' || tempString[i] == '!')
        {
            /*Algorithm to remove the punctuation and shift all succeeding letters forward*/
            for(j = i; j < len; j++)
            {
                tempString[j] = tempString[j+1];
            }
            len--;
            i--;
            numFound++;
        }
    }
    return numFound;
}

bool isItAPalindrome (char * aString)
{   
    /*This function takes a string and checks if each word is a palindrome*/
    int i;
    int j;

    int numOfWords;
    numOfWords = splitMe(aString, static2D);

    /*Loop iterates through all words in the string, and stores the current word in tempString*/
    for(i = 0; i < numOfWords; i++)
    {
        char* tempString;
        tempString = malloc(sizeof(char)*strlen(static2D[i]));
        strcpy(tempString, static2D[i]);
        int len;
        len = strlen(tempString);
        /*Iterates through all letters and checks if its mirror letter is the same*/
        for(j = 0; j < len; j++)
        {
            //If even a single letter does not pass, the function returns false
            if(tempString[j] != tempString[len-j-1])
            {
                return false;
            }
        }
    }
    //If all tests pass the function eventually returns true
    return true;
}

void printSuffixes (char * aString, int whichWord, char * desiredSuffix)
{   
    //Calls the splitMe function so it is easier to deal with individual words
    splitMe(aString, static2D);

    int i;

    char* tempString;
    tempString = malloc(sizeof(char)*strlen(static2D[whichWord-1]));
    strcpy(tempString, static2D[whichWord-1]);

    /*Prints the first letter of the target word and adds the suffix*/
    for(i = 0; i < strlen(tempString); i++)
    {
        printf("%c", tempString[i]);
        printf("%s", desiredSuffix);
        printf("\n");
    }
}