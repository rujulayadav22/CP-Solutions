class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string toGoatLatin(string s) {
        stringstream ss(s);
        string word, ans;
        string a = "a";

        while (ss >> word) {
            if (isVowel(word[0])) {
                word += "ma";
            } else {
                word = word.substr(1) + word[0] + "ma";
            }

            word += a;
            a += "a";

            ans += word + " ";
        }

        ans.pop_back(); // remove trailing space
        return ans;
    }
};