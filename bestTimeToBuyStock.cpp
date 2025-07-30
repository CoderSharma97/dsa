class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int last = nums[0];

        int n = nums.size();
        int maxi = 0;

        for(int i=1;i<n;i++){
            if(nums[i] - last > maxi){
                maxi = nums[i]-last;
            }
            last = min(last,nums[i]);
        }

        return maxi;
    }
};
