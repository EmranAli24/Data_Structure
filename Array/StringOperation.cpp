#include<bits/stdc++.h>
using namespace std;

string REPLACE(const string& str, const string& pattern1, const string& pattern2) {
    size_t pos = str.find(pattern1);
    if (pos != string::npos) {
        string result = str;
        result.replace(pos, pattern1.length(), pattern2);
        return result;
    }
    return str; // Return the original string if pattern1 is not found
}

int main(){

string str = "TO BE OR NOT TO BE";
cout << str.substr(4,7) << endl;
string str1 = "THE END";
cout << str1.substr(4,4) << endl;

string text = "He is wearing glasses";
int32_t index = text.find("ear");
cout << index << endl;
string text2 = "HIS FATHER IS THE PROFESSOR";
int index1 = text2.find("THE");
cout << index1 << endl; 

int32_t index2 = text2.find("THEN");
cout << index2  << endl;
string s1 = "MARK", s2 = "TWIN";
string conStr = s1.append(s2);
cout << conStr << endl;
// cout << s1+s2 << endl;

string stINSERT = "ABCDEF";
stINSERT.insert(3,"XYZ");
cout << stINSERT << endl;


string stDLT = "ABCDEFG";
stDLT.erase(4,2);
cout << stDLT << endl;

string stReplace = "XABYABZ";
stReplace = REPLACE(stReplace,"BA","C");
cout << stReplace << endl;

}
