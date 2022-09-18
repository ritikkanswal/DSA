



class WordFilter {
public:
    map<string,int>mp;
    WordFilter(vector<string>& words) {
        int k=0;
        for(auto x:words)
        {
            for(int i=0;i<=x.size();i++)
            {
                for(int j=0;j<=x.size();j++)
                {
                    
                    mp[x.substr(0,i)+"#"+x.substr(j,x.size())]=k+1;
                }
            }
            k++;
        }
    }
    
    int f(string prefix, string suffix) {
        if(mp[prefix+"#"+suffix]>0)
            return mp[prefix+"#"+suffix]-1;
        else  
            return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */