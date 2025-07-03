class Solution {
  public:
    int solve(string &s,int k){
        int left = 0;
        int ans = 0;
        unordered_map<char,int>mp;
        
        for(int right = 0;right<s.size();right++){
            mp[s[right]]++;
            
            while(mp.size() >k){
                mp[s[left]]--;
                if(mp[s[left]]==0)mp.erase(s[left]);
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here.
        
        return solve(s,k)-solve(s,k-1);   
    }
};
