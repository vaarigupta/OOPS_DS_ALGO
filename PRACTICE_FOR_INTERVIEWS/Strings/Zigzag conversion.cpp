#include<bits/stdc++.h>
using namespace std;
///https://leetcode.com/problems/zigzag-conversion/
string convert(string s, int numRows) {

        int l = s.length();
        if(l==0) return "";
        if(numRows==1 || numRows>=l) return s;
        vector<string> rows(numRows, "");
        bool goingDown = false;
        string output = "";
        int zig =0;
        for(int i=0;s[i]!='\0';i++)
        {
            rows[zig] += s[i];
            if(zig==0 || zig==numRows-1) goingDown = !goingDown;
            zig += goingDown?1:-1;
        }
        for(int i=0;i<numRows;i++)
        {
            output+= rows[i];
        }
        return output;

    }
int main()
{
    string str;
    int rows;
    cin>>str>>rows;
    cout<<convert(str,rows);
    return 0;
}
/*

PAYPALISHIRING
3
PAHNAPLSIIGYIR
*/
