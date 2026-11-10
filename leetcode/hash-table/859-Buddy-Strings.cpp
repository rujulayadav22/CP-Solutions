class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        bool has2 = false;
        unordered_map<char,int> mpp;

        for(auto c : s){
            mpp[c]++;
            if(mpp[c]>=2) has2 = true;
        }

        if(has2==true && s==goal) return true;

        int cnt = 0;
        int first = -1;
        int second = -1;

        for(int i = 0;i<s.size();i++){
            if(s[i]!=goal[i]){
                cnt++;

                if(first==-1) first = i;
                else if(second==-1) second = i;
                else return false;
            }
        }

        if(cnt!=2) return false;

        return s[first]==goal[second] && goal[first]==s[second];
    }
};