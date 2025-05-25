// Using pow func.
#include<bits/stdc++.h>
using namespace std;
int main(){
    double capital,interest,time;

    cin >> capital >> interest >> time;
    interest /= 100;
    double result = pow(1+interest,time) * capital ;
    cout << result << endl;
}
