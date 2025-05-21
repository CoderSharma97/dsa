class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>temp;

        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(),temp.end());

        int start = 0;
        int end = n-1;

        while(start<end){

            if(temp[start].first+temp[end].first == target){
                return {temp[start].second,temp[end].second};
            }
            else if(temp[start].first+temp[end].first < target){
                start++;
            }
            else{
                end--;
            }
        }
        
        return {-1,-1};
    }
};
