class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       // b1: tạo mảng prefix -> Chứa max từ 0 -> i
       // pre[i] = max(pre[i-1], pre[i]);
       // prefixGcd = gcd(nums[i], pre[i]);
       // sort -> non-decrease
       // loop in prefixgcd
       // if n odd -> vector.remove [mid];
       // gcdArr.push_back(gcd(prefixGcd[i], prefixGcd[n - i - 1]))
       // return sum(gcdArr)
       vector<int> prefixGcd(nums.size());
       prefixGcd[0] = nums[0];
       vector<int> mxi(nums.size());
       mxi[0] = nums[0];
       for(int i = 1; i < nums.size(); i++){
        mxi[i] = max(nums[i], mxi[i -1]);
       }
       for(int i = 1; i < nums.size(); i++){
        prefixGcd[i] = gcd(nums[i], mxi[i]);
       }
       sort(prefixGcd.begin(), prefixGcd.end());
       long long ans = 0;
       for(int i = 0; i < (prefixGcd.size()/2); i++){
            ans += gcd(prefixGcd[i], prefixGcd[prefixGcd.size() - i - 1]);
       }
       return ans;
    }
};