class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit =0;
        int mini = nums[0];
        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]-mini >profit){
                profit = nums[i]-mini;
            }
            mini = min(nums[i],mini);
        }

        return profit;
    }
};
