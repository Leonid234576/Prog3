#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>&v,int a,int n)
{
    int a1=a/n,a2=a%n;
    for(int i=0;i<v.size();i++)
    {
        int b1=v[i]/n,b2=v[i]%n;
        if(a1==b1||a2==b2||abs(a1-b1)==abs(b2-a2))return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<vector<int>>>v;
    v.resize(n+1);
    v[0].push_back({});
    for(int k=1;k<=n;k++)
    {
        for(int i=0;i<n*n;i++)
        {
            for(int j=0;j<v[k-1].size();j++)
            {
                if(check(v[k-1][j],i,n))
                {
                    v[k].push_back(v[k-1][j]);
                    v[k][v[k].size()-1].push_back(i);
                }
            }
        }
    }
    cout<<v[n].size();
    return 0;
}
