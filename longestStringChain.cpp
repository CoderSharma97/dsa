class Solution {
public:
    static bool compare(string &x,string &y){
        return x.size()<y.size();
    }
    bool isPossible(string s1,string s2){
        if(s2.size()-s1.size() !=1)return 0;

        int count =0;
        int i=0;
        int j=0;

        while(i<s1.size() && j<s2.size()){
            if(s1[i] != s2[j]){
                j++;
                count++;
            }
            else{
                i++;
                j++;
            }
            
        }
        return count<=1;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n = words.size();
        vector<int>dp(n,1);
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPossible(words[j],words[i]) && dp[j]+1 > dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
