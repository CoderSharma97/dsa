class Solution {
  public:
    int lowerBound(vector<int>&nums,int x){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int ans = -1;
        
        while(start<=end){
            int mid = (start+end)/2;
            
            if(nums[mid] <=x){
                ans = mid;
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans+1;
    }
    
    int helper(vector<vector<int>>&nums,int x){
        
        int count = 0;
        for(int i=0;i<nums.size();i++){
            
            count+=(lowerBound(nums[i],x));
        }
        return count;
        
    }
    int median(vector<vector<int>> &nums) {
        // code here
        int m = nums.size();
        int n = nums[0].size();
        
        int end = INT_MIN;
        int start = INT_MAX;
        int ans = -1;
        int req = (m*n+1)/2;
        
        for(int i=0;i<m;i++){
            start = min(start,nums[i][0]);
            end = max(end,nums[i][n-1]);
        }
        
        while(start<=end){
            int mid = (start+end)/2;
            
            int count = helper(nums,mid);
            if(count >=req){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            
        }
        return ans;
        
        
    }
};
