// If the input is only n(number of persons) and default of k=1(skip step)

#include <bits/stdc++.h>
using namespace std;

int J(int n)
{
    if (n == 1) // Base case
        return 1;

    if (n % 2 == 0) // If n is even
        return 2 * J(n / 2) - 1;
    else // If n is odd
        return 2 * J(n / 2) + 1;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "J(" << n << ") = " << J(n) << endl;
    return 0;
}