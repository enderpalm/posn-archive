#include <string.h>

#include <iostream>

#define maxLength 101

using namespace std;

int dp[maxLength][maxLength];

int lcs(int i, int j, string a, string b) {
    if (dp[i][j] != -1) return dp[i][j];
    if (!i || !j) return dp[i][j] = 0;
    if (a[i - 1] == b[j - 1])
        return dp[i][j] = lcs(i - 1, j - 1, a, b) + 1;
    else
        return dp[i][j] = max(lcs(i - 1, j, a, b), lcs(i, j - 1, a, b));
}

int main() {
    string a = "AGTACGTAGCATGGTCACACAAGCACAGTAGATCCTGCCCGCGCATCCTATATATTAAGTTAATTCTAATGGAATACGATGACATGTGGATGGGCAGTGG";
    string b = "CCGGTTGTTACACGCCTACCGCGATGCTGAATGACCCGGACTAAAGTGGCGAAAATTATGGCGTGTGACCCGTTATGCTCCAGTTCGGTCAGTGGGTCAT";
    memset(dp, -1, sizeof(dp));
    printf("Size of longest common subsequence: %d\n", lcs(a.length(), b.length(), a, b));
    return 0;
}