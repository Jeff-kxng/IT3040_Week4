/* Bài tập 13: Đếm xâu con */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000005

long long countEqualSubstrings(char *s) {
    long long count = 0;
    int i, zeros = 0, ones = 0;
    int *freq = (int *)malloc(sizeof(int) * MAX_LENGTH * 2);
    memset(freq, 0, sizeof(int) * MAX_LENGTH * 2);
    int diff = 0;

    freq[MAX_LENGTH] = 1; // Khởi tạo tần suất của diff = 0

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') {
            zeros++;
        } else {
            ones++;
        }

        diff = zeros - ones;

        count += freq[MAX_LENGTH + diff]; // Cập nhật số lượng xâu con thỏa mãn

        freq[MAX_LENGTH + diff]++; // Cập nhật tần suất xuất hiện của diff
    }

    free(freq);
    return count;
}

int main() {
    char s[MAX_LENGTH];
    scanf("%s", s);

    long long result = countEqualSubstrings(s);
    printf("%lld\n", result);

    return 0;
}
