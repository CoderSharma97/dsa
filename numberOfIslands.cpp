void bfs(vector<vector<char>>& board, vector<vector<int>>&visited,int row,int col){
     
        queue<pair<int,int>>q;
          int m = board.size();
        int n = board[0].size();

        q.push({row,col});
        visited[row][col]=1;
        while(!q.empty()){
            int i = q.front().first;
            int j =q.front().second;
            q.pop();

            if(i+1<m && board[i+1][j] =='1' && !visited[i+1][j]){
                q.push({i+1,j});
               
                visited[i+1][j]=1;
            }
            if(j+1<n && board[i][j+1] =='1' && !visited[i][j+1]){
                q.push({i,j+1});
              
                visited[i][j+1]=1;
            }
            if(i-1>=0 && board[i-1][j] =='1' && !visited[i-1][j]){
                q.push({i-1,j});
               
                visited[i-1][j]=1;
            }
            if(j-1>=0 && board[i][j-1] =='1' && !visited[i][j-1]){
                q.push({i,j-1});
                visited[i][j-1]=1;
            }
        }

        
    }
