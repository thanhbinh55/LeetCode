class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        vector<vector<int>> merged;
        
        merged.push_back(intervals[0]);

        int n = intervals.size();
        for(int i = 1; i < n; i++){
            vector<int>& current = intervals[i];
            vector<int>& last_merged = merged[merged.size() - 1];

            if(current[0] <= last_merged[1]){
                last_merged[1] = max(last_merged[1], current[1]);
            }else{
                merged.push_back(current);
            }
        }
        return merged;
    }
};
