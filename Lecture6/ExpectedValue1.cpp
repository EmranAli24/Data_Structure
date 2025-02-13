#include<bits/stdc++.h>
using namespace std;


int main() {
    double P_R1, P_R2;
    cout << "Enter probabilities P(R1) and P(R2): ";
    cin >> P_R1 >> P_R2;
    
    double E_T_given_R1, E_T_given_R2 ;
    cout << "Enter E(T|R1) and  E(T|R2) : ";
    cin >> E_T_given_R1 >> E_T_given_R2;
    
    // Solve for E(T)
    double E_T;
    E_T = (P_R1 * E_T_given_R1 + P_R2 * E_T_given_R2) / (1 - P_R2);
    
    cout << "Expected Value E(T) = " << E_T << endl;
    return 0;
}
