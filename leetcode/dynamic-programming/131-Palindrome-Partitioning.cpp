class Solution {
public:
    void funct (int index,string s, vector<vector<string>>&res,vector<string>&path){
        if(index==s.size()){
            res.push_back(path);
            return;
        }

        for(int i=index;i<s.size();i++){
            if(isPanlindrome(index,i,s)){
            path.push_back(s.substr(index,i-index+1));
            funct(i + 1, s, res, path);
            path.pop_back();
            }
        }
    }

    bool isPanlindrome(int start,int end,string s){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        funct(0,s,res,path);
        return res;
    }
};