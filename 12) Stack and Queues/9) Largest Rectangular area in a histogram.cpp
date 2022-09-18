


class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int>st;
        st.push(0);
        int n=nums.size();
        
        vector<int>next(n,n),prev(n,-1);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            while(!st.empty() and nums[st.top()]>nums[i])
            {
                next[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()]>nums[i])
            {
                prev[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
        for(int i=0;i<n;i++)
        {
            ans = max(ans, (next[i] - prev[i]-1) * nums[i]);
        }
        
        return ans;
    }
};