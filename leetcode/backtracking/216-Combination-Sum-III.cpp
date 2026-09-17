class Solution {
public:
    void findcombination (int index,int k,int n, vector<vector<int>>& ans,vector<int>& ds){
        if(k==0){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }
        for(int i=index;i<=9;i++){
           if(i>n)break;
           ds.push_back(i);
           findcombination(i+1,k-1,n-i,ans,ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(1,k,n,ans,ds);
        return ans;
    }
};