class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int cur_depth = 0;
        

        for(char c: s){
            if(c == '('){
                cur_depth++;
                max_depth = max(max_depth, cur_depth);
            }else if(c == ')'){
                cur_depth--;
            }
        }
        return max_depth;
    }
};