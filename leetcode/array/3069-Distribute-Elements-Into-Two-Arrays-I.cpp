class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> a(n);
        vector<int> b(n);

        int x = 0;
        int y = 0;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                a[x++] = nums[i];
            }
            else if (i == 1) {
                b[y++] = nums[i];
            }
            else {
                if (a[x - 1] > b[y - 1]) {
                    a[x++] = nums[i];
                }
                else {
                    b[y++] = nums[i];
                }
            }
        }

        for (int i = 0; i < y; i++) {
            a[x++] = b[i];
        }

        a.resize(x);
        return a;
    }
};