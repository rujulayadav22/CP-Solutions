class Solution {
public:
    void findCombination(int index, vector<int>& arr,vector<vector<int>>& ans, vector<int>& ds) {

        ans.push_back(ds);

        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1])
                continue;

            ds.push_back(arr[i]);

            findCombination(i + 1, arr, ans, ds);

            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, nums, ans, ds);

        return ans;
    }
};