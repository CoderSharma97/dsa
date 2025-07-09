class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int ans = 0;
        priority_queue<int>pq;

        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }


        for(auto it : mp){
            pq.push(it.second);
        }

        while(!pq.empty()){

            int count =0;
            vector<int>temp;

            while(count<n+1 && !pq.empty()){
                temp.push_back(pq.top()-1);
                pq.pop();
                count++;
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i] >0){
                    pq.push(temp[i]);
                }
            }
            if(pq.size()>0){
                ans+=(n+1);
            }
            else{
                ans+=(count);
            }
        }
        return ans;
    }
};
