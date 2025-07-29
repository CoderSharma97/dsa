class Solution {
public:
    int solve(string &s1,string &s2,int n1,int n2,vector<vector<int>>&dp){
        if(n1<0 || n2 <0)return 0;
        if(dp[n1][n2] != -1)return dp[n1][n2];
        int ans = 0;
        if(s1[n1]==s2[n2]){
            ans = 1+solve(s1,s2,n1-1,n2-1,dp);
        }
        else{
            ans = max(solve(s1,s2,n1-1,n2,dp),solve(s1,s2,n1,n2-1,dp));
        }
        return dp[n1][n2] = ans;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();

        string temp = s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));

        return solve(s,temp,n-1,n-1,dp);
    }
};
