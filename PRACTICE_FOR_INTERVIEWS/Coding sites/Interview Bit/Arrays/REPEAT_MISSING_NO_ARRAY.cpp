vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> output;
    int xor1 = 0;

    for(int i=0;i<A.size();i++)
    {
        xor1 ^= (A[i]^(i+1));
    }
    int temp = xor1;
    int setBit=0;
    ///to create mask
    while(temp>0)
    {
        if(temp&1)
        {
            break;
        }
        setBit++;
        temp >>= 1;

    }
    /// mask using first set bit obtained
    int mask = 1<<setBit;
    int missing = 0;
    int repeating = 0;
    for(int i=1;i<=A.size();i++)
    {
        if((mask&i)!=0)
        {
            missing ^= i;
        }
        else
        {
            repeating ^= i;
        }

    }
    for(int i=0;i<A.size();i++)
    {
        if((mask&A[i])!=0)
        {
            missing ^= A[i];
        }
        else
        {
            repeating ^= A[i];
        }

    }
    output.push_back(repeating);
    output.push_back(missing);
    return output;

}

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> output;
    unordered_map<int,bool> map;
    int repeating = 0,missing =0;
    for(int i=0;i<A.size();i++)
    {
        if(map[i]== NULL)
        {
            map[A[i]] = true;
        }
        else
        {
            repeating = i;
            break;
        }
    }

    for(int i=1;i<=A.size();i++)
    {
        if(map[i]== NULL)
        {
            missing = i;
        }
    }
    output.push_back(repeating);
    output.push_back(missing);
    return output;

}

#include <bits/stdc++.h>

using namespace std;

vector<int>repeatedNumber(const vector<int> &A) {
	long long int len = A.size();
	long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
	long long int missingNumber=0, repeating=0;

	for(int i=0;i<A.size(); i++){
	Sum_N -= (long long int)A[i];
	Sum_NSq -= (long long int)A[i]*(long long int)A[i];
	}

	missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
	repeating= missingNumber - Sum_N;
	vector <int> ans;
	ans.push_back(repeating);
	ans.push_back(missingNumber);
	return ans;

}


int main(void){
		std::vector<int> v = {4, 3, 6, 2, 1, 6,7};
	vector<int> res = repeatedNumber(v);
	for(int x: res){
		cout<< x<<" ";
	}
	cout<<endl;
}

