class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string ans;
        vector<pair<int,char>>temp;
        

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        for(auto it : mp){
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end());

        for(int i=temp.size()-1;i>=0;i--){
            string t(temp[i].first,temp[i].second);
            ans+=t;
        }
        return ans;
    }
};
