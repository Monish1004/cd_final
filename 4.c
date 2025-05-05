#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10

char productions[MAX][MAX];
char firstSet[MAX];
int prodCount = 0, firstCount = 0;

int isInFirstSet(char ch) {
    for (int i = 0; i < firstCount; i++) {
        if (ch == firstSet[i]) {
            return 1;
        }
    }
    return 0;
}

void addToFirstSet(char ch) {
    if (!isInFirstSet(ch)) {
        firstSet[firstCount++] = ch;
    }
}

void findFirst(char ch) {
    for (int i = 0; i < prodCount; i++) {
        if (productions[i][0] == ch) {
            char next = productions[i][2];
            if (next == '$') {
                addToFirstSet('$');
            } else if (islower(next) || !isalpha(next)) {
                addToFirstSet(next);
            } else {
                findFirst(next);
            }
        }
    }
}

int main() {
    char ch;
    printf("Enter the number of productions: ");
    scanf("%d", &prodCount);

    // Flush input buffer
    while ((getchar()) != '\n' && getchar() != EOF);

    printf("Enter %d productions (e.g., E=E+T):\n", prodCount);
    for (int i = 0; i < prodCount; i++) {
        scanf("%s", productions[i]);
    }

    // Flush input buffer again before reading char
    while ((getchar()) != '\n' && getchar() != EOF);

    printf("Enter the non-terminal: ");
    scanf("%c", &ch);

    findFirst(ch);

    printf("First(%c) = { ", ch);
    for (int i = 0; i < firstCount; i++) {
        printf("%c ", firstSet[i]);
    }
    printf("}\n");

    return 0;
}
