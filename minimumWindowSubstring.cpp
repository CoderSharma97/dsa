class Solution {
public:
    string minWindow(string s, string t) {
        int count = 0;
        unordered_map<char,int>mp;

        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        int j=0;
        int ans = INT_MAX;
        int index = -1;

        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0)count++;
            mp[s[i]]--;

            while(count==t.size()){
                if(ans >i-j+1){
                    ans = i-j+1;
                    index = j;
                }
                mp[s[j]]++;
                if(mp[s[j]] >0)count--;
                j++;
            }
        }
        return index !=-1 ? s.substr(index,ans):"";
    }

};
