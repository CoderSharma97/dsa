class Solution {
public:
    int solve(vector<int>&nums,int index,vector<int>&dp,int k){
        if(index == nums.size())return 0;
        if(dp[index] != -1)return dp[index];
        int n = nums.size();
        int maxi = 0;
        int ans = 0;
        for(int i=index;i<min(index+k,n);i++){
            maxi = max(nums[i],maxi);
            ans = max((i-index+1)*maxi+solve(nums,i+1,dp,k),ans);
        }
        return dp[index]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp,k);
    }
};
