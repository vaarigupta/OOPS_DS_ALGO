#include<iostream>
using namespace std;
void subsequence( char *input, char *output, int i, int j)
{
    if(input[i]== '\0')
    {
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    ///include the curr char
    output[j] = input[i];
    subsequence(input,output,i+1,j+1);
    ///exclude the curr char
    subsequence(input,output,i+1,j);
}
int main()
{
    char input[100],  output[100];
    cin>>input;
    subsequence(input,output,0,0);

    return 0;
}
