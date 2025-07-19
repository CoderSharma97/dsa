// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        int INF = 1e9;

        // Step 1: Replace -1 with INF for calculation
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] == -1 && i != j)
                    dist[i][j] = INF;
            }
        }

        // Step 2: Standard Floyd-Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 3: Convert INF back to -1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][j] >= INF)
                    dist[i][j] = -1;
            }
        }
    }
};
