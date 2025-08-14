#include<bits/stdc++.h>
#define range 100000
using namespace std;
int primes[range];
void prime_no()
{
    int seive[range+1];
    memset(seive,1,sizeof(seive));
    seive[0] =0;
    seive[1] = 0;
    for(int i=2;i<=range;i++)
    {
        for(int j=2*i;j<=range;j+=i)
        {
            seive[j] = 0;
        }
    }
    memset(primes,0,sizeof(primes));
    int k=0;
    for(int i=2;i<=range;i++)
    {
        if(seive[i])
        {
            k++;
            primes[k] = i;

        }
    }
}

bool possible_case(int k, int n, vector<int> boards, long long mid )
{
    int curr =0;
    int painters=1;
   for(int i=0;i<n;i++)
    {
        if(curr + boards[i]> mid)
        {
            curr = boards[i];
            painters++;
            if(painters>k)
            {
                return false;
            }
        }
        else
        {
            curr += boards[i];
        }
    }
    return true;

}
long long painter_partition(int k, int n, vector<int> boards, long long max_time)
{
    long long s =0;
    long long e = max_time;
    long long ans = INT_MAX;
    while(s<=e)
    {
        long long mid = (s+e)/2;
        cout<<"Start "<<s<<" end : "<<e<<" Mid :"<<mid<<endl;
        if(possible_case(k,n,boards,mid))
        {
            ans = min(mid,ans);
            e = mid-1;

        }
        else
        {
            s = mid+1;
        }
    }
    return ans;

}
int main()
{
    int painters,total_boards,sum=0;
    cin>>painters>>total_boards;
    vector<int> boards;
    prime_no();
    long long max_time =0;
    for(int i=0;i<total_boards;i++)
    {
        int len;
        cin>>len;
        max_time += primes[len];
        boards.push_back(primes[len]);
    }
    cout<<painter_partition(painters,total_boards,boards,max_time);
    return 0;
}

/*

2 4
2 3 4 5
Start 0 end : 26 Mid :13
Start 14 end : 26 Mid :20
Start 14 end : 19 Mid :16
Start 14 end : 15 Mid :14
Start 15 end : 15 Mid :15
15

2 4
10 10 10 10
Start 0 end : 116 Mid :58
Start 0 end : 57 Mid :28
Start 29 end : 57 Mid :43
Start 44 end : 57 Mid :50
Start 51 end : 57 Mid :54
Start 55 end : 57 Mid :56
Start 57 end : 57 Mid :57
58


2 4
10 20 30 40
Start 0 end : 386 Mid :193
Start 194 end : 386 Mid :290
Start 194 end : 289 Mid :241
Start 194 end : 240 Mid :217
Start 194 end : 216 Mid :205
Start 206 end : 216 Mid :211
Start 212 end : 216 Mid :214
Start 212 end : 213 Mid :212
Start 213 end : 213 Mid :213
213


3 6
10 20 60 50 30 40
Start 0 end : 896 Mid :448
Start 0 end : 447 Mid :223
Start 224 end : 447 Mid :335
Start 336 end : 447 Mid :391
Start 336 end : 390 Mid :363
Start 364 end : 390 Mid :377
Start 378 end : 390 Mid :384
Start 378 end : 383 Mid :380
Start 381 end : 383 Mid :382
Start 381 end : 381 Mid :381
381


169 seive
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 307 311 313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431 433 439 443 449 457 461 463 467 479 487 491 499 503 509 521 523 541 547 557 563 569 571 577 587 593 599 601 607 613 617 619 631 641 643 647 653 659 661 673 677 683 691 701 709 719 727 733 739 743 751 757 761 769 773 787 797 809 811 821 823 827 829 839 853 857 859 863 877 881 883 887 907 911 919 929 937 941 947 953 967 971 977 983 991 997

*/
