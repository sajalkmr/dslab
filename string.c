#include <stdio.h>

char str[100], pat[100], rep[100];
int pat_len;

void read_strings() {
    int i;
    printf("\nEnter the main string: ");
    fgets(str, sizeof(str), stdin);
    printf("\nEnter the pattern string: ");
    fgets(pat, sizeof(pat), stdin);
    printf("\nEnter the replace string: ");
    fgets(rep, sizeof(rep), stdin);

    for (i = 0; pat[i] != '\0'; i++)
        pat_len++;
}

void pattern_match() {
    int i, j, k, z = 0, count = 0;
    char final_str[100];

    for (i = 0; str[i] != '\0'; i++) {
        j = 0;
        while ((str[i + j] == pat[j]) && (j < pat_len))
            j++;

        if (pat[j] == '\0') {
            count++;
            for (k = 0; rep[k] != '\0'; k++, z++) {
                final_str[z] = rep[k];
            }
            i = i + pat_len - 1;
        } else {
            final_str[z] = str[i];
            z++;
        }
    }

    if (count == 0)
        printf("\nPattern doesn't exist in the main string!!!");
    else {
        final_str[z] = '\0';
        printf("\nThe number of occurrences of the pattern: %d", count);
        printf("\nThe main string after replacement is: %s\n", final_str);
    }
}

int main() {
    read_strings();
    pattern_match();
    return 0;
}
