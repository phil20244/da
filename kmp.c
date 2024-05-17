#include <stdio.h>
#include <string.h>

void computeLPSArray(char *pattern, int m, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(char *pattern, char *text) {
    int m = strlen(pattern);
    int n = strlen(text);

    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    if (j != m) {
        printf("Pattern not found in the text.\n");
    }
}

int main() {
    char text[1000], pattern[100];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the pattern to search for: ");
    fgets(pattern, sizeof(pattern), stdin);
    // Removing newline characters from input strings
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    KMP(pattern, text);
    return 0;
}

