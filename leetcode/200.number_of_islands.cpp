class Solution {
public:

    bool check(vector<vector<char>>& grid, int m, int n, int curi, int curj, vector<vector<bool>>& visited){
        if(curi<0 || curi>=m || curj<0 || curj>=n || visited[curi][curj]==true || grid[curi][curj]=='0'){
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>>& grid, int m, int n, int curi, int curj, vector<vector<bool>>& visited){
        visited[curi][curj]=true;

        int nexti,nextj;
        nexti=curi;
        nextj=curj+1;
        if(check(grid,m,n,nexti, nextj, visited)){
            dfs(grid, m, n, nexti, nextj, visited);
        }

        nexti=curi+1;
        nextj=curj;
        if(check(grid,m,n,nexti, nextj, visited)){
            dfs(grid, m, n, nexti, nextj, visited);
        }

        nexti=curi;
        nextj=curj-1;
        if(check(grid,m,n,nexti, nextj, visited)){
            dfs(grid, m, n, nexti, nextj, visited);
        }

        nexti=curi-1;
        nextj=curj;
        if(check(grid,m,n,nexti, nextj, visited)){
            dfs(grid, m, n, nexti, nextj, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i < m;i++){
            for(int j=0; j< n; j++){
                if(grid[i][j]=='1'&&visited[i][j]==false){
                    count++;
                    dfs(grid, m, n, i, j, visited);
                }
            }
        }
        return count;
    }
};
