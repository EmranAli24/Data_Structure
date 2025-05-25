// Using Recursion
#include<bits/stdc++.h>
using namespace std;

double CalculateInterest(double capital,double interest,int n){

    if(n==0) return capital;
    capital += (capital * interest);

   return CalculateInterest(capital,interest,n-1);

    

}
int main(){
    double capital,interest;
    int time;
    cin >> capital >> interest;
    cin >> time;
    interest = interest / 100 ;

    double capiWithInt = CalculateInterest(capital,interest,time);
    cout << capiWithInt << endl;
}