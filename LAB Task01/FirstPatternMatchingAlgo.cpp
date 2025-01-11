#include<bits/stdc++.h>
using namespace std;

int firstPatternMatching(const string &P,const string &T){

    int R = P.length();
    int S = T.length();
    int k=0;// for zero indexing
    int Max = S-R;
    int index = -1;

    while ((k <= Max))
    {
        bool match = true ;

        for(int L=0; L < R;L++){
            if(P[L] != T[L+k]){
               match = false;
                break;
            }
        }
        
    if(match){
        index = k+1; // return 1-based index for output 
        break;
    }

        k++;
    }

    return index;
    
}


int main(){
    string P,T;
    
    cout << "Enter the pattern: " ;
    cin >> P;

    cout << "Enter the text: ";
    cin >> T;

    int index = firstPatternMatching(P,T);

    if(index != -1){
        cout << "Pattern found at position: " << index << endl;
    } else{
        cout << "Pattern not found." << endl;
    }

    return 0;
}