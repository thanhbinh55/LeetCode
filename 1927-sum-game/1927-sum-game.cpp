class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int mid = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < mid)
                    leftQ++;
                else
                    rightQ++;
            } else {
                if (i < mid)
                    leftSum += num[i] - '0';
                else
                    rightSum += num[i] - '0';
            }
        }

        // Tổng số ? là lẻ → Alice đi cuối
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        int diff = leftSum - rightSum;
        int q = leftQ - rightQ;

        return diff != -9 * q / 2;
    }
};