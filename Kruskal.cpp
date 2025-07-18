// User function Template for C++
class disjointSet{
    private:
    vector<int>parent;
    vector<int>size;
    public:
    
    disjointSet(int n){
        size.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int findU(int x){
        if(x==parent[x]){
            return  x;
        }
        return parent[x]=findU(parent[x]);
    }
    
    void unionBySize(int u,int v){
        int u_u = findU(u);
        int u_v = findU(v);
        
        if(size[u_u] >size[u_v]){
            parent[u_v]=parent[u_u];
            size[u_u]+=size[u_v];
        }
        else{
            parent[u_u]=parent[u_v];
            size[u_v]+=size[u_u];
        }
    }
};
class Solution {
  public:
    static bool compare(vector<int>&x,vector<int>&y){
        return x[2]<y[2];
    }
    int kruskalsMST(int v, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),compare);
        disjointSet d(v);
        
        int ans = 0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt=edges[i][2];
            
            if(d.findU(u) != d.findU(v)){
                d.unionBySize(u,v);
                ans+=wt;
            }
        }
        
        return ans;
    }
};
