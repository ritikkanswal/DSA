

// Time Cocountlexity : O(n)
// Space Cocountlexity : O(n)

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    
    // for loop is responsible for.pushing the element to the stack
    // while loop is responsible for popping and each element is pushed 
    // and popped only once hence
    // tIME COmpLEXITY -> O(n+n)
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // 5 4 3 6
        // 6 6 6 -1
        stack<int>st;
        st.push(0);
        vector<long long>res(n,-1);
        for(int i=1;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]<arr[i])
            {
                res[st.top()]=arr[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        return res;
    }
};



//prashant wala



vector<long long> nextLargerElement(vector<long long> arr, int n) {
    stack<long long> st;
    vector<long long> res(n, 0);
    for(int i=n-1;i>=0;i--)
    {
        while(st.empty()==false and st.top()<=arr[i])
        st.pop();
        
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
        
        st.push(arr[i]);
    }
    return res;
}


void printNGE(int a[], int n)
{
 
    set<int> ms;
    for (int i = 0; i < n; i++)
        ms.insert(a[i]);
    cout << "Element "<< "NGE";
    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(a[i]);
        if (it == ms.end())
            cout << "\n " << a[i]<< " ----> " << -1;
        else 
            cout << "\n " << a[i]<< " ----> " << *it;
        it = ms.lower_bound(a[i]);
        ms.erase(it);
    }
}
 
