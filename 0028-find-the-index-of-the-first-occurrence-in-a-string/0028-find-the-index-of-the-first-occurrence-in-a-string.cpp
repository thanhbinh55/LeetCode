class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_len = needle.length();
        int haystack_len = haystack.length();
        for(int i = 0; i <= haystack_len - needle_len; i++){
            std::string haystack_sub = haystack.substr(i, needle_len);
            if(haystack_sub == needle){
                std::cout<<i;
                return i;
            }
        }
        return -1;
    }
};