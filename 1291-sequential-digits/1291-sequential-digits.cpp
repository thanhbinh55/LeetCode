class Solution {
public:
    void dequy(int val, int tail, int low, int high, vector<int> &ans){
        int new_val = val * 10 + tail;
        if (new_val > high) return;
        if(new_val >= low) ans.push_back(new_val); 
        
        if(tail == 9) return;
        dequy(new_val, tail+1,low,high,ans);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1; i <= 8; i++){
            dequy(i,i+1,low,high,ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};