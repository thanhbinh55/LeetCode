class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26,0);
        for(auto c : s){ // dem so lan xuat hien cua moi ky tu
            cnt[c - 'a'] ++;
        }
        int middle = -1;
        string left = "";
        for(int i = 0; i < 26; i++){
            if(cnt[i] % 2 == 1) {
                middle = i;
            }
            left += string(cnt[i]/2, 'a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        string res = "";
        res += left;

        if(middle != -1){
            res += middle + 'a';
        }
        res += right;
        return res;
    }
};