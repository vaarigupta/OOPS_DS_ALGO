#include<bits/stdc++.h>
using namespace std;
struct roman_letter
{
    int decimal;
    char *roman;
};

const roman_letter roman_index[] =
{
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"},
};

const int roman_len = sizeof(roman_index)/sizeof(roman_letter);

    string intToRoman(int remainder)
    {
        string output;

        while (remainder > 0)
        {
            for (int i = 0; i < roman_len;i++)
            {
                if (roman_index[i].decimal <= remainder)
                {
                    remainder -= roman_index[i].decimal;
                    output += roman_index[i].roman;
                    break;
                }
            }
        }

        return output;
    }
int main()
{

        int n;
        cin>>n;
        cout<<intToRoman(n)<<endl;
    return 0;
}
