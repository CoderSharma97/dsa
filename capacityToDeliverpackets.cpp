class Solution {
public:
    bool isValid(vector<int>&nums,int mid,int days){

        int count = 1;
        int wt = 0;

        for(int i=0;i<nums.size();i++){

            if(nums[i]+wt <=mid){
                wt+=nums[i];
            }
            else{
                wt = nums[i];
                count++;
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        
        int start = 0;
        int end   = 0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            end+=nums[i];
            start = max(start,nums[i]);
        }

        while(start<=end){
            int mid = (start+end)/2;

            if(isValid(nums,mid,days)){
                end = mid-1;
                ans = mid;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};
