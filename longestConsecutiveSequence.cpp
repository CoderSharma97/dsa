class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans = 0;

        for(auto it : st){
            if(st.find(it-1) ==st.end()){
                int x = it;
                int count = 0;
                while(st.find(x) != st.end()){
                    count++;
                    x++;
                }
                ans = max(count,ans);
            }
        }
        return ans;
    }
};
