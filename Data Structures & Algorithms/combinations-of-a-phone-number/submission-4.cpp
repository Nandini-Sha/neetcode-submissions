class Solution {
    unordered_map<int, vector<char>> mp = {
        {2, {'a','b','c'}},
        {3, {'d','e','f'}},
        {4, {'g','h','i'}},
        {5, {'j','k','l'}},
        {6, {'m','n','o'}},
        {7, {'p','q','r','s'}},
        {8, {'t','u','v'}},
        {9, {'w','x','y','z'}}
    };

    vector<string> ans;

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string temp;
        backtrack(digits, temp, 0);
        return ans;
    }

    void backtrack(string& digits, string& temp, int i) {
        if (i == digits.size()) {
            ans.push_back(temp);
            return;
        }

        for (char c : mp[digits[i] - '0']) {
            temp.push_back(c);
            backtrack(digits, temp, i + 1);
            temp.pop_back();
        }
    }
};