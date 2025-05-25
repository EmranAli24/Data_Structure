
// https://leetcode.com/problems/subsets/description/
#include <bits/stdc++.h>
using namespace std;

void backtrace(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &result)
{
    result.push_back(path);
    for (int i = start; i < nums.size(); i++)
    {
        path.push_back(nums[i]);
        backtrace(nums, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> path;
    backtrace(nums, 0, path, result);
    return result;
}


int main()
{

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> result = subsets(v);

    for (auto &u : result){
        for (auto &w : u)
        cout << w << " ";

        cout << "\n";
    }
       

    return 0;
}


/****
1.Initially the (result) list is empty.
2. we start with the initial call to the backtrack func. with start=0 and path = [].
3.Inside the backtrack func:
    *we add the current path(empty) to the result.so,result = [[]];
    *we iterate over the elements of nums starting from index start = 0;
4. For the first element 1: 
    we add 1 to the path,so path = [1];
    we make a recursive call to backtrack(1,[1]);
5.Inside the recursive call with start = 1 and path = [1]:
    * We add the current path [1] to the result.so,result = [[],[1]];
    *ew iterate over the elements of nums. starting from index start = 1.

***/
