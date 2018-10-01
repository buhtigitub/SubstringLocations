#include <stdio.h>

int * checkOccurrences(char *text, char *subtext) {
    int textLength = strlen(text);
    int subtextLength = strlen(subtext);
    
    int matches[textLength];
    int matchesLength = 0;
    
    for (int i = 0; i < textLength; i++) {
        //printf("Checking %c. ", text[i]);
        if (tolower(text[i]) == tolower(subtext[0])) {
            for (int j = 0; j < subtextLength; j++) {
                //printf("checking %c. ", subtext[j]);
                if (j == subtextLength-1) {
                    if (tolower(text[i+j]) == tolower(subtext[j])) {
                        //printf("Match at %i.", i + 1);
                        matches[matchesLength] = i+1;
                        matchesLength++;
                        i += subtextLength - 1;
                    }
                }
                else if (tolower(text[i+j]) != tolower(subtext[j])) {
                    //printf("%c doesn't match %c.", text[i+j], subtext[j]);
                    break;
                }
            }
        }
        fflush(stdout);
    }
    
    int *matchesReturn = (int *) malloc((matchesLength+1) * sizeof(int));
    matchesReturn[0] = matchesLength;
    for (int i = 0; i < matchesLength; i++) {
        matchesReturn[i+1] = matches[i];
    }
    return matchesReturn;
}

int main(void)
{
    char text[] = "Polly put the kettle on, polly put the kettle on, polly put the kettle on we'll all have tea";
    
    int *output;
    output = checkOccurrences(text, "Polly");
    if (output[0] == 0) {
        printf("<no matches>");
    }
    
    for (int i = 1; i <= output[0]; i++) {
        printf("%i", output[i]);
        if (i != output[0]) {
            printf(", ");
        }
        fflush(stdout);
    }

    return 0;
}