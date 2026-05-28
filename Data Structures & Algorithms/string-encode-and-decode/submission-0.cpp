class Solution {
public:

    // ENCODE function: Convert list of strings to a single string
    string encode(vector<string>& strs) {
        string temp = "";
        for (auto str : strs) {
            int length = str.size();
            temp += to_string(length);
            temp += '#'; // delimiter
            temp += str;
        }
        return temp;
    }

    // DECODE function: Convert encoded string back to list of strings
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            string length = "";

            // Read length of next word until you hit '#'
            while (s[i] != '#') {
                length += s[i];
                i++;
            }
            i++;  // skip '#'
            int len = stoi(length);  // convert length to integer

            // Extract the actual word
            string word = s.substr(i, len);
            res.push_back(word);
            i += len;
        }
        return res;
    }
};
