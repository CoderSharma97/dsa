class Solution {
public:
    int ncr(int n,int r){
        double ans =1;
        for(int i=0;i<r;i++){
            ans *=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                temp.push_back(ncr(i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
