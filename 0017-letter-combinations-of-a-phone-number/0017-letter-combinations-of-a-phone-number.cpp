class Solution {
public:
    vector<string> result;
        vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int index, string& path) {
        // TH da chon du chua cai
        if (index == digits.size()){
            result.push_back(path);
            return;
        }

        // Lay chu cai tuong ung chu so hien tai
        string letters = mp[digits[index] - '0'];

        for(char c: letters){
            path.push_back(c); // Chon chu cai
            backtrack(digits, index + 1, path); // De quy
            path.pop_back(); // Quay lui
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string path = "";
        backtrack(digits,0,path);
        return result;
    }
};