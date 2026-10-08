class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // ý tưởng: 
        // fi là số cách tạo nên giá tổng tiền i
        // Đây là tổ hợp, 1-2 và 2-1 là tính một 
        // Duyệt qua từng đồng xu c-> cố định thứ tự duyệt mệnh giá , không bị lấy lại, tránh trùng lặp
        // Với mỗi đồng xu tính cách tạo nên giá tiền i với đồng xu đó
        // fi = fi + f(i - c) -> fi = tổng số cách tạo fi trước đó + số cách tạo nếu thêm c

        vector<unsigned int> dp(amount + 1, 0); // index từ 1 -> số cách tạo ban đầu là 0
        dp[0] = 1; // số cách tạo tổng không là 1 cách <=> Không chọn gì cả

        for(int c : coins){
            for(int i = c; i <= amount; i++){
                dp[i] = dp[i] + dp[i - c];
            }
        }
        return dp[amount];
    }
};