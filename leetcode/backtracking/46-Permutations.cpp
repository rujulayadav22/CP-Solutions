class Solution {
public:
    void solve(int index,vector<vector<int>>&res,vector<int>&path,vector<int>& nums,vector<int>&visited){
        if(index==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                path.push_back(nums[i]);
                solve(index+1,res,path,nums,visited);
                path.pop_back();
                visited[i]=0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>path;
        vector<int> visited(nums.size(), 0);
        solve(0,res,path,nums,visited);
        return res;
    }
};