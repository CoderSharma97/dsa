

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& nums) {
        // Code here
        int maxi = INT_MIN;
        int n = nums.size();
        vector<int>ans;
        
        for(int i = n-1;i>=0;i--){
            if(nums[i] >= maxi){
                maxi = nums[i];
                ans.push_back(maxi);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
