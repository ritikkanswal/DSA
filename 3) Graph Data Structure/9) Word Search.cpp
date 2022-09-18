class Solution {
public:
    map<int,string>mp;
    bool dfs(vector<vector<char>>& board, string word,int x,int y,int count)
    {
        if(count==word.size()) return true;
        if(x==-1||x>=board.size()||y==-1||y>=board[0].size()||board[x][y]!=word[count])
            return 0;
        char tmp=board[x][y];
        board[x][y]='?';
        bool res=dfs(board,word,x-1,y,count+1)||
                 dfs(board,word,x,y-1,count+1)||
                 dfs(board,word,x+1,y,count+1)||
                 dfs(board,word,x,y+1,count+1);
        
        board[x][y]=tmp;
        return res;
    }
    bool exist(vector<vector<char>>& board,string word) 
    {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0] and dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};