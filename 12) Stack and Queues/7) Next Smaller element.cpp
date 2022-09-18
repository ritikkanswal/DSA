


// Time Complexity : O(n)
// Space Complexity : O(n)



class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int>st;
        vector<int>res(n,-1);
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>arr[i])
            {
                res[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    } 
};
