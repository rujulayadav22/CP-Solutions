class Solution {
public:
    void findCombination(int index, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < arr.size(); i++) {

            if (i > index && arr[i] == arr[i - 1])
                continue;

            if (arr[i] > target)
                break;

            ds.push_back(arr[i]);

            findCombination(i + 1, target - arr[i],
                            arr, ans, ds);

            ds.pop_back();
        }
    }

    // GFG expects this exact name
    vector<vector<int>> uniqueCombinations(vector<int>& arr, int sum) {

        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(0, sum, arr, ans, ds);

        return ans;
    }
};