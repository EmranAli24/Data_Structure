/* The simple approach is to create a list
 and add all values from 1 to N to it.
  Create a recursive function that takes a list, 
  start (position at which counting will start), 
  and k ( number of people to be skipped) as an argument.
 If the size of the list is one i.e. only one person left then return this position.
 Otherwise, start counting the k person in a clockwise direction from starting position and
  remove the person at the kth position. Now the person at the kth position is removed and 
  now counting will start from this position. This process continues till only one person is left.
*/

// if input is n(number of persons) and k ( skip > 1)

#include<bits/stdc++.h>
using namespace std;
#define pb push_back

 void Josephus(vector<int> person,int k,int index){

    // base case , when only one person is left 
    if(person.size() == 1){
        cout << person[0] << endl;
        return;
    }

    // find the index of first person which will die

    index = ((index + k) % person.size());
    
    //Remove the first person which is going to be killed
    person.erase(person.begin()+index);

    // recursive call for n-1 persons
    Josephus(person,k,index); 
}
int main(){

    int n ;
    cout << "Enter Number of persons: " ;
    cin >> n;
    int  k ;
    cout << "Enter number of steps to skip: ";
    cin >> k;
    k--; // (k-1) th person will be killed
    int index = 0; // the index where the person which will die

    vector<int> person;

    for(int i=1; i<= n; i++){
        person.pb(i);
    }

    Josephus(person,k,index);
}
 


