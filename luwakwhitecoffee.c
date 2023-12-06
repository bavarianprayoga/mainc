#include <stdio.h>
#include <string.h>

int main() {
    int T, N;
    char X[101], changes[26][2];
    int freq[26] = {0};

    // Read the number of test cases
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        // Read the initial string
        scanf("%s", X);

        // Read the number of processes
        scanf("%d", &N);

        // Read the processes
        for (int n = 0; n < N; n++) {
            scanf(" %c %c", &changes[n][0], &changes[n][1]);
        }

        // Count the frequency of each character
        for (int i = 0; i < strlen(X); i++) {
            freq[X[i] - 'A']++;
        }

        // Apply the changes
        for (int n = 0; n < N; n++) {
            freq[changes[n][1] - 'A'] += freq[changes[n][0] - 'A'];
            freq[changes[n][0] - 'A'] = 0;
        }

        // Print the result
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                printf("%c %d\n", i + 'A', freq[i]);
            }
        }
    }

    return 0;
}
