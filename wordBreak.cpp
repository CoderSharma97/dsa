class Solution {
public:
    bool solve(unordered_map<string,int>&mp,string &s,int index,vector<int>&dp){

        
        
        if(index == s.size())return 1;

        if(dp[index] != -1)return dp[index];
        for(int i=index;i<s.size();i++){
            if(mp.find(s.substr(index,i-index+1)) != mp.end()){
                bool ans = solve(mp,s,i+1,dp);
                if(ans)return ans;
            }
        }
        return dp[index]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;

        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }
        vector<int>dp(s.size(),-1);
        return solve(mp,s,0,dp);

    }
};
