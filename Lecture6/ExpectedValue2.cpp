#include<bits/stdc++.h>
using namespace std;

int main() {
    double P_R1, P_R2, P_R3, P_R4;
    cout << "Enter probabilities P(R1), P(R2), P(R3), and P(R4): ";
    cin >> P_R1 >> P_R2 >> P_R3 >> P_R4;
    
    double E_T_given_R1, constant_R2, constant_R3, constant_R4;
    cout << "Enter E(T|R1) and constants for E(T|R2) = E_T + constant_R2, ";
    cout << "E(T|R3) = E_T + constant_R3, and E(T|R4) = E_T + constant_R4: ";
    cin >> E_T_given_R1 >> constant_R2 >> constant_R3 >> constant_R4;
    

    double E_T = (P_R1 * E_T_given_R1 + P_R2 * constant_R2 + P_R3 * constant_R3 + P_R4 * constant_R4) / (1 - (P_R2 + P_R3 + P_R4));
    
    cout << "Expected Value E(T) = " << E_T << endl;
    return 0;
}