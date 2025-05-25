#include <iostream>
#include <string>

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

int main() {
    string original = "ABXYEFGH";
    string pattern1 = "XY";
    string pattern2 = "CD";

    string result = REPLACE(original, pattern1, pattern2);
    cout << "Result: " << result << endl;

    return 0;
}