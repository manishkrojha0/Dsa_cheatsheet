#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(int a[], int n){
    

    int sum=-1e9,cur=0;
    for(int i=0;i<n;i++)
    {
        cur+=a[i];
        if(cur<0)
        {
            sum=max(sum,cur);
            cur=0;
            
        }
        else
        sum=max(sum,cur);

    }
  //  cout<<"cur="<<cur<<" sum="<<sum<<endl;
    return sum;
}
void solve()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<maxSubarraySum(a,n);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
