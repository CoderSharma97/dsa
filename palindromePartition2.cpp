class Solution {
public:
    bool isPalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start] != s[end]){
                return 0;
            }
                start++;
                end--;
        }
        return 1;
    }
    int solve(string &s,int index,vector<int>&dp){

        if(index ==s.size())return 0;
        if(dp[index] != -1)return dp[index];
        int ans = INT_MAX;
        for(int i=index;i<s.size();i++){
            if(isPalindrome(s,index,i)){
                int res = solve(s,i+1,dp)+1;
                ans = min(res,ans);
            }
        }
        return dp[index]= ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return solve(s,0,dp)-1;
    }
};
