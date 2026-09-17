class Solution {
public:
    void findcombination(int index, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {

        if (index == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[index] <= target) {
            ds.push_back(arr[index]);

            findcombination(index, target - arr[index], arr, ans, ds);

            ds.pop_back();
        }

        findcombination(index + 1, target, arr, ans, ds);
    }

    vector<vector<int>> targetSumComb(vector<int>& arr, int sum) {
        vector<vector<int>> ans;
        vector<int> ds;

        findcombination(0, sum, arr, ans, ds);

        return ans;
    }
};