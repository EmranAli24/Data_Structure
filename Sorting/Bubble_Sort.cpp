/****************************************************************************
 *  
 * Algorithm 4.4: (Bubble Sort) BUBBLE(DATA, N)
 Here DATA is an array with N elements. This algorithm
 sorts the elements in DATA.
 1. Repeat Steps 2 and 3 for K = 1 to N – 1.
 2. Set PTR := 1. [Initializes pass pointer PTR.]
 3. Repeat while PTR ≤ N – K [Executes pass.]
 (a) If DATA[PTR] > DATA[PTR + 1], then:
 Interchange DATA[PTR] and DATA[PTR + 1].
 [End of If structure.]
 (b) Set PTR := PTR + 1.
 [End of inner loop.]
 [End of Step 1 outer loop.]
 4. Exit
 * 
 *******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

template<typename T>
void BubbleSort(T DATA[],int N){
    int K,PTR;
    T temp;

    for(K=0;K<N;K++){
        PTR = 0;
        
        while (PTR < N-K-1)   
        {
            if(DATA[PTR] > DATA[PTR+1]){
                temp = DATA[PTR];
                DATA[PTR] = DATA[PTR+1];
                DATA[PTR+1] = temp; 
            }
            PTR++;
        }
        
    }
    
    cout << "After Sorting The Array: " << endl; 
    for(int i=0;i<N;i++){
        cout <<DATA[i] << " " ;
    }
    cout << "" << endl;

}



#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;

    int DATA[N];
    for(int i=0;i<N;i++){
        cin >> DATA[i];
    }

    BubbleSort<int>(DATA,N);
} 