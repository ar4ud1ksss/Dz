
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

char** BreakingUp (char* A);

int main()
    {
    char* A = (char*) calloc (100, sizeof (char));
    fgets (A, 100, stdin);
    BreakingUp(A);
    }

char** BreakingUp (char* A)
    {
    int length = strlen (A) - 1;
    int num = 1;
    char** ArrayOfWords = (char**) calloc (length, sizeof(char*));
    ArrayOfWords[0] = &A[0];
    for (int i = 0; i < length; i++)
        if (A[i] == ' ')
            {
            A[i] = '\0';
            ArrayOfWords[num] = &A[i] + 1;
            num++;
            }
    for (int i = 0; i < num; i++)         
        printf ("%s\n", ArrayOfWords[i]);
    }
