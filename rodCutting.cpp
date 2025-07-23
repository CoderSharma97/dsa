// User function Template for C++

class Solution {
  public:
    int solve(vector<int>&price,int len,vector<int>&dp){
        if(len ==0){
            return 0;
        }
        
        if(dp[len] !=-1)return dp[len];
        int ans = 0;
        for(int i=1;i<=len;i++){
            if(len-i >=0){
                int res = solve(price,len-i,dp)+price[i-1];
                ans = max(res,ans);
            }
        }
        return dp[len] = ans;
    }
    int cutRod(vector<int> &price) {
        // code here
        int len = price.size();
        vector<int>dp(len+1,-1);
        return solve(price,len,dp);
        
    }
};
