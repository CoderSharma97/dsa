class Solution {
public:
     class DisjoinSet{
        
        vector<int>parent;
        vector<int>size;
        public:
        
        DisjoinSet(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        
        int findU(int u){
            
            if(parent[u]==u){
                return u;
            }
            
            return parent[u]=findU(parent[u]);
        }
        
        void unionBySize(int u,int v){
            int ul_u=findU(u);
            int ul_v=findU(v);
            
            if(ul_u==ul_v)return;
            
            if(size[ul_u] <size[ul_v]){
                parent[ul_v]=parent[ul_u];
                size[ul_u]+=size[ul_v];
            }
            else{
                parent[ul_u]=parent[ul_v];
                size[ul_v]+=size[ul_u];
            }
        }
    };
    int makeConnected(int n, vector<vector<int>>& edges) {
       DisjoinSet d(n);
       int count =0;

       for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(d.findU(u) != d.findU(v)){
                d.unionBySize(u,v);
            }
            else{
                count++;
            }
       }
       int components=0;

       for(int i=0;i<n;i++){
            if(d.findU(i)==i){
                components++;
            }
       }
       if(count<components-1 )return -1;

       return components-1;
    }
};
