class Solution {
  public:
    bool solve(vector<int>&nums,int sum,int n,vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(sum<0 || n<0)return 0;
        if(dp[n][sum] != -1)return dp[n][sum];
    
        bool pick = solve(nums,sum-nums[n],n-1,dp);
        
        bool notPick = solve(nums,sum,n-1,dp);
        
        return dp[n][sum] = pick||notPick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(arr,sum,n-1,dp);
    }
};
