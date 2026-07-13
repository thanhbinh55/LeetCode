class Solution {
public:

    vector<int> ans;
    int h;
    int l;
    void dequy(int val, int tail){
        int new_val = val * 10 + tail;
        if(new_val >= l && new_val <= h) ans.push_back(new_val);; 
        
        if(tail == 9) return;
        dequy(new_val, tail+1);
    }

    vector<int> sequentialDigits(int low, int high) {
        h = high;
        l = low;
        for(int i = 1; i <= 8; i++){
            dequy(i,i+1);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};