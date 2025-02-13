#include<bits/stdc++.h>
using namespace std;

int Josephus(int num){
    string binaryNum = bitset<32>(num).to_string();// convert to 32bit binary string
    size_t pos = binaryNum.find('1'); // find the position of MSB(first'1)

    if(pos == string::npos) return 0; // if no '1' is found,return 0;
    string newBinaryNum = binaryNum.substr(pos+1)+"1"; // move the MSB to the last position
    int newDecimal = bitset<32>(newBinaryNum).to_ulong(); // convert back to decimal

    return newDecimal;
}

int main(){
    int num;
    cout << "Enter number of persons: ";
    cin >> num ;

    int freePerson = Josephus(num);

    cout << "The " << freePerson <<"th person will be free." << endl;
    return 0;
}