class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (auto &c : s) {
            freq[c]++;
        }

        vector<pair<char, int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans = "";

        for (auto &e : v) {
            while (e.second > 0) {
                ans += e.first;
                e.second--;
            }
        }

        return ans;
    }
};