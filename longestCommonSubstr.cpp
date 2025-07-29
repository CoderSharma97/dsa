class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n1 = s1.size();
        int n2=s2.size();
        int ans = 0;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=0;
                }
                ans = max(dp[i][j],ans);
            }
        }
        
        return ans;
    }
};
