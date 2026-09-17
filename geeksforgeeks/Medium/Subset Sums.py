class Solution {
  public:
    void funct(int index,int sum,vector<int>& arr,vector<int>&ans){
        if(index==arr.size()){
            ans.push_back(sum);
            return;
        }
        funct(index+1,sum+arr[index],arr,ans);
        funct(index+1,sum,arr,ans);
    }
  
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>ans;
        funct(0,0,arr,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};