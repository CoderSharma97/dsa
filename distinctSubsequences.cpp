class Solution {
public:
    int solve(string &s1,string &s2,int n1,int n2,vector<vector<int>>&dp){
        if(n2==-1)return 1;
        if(n1==-1)return 0;
        if(dp[n1][n2] != -1)return dp[n1][n2];
        int ans = 0;
        if(s1[n1]==s2[n2]){
            ans = solve(s1,s2,n1-1,n2-1,dp)+solve(s1,s2,n1-1,n2,dp);
        }
        else{
            ans = solve(s1,s2,n1-1,n2,dp);
        }
        return dp[n1][n2] = ans;
    }
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(s,t,n1-1,n2-1,dp);
    }
};
