#include <iostream>
using namespace std

///Convert the string into palindrome string by changing only one character
/// https://www.geeksforgeeks.org/convert-string-palindrome-string-changing-one-character/
bool CanMakePalindrome(string str)
{
    int i = 0;
    int j = str.length()-1;
    int cnt =0;
    while(i<j)
    {
        if(cnt>1)
          return false;
        if(str[i]!=str[j])
        {
            cnt++;
        }
        i++;
        j--;
    }
    if(cnt>1)
      return false;
    else
      return true;
}
int main() {

	string str;
    cin>>str;
    bool ans = CanMakePalindrome(str);

    if(ans)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
	return 0;
}
