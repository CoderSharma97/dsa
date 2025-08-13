class Solution {
public:
    void solve(vector<int>&nums,int index,vector<int>current,vector<vector<int>>&ans){

        ans.push_back(current);
        int n = nums.size();
        for(int i=index;i<n;i++){
            if(i>index && nums[i]== nums[i-1])continue;

            current.push_back(nums[i]);
            solve(nums,i+1,current,ans);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) { 
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>current;
        sort(nums.begin(),nums.end());
        solve(nums,0,current,ans);
        return ans;
    }
};
