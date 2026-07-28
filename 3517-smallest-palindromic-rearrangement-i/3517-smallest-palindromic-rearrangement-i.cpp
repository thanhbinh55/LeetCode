class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26,0);
        for(auto c : s){ // dem so lan xuat hien cua moi ky tu
            cnt[c - 'a'] ++;
        }
        
        vector<int> left(26,0);
        int middle = -1;
        for(int i = 0; i < 26; i++){
            if(cnt[i] % 2 == 1){
                middle = i; 
            }
            left[i] = cnt[i]/2;
        }

        string res = "";
        for(int i = 0; i < 26; i++){
            while(left[i] > 0){
                res += i + 'a';
                left[i] --;
            }
        }
        string tmp = res;
        reverse(tmp.begin(), tmp.end());
        if(middle != -1){
            res += middle + 'a';
        }
        res += tmp;
        return res;
    }
};