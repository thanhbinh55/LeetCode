class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        if (n < 3) return n;
        while(n > 0){
            count++;
            n /=2;
        }
        return pow(2,count);
    }
};