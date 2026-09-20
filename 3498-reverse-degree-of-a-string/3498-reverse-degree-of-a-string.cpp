class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            int c = 26 - (s[i] - 'a') ;
            sum += c * (i + 1);
        }
        return sum;
    }
};