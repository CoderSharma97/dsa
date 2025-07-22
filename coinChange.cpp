class Solution {
public:
    int solve(vector<int>&nums,int sum ,int n,vector<vector<int>>&dp){

        if(sum==0)return 0;
        if(n==-1)return 1e9;
        if(dp[n][sum] != -1)return dp[n][sum];


        int pick =1e9;
        if(sum-nums[n] >=0){
          pick = solve(nums,sum-nums[n],n,dp)+1;
        }
        int notPick = solve(nums,sum,n-1,dp);

        return dp[n][sum] =  min(pick,notPick);
    }
    int coinChange(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));

       int res = solve(nums,sum,n-1,dp);
        return res == 1e9? -1:res;
    }
};
