#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Transform(char *a, int n) {
    if (n == 0) {
        // Return a copy of the input string if n is 0
        char *res = (char *)malloc(strlen(a) + 1);
        if (!res) {
            return NULL; // Allocation failed
        }
        strcpy(res, a);
        return res;
    }

    char *res = (char *)malloc(sizeof(char) * 10086);
    if (!res) {
        return NULL; // Allocation failed
    }
    
    for (int t = 0; t < n; t++) {
        int cnt = 1, opos = 0, rpos = 0;
        while (a[opos] != '\0') {
            if (a[opos] == a[opos + 1]) {
                cnt++;
                opos++;
            } else {
                res[rpos++] = cnt + '0';
                res[rpos++] = a[opos];
                cnt = 1;
                opos++;
            }
        }
        res[rpos] = '\0'; // Null-terminate the transformed string
        strcpy(a, res); // Copy the transformed string back to 'a' for the next iteration
    }
    return res;
}

int main() {
    system("chcp 65001");
    char strnums[10086];
    int n;
    
    // Use fgets instead of gets
    fgets(strnums, sizeof(strnums), stdin);
    
    // Remove the newline character if fgets reads it
    strnums[strcspn(strnums, "\n")] = 0;
    
    scanf("%d", &n);
    char *transformed = Transform(strnums, n);
    if (transformed) {
        printf("%s\n", transformed);
        free(transformed); // Free the allocated memory
    } else {
        printf("Memory allocation failed\n");
    }
    
    return 0;
}
