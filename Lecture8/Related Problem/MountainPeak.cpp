#include <bits/stdc++.h>
using namespace std;

void fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {

   fastio();
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> st; // Stack to store indices of elements

    // Iterate from the end to the start
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are <= current element
        while (!st.empty() && st.top() <= heights[i]) {
            st.pop();
        }
        // If stack is not empty, the top is the next greater element
        if (!st.empty()) {
            result[i] = st.top();
        }
        // Push the current element onto the stack
        st.push(heights[i]);
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}