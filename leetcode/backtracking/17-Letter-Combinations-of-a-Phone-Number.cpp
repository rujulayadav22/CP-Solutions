class Solution {
public:
    void findCombination(int index, string& digits,
                          vector<string>& ans, string& ds) {

        if (index == digits.size()) {
            ans.push_back(ds);
            return;
        }

        string letters;

        if (digits[index] == '2')
            letters = "abc";
        else if (digits[index] == '3')
            letters = "def";
        else if (digits[index] == '4')
            letters = "ghi";
        else if (digits[index] == '5')
            letters = "jkl";
        else if (digits[index] == '6')
            letters = "mno";
        else if (digits[index] == '7')
            letters = "pqrs";
        else if (digits[index] == '8')
            letters = "tuv";
        else if (digits[index] == '9')
            letters = "wxyz";

        for (int i = 0; i < letters.size(); i++) {

            ds.push_back(letters[i]);

            findCombination(index + 1, digits, ans, ds);

            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        string ds;

        if (digits.empty()) {
            return ans;
        }

        findCombination(0, digits, ans, ds);

        return ans;
    }
};