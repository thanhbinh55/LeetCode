class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // giá trị sau >= giá trị trước
        // Muc tiêu return dp[i] là độ dài lớn nhất của dãy không giảm
        // ý tưởng:
        // - định nghĩa dp[i]là độ dài lớn nhất của dãy không giảm tính đến a[i]
        // - hàm: duyệt j < i, nếu aj <= ai thì độ dài lớn nhất tại j dp[j] = max (dp[j] + 1, dp[i]) // j ngay truoc i
        // base case: độ dài lớn nhất không giảm tại mỗi điểm ban đầu là 1
        int n = obstacles.size();
        vector<int> ans(n);
        vector<int> tail;

        for(int i = 0; i < n; i++){
            int x = obstacles[i];

            auto it = upper_bound(tail.begin(), tail.end(), x);
            int idx = it - tail.begin();

            if(it == tail.end()){ // Khong co so nao lon hon x -> x la lon hon cac gia tri truoc do -> them vao day thoa dk
                tail.push_back(x);
            }else{ // co gia tri tai vi tri idx > x, nhung tai do lai co chung do dai -> thay bang x de toi uu sau nay
                tail[idx] = x;
            }
            ans[i] = idx + 1;
        }

        return ans;
    }
};