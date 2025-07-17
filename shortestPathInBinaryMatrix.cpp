class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n = grid[0].size();

        vector<vector<int>>distance(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        if(grid[0][0]==1)return -1;
        q.push({0,0});
        distance[0][0]=0;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row==m-1 && col==n-1){
                return distance[n-1][n-1]+1;
            }

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int newRow = row+i;
                    int newCol = col+j;
                    

                    if(newRow >=0 && newRow <m && newCol <n && newCol>=0 && grid[newRow][newCol]==0){
                        if(distance[newRow][newCol] > distance[row][col]+1){
                            distance[newRow][newCol]=distance[row][col]+1;
                            q.push({newRow,newCol});
                        }
                    }
                }
            }
        }
        return -1;

    }
};
