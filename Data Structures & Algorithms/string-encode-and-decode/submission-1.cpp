class Solution {
public:

    string encode(vector<string>& strs) {
        string temp = "";
        for (auto str : strs) {
            int length = str.size();
            temp += to_string(length);
            temp += '#'; 
            temp += str;
        }
        return temp;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            string length = "";

            while (s[i] != '#') {
                length += s[i];
                i++;
            }
            i++; 
            int len = stoi(length); 

            string word = s.substr(i, len);
            res.push_back(word);
            i += len;
        }
        return res;
    }
};
