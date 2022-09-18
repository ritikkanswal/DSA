


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {           unordered_set<string> m(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        int cnt = 0;
     
        vector<vector<string>>res;
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
                            if(tmp==endWord)
                                res.push_back(new_path);
                            else
                                q.push(new_path);
                            visited.insert(tmp);
                        }
                    }
                    tmp = x;
                }
            }
             for(auto& str : visited)
                    m.erase(str);
        }
        return res;
    }
};