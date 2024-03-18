#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find and replace pattern in the main string
void findAndReplace(char *mainStr, char *pattern, char *replace) {
    int mainLen = strlen(mainStr);
    int patternLen = strlen(pattern);
    int replaceLen = strlen(replace);

    // Iterate through the main string
    for (int i = 0; i <= mainLen - patternLen; i++) {
        int j;

        // Check if the pattern is found at the current position
        for (j = 0; j < patternLen; j++) {
            if (mainStr[i + j] != pattern[j]) {
                break;
            }
        }

        // If pattern is found, replace it with replace string
        if (j == patternLen) {
            // Shift the remaining characters to make space for replace string
            for (int k = i + patternLen; k < mainLen + replaceLen - patternLen; k++) {
                mainStr[k + replaceLen - patternLen] = mainStr[k];
            }

            // Copy replace string into main string
            for (int k = 0; k < replaceLen; k++) {
                mainStr[i + k] = replace[k];
            }

            // Update main string length
            mainLen += replaceLen - patternLen;
        }
    }
}

int main() {
    char mainStr[100], pattern[100], replace[100];

    // Read main string, pattern, and replace string
    printf("Enter the main string: ");
    scanf("%s", mainStr);
    printf("Enter the pattern string: ");
    scanf("%s", pattern);
    printf("Enter the replace string: ");
    scanf("%s", replace);

    // Perform pattern matching and replacement
    findAndReplace(mainStr, pattern, replace);

    // Print the modified string
    printf("Modified string: %s\n", mainStr);

    return 0;
}
