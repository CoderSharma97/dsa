// User function Template for C++

class Solution {
  public:
    int solve(vector<int>&val,vector<int>&wt,int capacity,int n,
    vector<vector<int>>&dp){
        if(n==-1){
            return 0;
        }
        if(dp[n][capacity] !=-1)return dp[n][capacity];
        int pick = 0;
        if(capacity-wt[n]  >=0)
        pick = solve(val,wt,capacity-wt[n],n,dp)+val[n];
        int notPick = solve(val,wt,capacity,n-1,dp);
        
        return dp[n][capacity]=  max(pick,notPick);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n  = val.size();
        int profit = 0;
        
       
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        
        return solve(val,wt,capacity,n-1,dp);
    }
};
