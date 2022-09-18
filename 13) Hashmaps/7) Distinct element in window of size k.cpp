// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

// Method - 1
// Bruteforce
// Time -> O(n2)

// Method - 2
// Sliding window and Hashmap
// Time -> O(n) Space -> O(n)


class Solution{
  public:
    unordered_map<int,int>ump;
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector <int>res;
        for(int i=0;i<k;i++) ump[A[i]]++;
        for(int i=k;i<n;i++)
        {
            res.push_back(ump.size());
            ump[A[i]]++;
            ump[A[i-k]]--;
            if(ump[A[i-k]]==0)
            ump.erase(A[i-k]);
        }
        res.push_back(ump.size());
        return res;
    }
};