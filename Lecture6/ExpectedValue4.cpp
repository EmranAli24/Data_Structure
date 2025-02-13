#include<bits/stdc++.h>
using namespace std;
int main(){

    double P_D1,P_D2,P_D3;

    cout << "Enter Probabilities for Door1(P_D1),Door2(P_D2),Door3(P_D3) : ";
    cin >> P_D1 >> P_D2 >> P_D3 ;

    double constant_D1,constant_D2,E_T_given_D3;

    cout << " Enter constants for E(T|D1) = E_T + constant_D1 ,";
    cout << " constants for E(T|D2) = E_T + constant_D2, and E(T|D3) : ";
    cin >> constant_D1 >> constant_D2 >> E_T_given_D3 ;

    double E_T;

    E_T = (P_D1*constant_D1 + P_D2 * constant_D2 + P_D3* E_T_given_D3) / (1 -(P_D1+P_D2));

    cout << "Expected value : " << E_T << endl;
    return 0;
}