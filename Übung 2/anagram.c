#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_anagram(char *word, char *compared) {
    if (strlen(word) != strlen(compared)) return 0;

    size_t i, j;
    int used[strlen(word)];
    for (size_t k = 0; k < strlen(word); k++) used[k] = 0;

    for (i = 0; i < strlen(word); i++) {
        for (j = 0; j < strlen(compared); j++) {
            if (word[i] == compared[j]) {
                if (used[j] == 0) {
                    used[j] = 1;
                    break;
                }
            }
        }
        if (j == strlen(compared)) return 0;
    }
    if (i == strlen(word)) return 1;
    return 0;
}

int main() {
    // test your code
    printf("%d\n", is_anagram("mehle", "helme"));
    printf("%d\n", is_anagram("boeing", "airbus"));
    return EXIT_SUCCESS;
}
