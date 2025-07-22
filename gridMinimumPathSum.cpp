class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i>=m || j>=n)return 1e9;
        if(dp[i][j] !=-1)return dp[i][j];
        if(i==m-1 && j==n-1)return grid[i][j];

        int right = solve(grid,i,j+1,dp);
        int bottom = solve(grid,i+1,j,dp);

        return dp[i][j] = min(right,bottom)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,0,0,dp);
    }
};
