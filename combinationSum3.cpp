class Solution {
public:
    void solve(int k,int n,vector<int>current,vector<vector<int>>&ans,int index){
        if(k==0 && n==0){
            ans.push_back(current);
            return;
        }

        for(int i=index;i<=9;i++){
            if(n-i>=0){
                current.push_back(i);
                solve(k-1,n-i,current,ans,i+1);
                current.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        solve(k,n,{},ans,1);
        return ans;
    }
};
