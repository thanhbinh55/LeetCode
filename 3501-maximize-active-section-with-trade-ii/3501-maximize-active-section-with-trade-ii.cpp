class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length(), total_1s = 0;
        vector<int> S, E, L;
        
        // Tiền xử lý các cụm '0'
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                total_1s++;
                i++;
            } else {
                int j = i;
                while (j < n && s[j] == '0') j++;
                S.push_back(i);
                E.push_back(j - 1);
                L.push_back(j - i);
                i = j;
            }
        }
        
        int m = S.size();
        int log = 0;
        while ((1 << log) <= m) log++;
        vector<vector<int>> st(max(1, m), vector<int>(max(1, log), 0));
        
        // Khởi tạo Sparse Table tính tổng max của 2 cụm '0' kề nhau
        for (int i = 0; i < m - 1; ++i) {
            st[i][0] = L[i] + L[i+1];
        }
        for (int j = 1; j < log; ++j) {
            for (int i = 0; i + (1 << j) <= m - 1; ++i) {
                st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
        
        auto query_st = [&](int l, int r) {
            if (l > r) return 0;
            int j = 31 - __builtin_clz(r - l + 1);
            return max(st[l][j], st[r - (1 << j) + 1][j]);
        };
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            auto it1 = lower_bound(E.begin(), E.end(), l);
            auto it2 = upper_bound(S.begin(), S.end(), r);
            
            // Nếu không có mảng '0' nào trong đoạn
            if (it1 == E.end() || it2 == S.begin()) {
                ans.push_back(total_1s);
                continue;
            }
            
            int x = distance(E.begin(), it1);
            int y = distance(S.begin(), it2) - 1;
            
            // Cần ít nhất 2 mảng '0' để trade (ngăn cách bởi '1')
            if (x >= y) {
                ans.push_back(total_1s);
            } else if (y == x + 1) { // Chỉ có đúng 2 mảng '0' kề nhau
                int gain = (E[x] - max(S[x], l) + 1) + (min(E[y], r) - S[y] + 1);
                ans.push_back(total_1s + gain);
            } else {                 // Có từ 3 mảng '0' trở lên
                int gain = (E[x] - max(S[x], l) + 1) + L[x+1]; // Ghép cụm đầu
                gain = max(gain, L[y-1] + (min(E[y], r) - S[y] + 1)); // Ghép cụm cuối
                gain = max(gain, query_st(x + 1, y - 2)); // Chèn các cụm hoàn toàn ở giữa
                ans.push_back(total_1s + gain);
            }
        }
        return ans;
    }
};