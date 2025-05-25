/*
Algorithm 3.3: (Pattern Matching) P and T are strings with lengths R and S,
respectively, and are stored as arrays with one character per element. This
algorithm finds the INDEX of P in T.

1. [Initialize.] Set K := 1 and MAX : = S − R + 1.
2.  Repeat Steps 3 to 5 while K ≤ MAX:
3.    Repeat for L = 1 to R: [Tests each character of P.]
            If P[L] ≠ T[K + L − 1], then: Go to Step 5.
        [End of inner loop.]
4.    [Success.] Set INDEX = K, and Exit.
5.    Set K := K + 1.
[End of Step 2 outer loop.]
6. [Failure.] Set INDEX = 0.
7. Exit.


*/
#include <bits/stdc++.h>
using namespace std;

int firstPatternMatching(const string &P, const string &T)
{

    int R = P.length();
    int S = T.length();
    int k = 0; // for zero indexing
    int Max = S - R;
    int index = -1;

    while ((k <= Max))
    {
        bool match = true;

        for (int L = 0; L < R; L++)
        {
            if (P[L] != T[L + k])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            index = k + 1; // return 1-based index for output
            break;
        }

        k++;
    }

    return index;
}

int main()
{
    string P, T;

    cout << "Enter the pattern: ";
    cin >> P;

    cout << "Enter the text: ";
    cin >> T;

    int index = firstPatternMatching(P, T);

    if (index != -1)
    {
        cout << "Pattern found at position: " << index << endl;
    }
    else
    {
        cout << "Pattern not found." << endl;
    }

    return 0;
}