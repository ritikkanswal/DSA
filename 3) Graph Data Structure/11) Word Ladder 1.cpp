class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int cnt = 0;
        map<string, int>m;
        for(int i=0;i<wordList.size();i++)
            m[wordList[i]]=1;
     
        
        queue<vector<string>>q;
        q.push({beginWord});
        while(q.empty()==false)
        {
            int qu = q.size();
            cnt++;
            for(int i=0;i<qu;i++)
            {
                auto curr_path = q.front();
                q.pop();
                string tmp=curr_path.back();
                if(tmp==endWord)
                    return cnt;
                
               
                for(int j=0;j<tmp.size();j++)
                {
                    string x = tmp;
                    for(int k=0;k<26;k++)
                    {
                        tmp[j]=k+'a';
                        if(m.find(tmp)!=m.end())
                        {
                            auto new_path=curr_path;
                            new_path.push_back(tmp);
                            q.push(new_path);
                            m.erase(tmp);
                        }
                    }
                    tmp = x;
                }
            }
        }
        return 0;
    }
};