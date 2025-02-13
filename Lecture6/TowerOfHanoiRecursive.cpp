// ref: GFG
// C++ recursive function to
// solve tower of hanoi puzzle

#include <bits/stdc++.h>
using namespace std;

/*
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
      cout << "Move disk " << n << " from rod " << from_rod
        << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int N = 3;

    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}

*/

int TOH(int N, char from_rod, char to_rod, char aux_rod)
{

    if (N == 0)
    {
        return 0;
    }
    int count = 0;

    count += TOH(N - 1, from_rod, aux_rod, to_rod);
    count++;
    printf("Move disk %d from %c to %c\n", N, from_rod, to_rod);
    count += TOH(N - 1, aux_rod, to_rod, from_rod);

    return count;
}

int main()
{
    int N = 3;

    int count = TOH(N, 'A', 'B', 'C');
    cout << "Total moves: " << count << endl;
    return 0;
}