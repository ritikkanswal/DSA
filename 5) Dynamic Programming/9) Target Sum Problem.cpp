#include <bits/stdc++.h>
#define mod 1000000007
#define lli long long int
using namespace std;
bool ch(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' ||
        x == 'o' || x == 'u' || x == 'A' ||
        x == 'E' || x == 'I' || x == 'O' || x == 'U')
    return 1;
    else
    return 0;
}
int countmin(string p)
{
    int v=0;
    int sz=p.size();
    for(auto x:p){

        int mi=INT_MAX;
        if(ch(x))
        {
            v++;
        }
    }
    vector<int>ans;
    for(auto x:p){

        int mi=INT_MAX;
        if(!ch(x))
        {
            int a=abs(x-'a');
            int e=abs(x-'e');
            int i=abs(x-'i');
            int o=abs(x-'o');
            int u=abs(x-'u');
            mi=min({a,e,i,o,u});
            ans.push_back(mi);
        }
    }

    if(sz/2==v)
        return 0;
    else
    {
        int f=sz/2-v;
        if(f<0)
        return abs(f);
        int sum=0;
        sort(ans.begin(), ans.end());
        for(int i=0;i<f;i++){
            sum+=ans[i];
        }
        return sum;
    }

}

int main()
{
    string s;
    cin>>s;
    cout<<countmin(s)<<endl;;
    return 0;
}