class Solution {
public:
    int maxDepth(string s) {
        int count =0;
        int ans = -1;

        for(int i=0;i<s.size();i++){
            if(s[i] =='(')count++;
            ans=max(count,ans);
            if(s[i]==')')count--;
        }
        return ans;
    }
};
