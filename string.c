#include <stdio.h>

void read_strings(char str[], char pat[], char rep[]) {
    printf("Enter the main string: ");
    gets(str);

    printf("Enter the pattern string: ");
    gets(pat);

    printf("Enter the replace string: ");
    gets(rep);
}

void pattern_replace(char str[], char pat[], char rep[]) {
    int i, j, k, count = 0;
    char final_str[100];

    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; pat[j] != '\0' && str[i + j] == pat[j]; j++);

        if (pat[j] == '\0') {
            count++;

            for (k = 0; rep[k] != '\0'; k++)
                final_str[i + k] = rep[k];

            i += j - 1;
        } else {
            final_str[i] = str[i];
        }
    }

    final_str[i] = '\0';

    if (count == 0) {
        printf("\nPattern doesn't exist in the main string!!!");
    } else {
        printf("\nThe number of occurrences of the pattern: %d", count);
        printf("\nThe main string after replacement is: %s\n", final_str);
    }
}

int main() {
    char str[100], pat[100], rep[100];

    read_strings(str, pat, rep);
    pattern_replace(str, pat, rep);

    return 0;
}
