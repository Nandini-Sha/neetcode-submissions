class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> copy = grid;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2147483647){
                    int mind = INT_MAX;
                    int temp = grid[i][j];
                    grid[i][j] = -2;
                    find(grid,i,j,0,mind);
                    grid[i][j] = temp;
                    copy[i][j] = mind;
                }
            }
        }
        grid = copy;
    }
    void find(vector<vector<int>>& grid, int i, int j, int d, int& mind){
        int m = grid.size();
        int n = grid[0].size();
        if(d>=mind) return;
        if(grid[i][j] == 0){
            mind = min(mind,d);
            return;
        }
        if(i+1<m && grid[i+1][j]!=-1 && grid[i+1][j]!=-2){
            if(grid[i+1][j] != 0){
                int temp = grid[i+1][j];
                grid[i+1][j] = -2;
                find(grid,i+1,j,d+1,mind);
                grid[i+1][j] = temp;
            }
            else{
                find(grid,i+1,j,d+1,mind);
            }
        }
        if(i-1>=0 && grid[i-1][j]!=-1 && grid[i-1][j]!=-2){
            if(grid[i-1][j] != 0){
                int temp = grid[i-1][j];
                grid[i-1][j] = -2;
                find(grid,i-1,j,d+1,mind);
                grid[i-1][j] = temp;
            }
            else{
                find(grid,i-1,j,d+1,mind);
            }
        }
        if(j+1<n && grid[i][j+1]!=-1 && grid[i][j+1]!=-2){
            if(grid[i][j+1] != 0){
                int temp = grid[i][j+1];
                grid[i][j+1] = -2;
                find(grid,i,j+1,d+1,mind);
                grid[i][j+1] = temp;
            }
            else{
                find(grid,i,j+1,d+1,mind);
            }
        }
        if(j-1>=0 && grid[i][j-1]!=-1 && grid[i][j-1]!=-2){
            if(grid[i][j-1] != 0){
                int temp = grid[i][j-1];
                grid[i][j-1] = -2;
                find(grid,i,j-1,d+1,mind);
                grid[i][j-1] = temp;
            }
            else{
                find(grid,i,j-1,d+1,mind);
            }
        }
    }
};
