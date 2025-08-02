class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double ans = INT_MIN;
        double sum = 0;

       for(int i=0;i<k;i++){
            sum+=nums[i];
       }
        ans = sum;
       for(int i=k;i<n;i++){
            sum+=(nums[i]-nums[i-k]);
            if(ans <sum){
                ans = sum;
            }
       }

        return ans/(double)k;
    }
};
