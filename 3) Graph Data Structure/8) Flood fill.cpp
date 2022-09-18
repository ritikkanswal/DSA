 bool visited[52][52];
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int sColor)
    {
        int r=image.size();
        int c=image[0].size();
        if(sr<0||sc<0||sr>=r||sc>=c||image[sr][sc]!=sColor||visited[sr][sc]==1) return;
        
        image[sr][sc]=newColor;
        visited[sr][sc]=1;
        
        dfs(image,sr+1,sc,newColor,sColor);
        
        dfs(image,sr,sc+1,newColor,sColor);
        
        dfs(image,sr-1,sc,newColor,sColor);
        
        dfs(image,sr,sc-1,newColor,sColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }