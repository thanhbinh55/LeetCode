class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // xoa it nhat -> Tim nhieu nhat cac cuoc hop khong trung nhau
        // Y tuong la sort theo giờ kết thúc
        // Tao mot bien end giu End hien tai, K giu so toi da giu lai
        // So sanh start với end hiên tại
        // can bo toi thieu = n - giu toi da

        int k = 0;
        int end = INT_MIN;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });

        for(int i = 0; i< intervals.size(); i++){
            if(intervals[i][0] >= end){
                k++;
                end = intervals[i][1];
            }
        }
        return intervals.size() - k;
    }
};