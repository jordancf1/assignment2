#include <stdbool.h>
#define MAX_LENGTH 20
#define MAX_WORDS 50

/* 
  Student Name: Jordan Fulawka
  Student ID: 1176755 
  Due Date: March 6, 2022
  Course: CIS*2500 
 
  I have exclusive control over this submission via my password. 
  By including this header comment, I certify that: 
   1) I have read and understood the policy on academic integrity. 
   2) I have completed Moodle's module on academic integrity. 
   3) I have achieved at least 80% on the academic integrity quiz 
  I assert that this work is my own. I have appropriate acknowledged 
  any and all material that I have used, be it directly quoted or 
  paraphrased. Furthermore, I certify that this assignment was written 
  by me in its entirety. 
*/


char static2D[MAX_WORDS][MAX_LENGTH];

char * readFile (char * filename);

char * stretchMe (char * aStringToStretch); 

int splitMe (char * aStringToSplit, char static2D [MAX_WORDS][MAX_LENGTH]);

int shrinkMe (char * aStringToShrink);

bool isItAPalindrome (char * aString);

void printSuffixes (char * aString, int whichWord, char * desiredSuffix);