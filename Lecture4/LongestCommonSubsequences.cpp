#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute the length of the LCS and print the LCS string
void LCS(const string& A, const string& B) {
    int n = A.length();
    int m = B.length();

    // Create a 2D DP table of size (n+1) x (m+1)
    vector<vector<int>> L(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // Backtrack to construct the LCS string
    int i = n, j = m;
    string lcs;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs = A[i - 1] + lcs; // Add the matching character to the result
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Output the results
    cout << "Length of LCS: " << L[n][m] << endl;
    cout << "LCS String: " << lcs << endl;
}

int main() {
    string A, B;

    // Input the two strings
    cout << "Enter the first string: ";
    cin >> A;
    cout << "Enter the second string: ";
    cin >> B;

    // Compute and print the LCS
    LCS(A, B);

    return 0;
}