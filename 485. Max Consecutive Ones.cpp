class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 1)count++;
            else count =0;
            ans = max(count,ans);
        }
        return ans;
    }
};
