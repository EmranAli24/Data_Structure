#include<bits/stdc++.h>
using namespace std;

double FuelPrice(double price,double rate,int n){
    if(n==0) return price ;
    price += price*rate;
    return FuelPrice(price,rate,n-1);
}

int main(){
    double initialPrice,annual_rate;
    int year;
    cin >> initialPrice >> annual_rate >> year ;

    annual_rate /= 100;

    double future_price = FuelPrice(initialPrice,annual_rate,year);
    cout << "The estimated fuel price after " << year << " Years: " << future_price << endl;
}