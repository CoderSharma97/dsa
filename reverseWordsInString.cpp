class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>temp;
        string word;
        string ans;

        while(ss>>word){
            temp.push_back(word);
        }

        for(int i=temp.size()-1;i>=0;i--){
            ans+=temp[i];
            if(i>0)ans+=" ";
        }
        return ans;
    }

};
