class Solution {
public:
    void solve(string s,int target,int index,string path,long long sum,long long prev,vector<string>&ans){

        if(sum== target && index == s.size()){
            ans.push_back(path);
            return;
        }
        long long num = 0;
        string numString ="";
        for(int i=index;i<s.size();i++){
            if(i>index && s[index]=='0')return;
            int x = s[i]-'0';
            num = num*10+x;
            numString +=s[i];
            
            if(index==0)
            solve(s,target,i+1,numString,num,num,ans);
            else{
                solve(s,target,i+1,path+'+'+numString,sum+num,num,ans);
                solve(s,target,i+1,path+'-'+numString,sum-num,-num,ans);
                solve(s,target,i+1,path+'*'+numString,sum-prev+num*prev,num*prev,ans);
            }
        }
    }
    vector<string> addOperators(string s, int target) {
     vector<string>ans;
     solve(s,target,0,"",0,0,ans);
     return ans;   
    }
};
