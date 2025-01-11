#include <bits/stdc++.h>
using namespace std;

int stringLength(string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

string subsString(string str, int initial, int length)
{

    string subs_str = "";
    for (int i = initial - 1; i < initial + length - 1 && str[i] != '\0'; i++)
    {
        subs_str += str[i];
    }

    return subs_str;
}

int Index(string text, string pattern)
{
    int n = stringLength(text);
    int m = stringLength(pattern);

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
        {
            return i + 1;
        }
    }

    return -1;
}

string stringConcatenation(string str1, string str2)
{
    string result="";
    int i, j = 0;

    for (i = 0; i < str1.length(); i++)
    {
        result += str1[i];
    }

    for (i = 0; i < str2.length(); i++)
    {
        result+= str2[i];
    }

    return result;
}

string StringInsertion(string str,int position,string pattern){
    string result = "";
    int len = stringLength(str);
    int pLen = stringLength(pattern);

    for(int i=0;i<position-1;i++){
        result += str[i];
    }

    for(int j=0;j< pLen;j++){
        result += pattern[j];
    }

    for(int i=position-1;i<len;i++){
        result += str[i];
    }

    return result;
       
}

string stringDeletion(string str,int position,int length){

    string result = "";
    int strLen = stringLength(str);

    if(position == 0){
        result = str ;
        return result;

    }

    for(int i=0;i<position-1;i++){
        result += str[i];
    }

    for(int i=position-1+length ; i < strLen;i++){
        result += str[i];
    }

    return result ;

}

string stringReplacement(string str,string pt1,string pt2){
   int loc = Index(str,pt1);
   int strLen = stringLength(str);
   int pt2Len = stringLength(pt2);
   int pt1Len = stringLength(pt1);
   string result;

   if(loc==-1){
    result = str;
   }
   else{
    for(int i=0;i<loc-1;i++){
        result += str[i];
    }

    for(int k=0;k<pt2Len;k++){
        result += pt2[k];
    }

    for(int j=loc+pt1Len-1; j<strLen;j++){
        result += str[j];
    }

   }

   return result;
}

int main()
{

    string str1 = "computer ";


    int length = stringLength(str1);
    cout << length << endl;
    cout << subsString("To be or not to be", 4, 7) << endl;
    cout << subsString("THE END", 4, 4) << endl;
    cout << Index("He is wearing glasses", "ear") << endl;
    cout << Index("HIS FATHER IS THE PROFESSOR", "THE") << endl;
    cout << stringConcatenation("MARK", "TWIN") << endl;
    cout << StringInsertion("ABCDEF",3,"XYZ") << endl;
    cout << StringInsertion("him",1,"fa") << endl;
    cout << stringDeletion("ABCDEFG",4,2) << endl;
    cout << stringDeletion("ABCDEFG",2,4) << endl;
    cout << stringDeletion("ABCDEFG",0,2) << endl;
    cout << stringReplacement("XABYABZ","AB","C") << endl;
    cout << stringReplacement("XABYABZ","BA","C") << endl;
    return 0;
}