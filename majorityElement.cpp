class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = -1;
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n;i++){
            if(count==0){
                x = nums[i];
                count=1;
            }
            else if(nums[i] != x){
                count--;
            }
            else{
                count++;
            }
        }
        return x;
    }
};
