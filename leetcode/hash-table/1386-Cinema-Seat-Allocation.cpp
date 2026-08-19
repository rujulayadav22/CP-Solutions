class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int l = 0, r = 0, prev = 0;
        int sz = reservedSeats.size();

        sort(reservedSeats.begin(), reservedSeats.end());

        bool isReserved[11] = {};
        int ans = 0;

        while (r < sz) {
            ans += 2 * (reservedSeats[r][0] - prev - 1);
            prev = reservedSeats[r][0];

            while (r < sz && reservedSeats[l][0] == reservedSeats[r][0]) {
                isReserved[reservedSeats[r][1]] = true;
                r++;
            }

            bool twoToFive = check(isReserved, 2, 5);
            bool fourToSeven = check(isReserved, 4, 7);
            bool sixToNine = check(isReserved, 6, 9);

            if (twoToFive && sixToNine)
                ans += 2;
            else if (twoToFive || fourToSeven || sixToNine)
                ans++;

            l = r;

            fill(isReserved, isReserved + 11, false);
        }

        ans += 2 * (n - prev);

        return ans;
    }

    bool check(bool b[], int l, int r) {
        for (int i = l; i <= r; i++) {
            if (b[i])
                return false;
        }
        return true;
    }
};