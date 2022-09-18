// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        return (p1.first/(double)p1.second)>(p2.first/(double)p2.second);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({arr[i].value,arr[i].weight});

        }
        sort(vp.begin(),vp.end(),cmp);
        int i=0;
        double ans=0;
        while(W>0 and i<n)
        {
            if(vp[i].second>W)
            {
                ans+=vp[i].first/(double)vp[i].second*W;
                break;
            }
            W-=vp[i].second;
            ans+=vp[i].first;
            i++;
        }
        return ans;
    }
};