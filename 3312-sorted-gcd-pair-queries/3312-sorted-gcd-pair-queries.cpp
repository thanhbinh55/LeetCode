class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums) freq[x]++;

        
        vector<long long> multiple(mx + 1);

        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g)
                multiple[g] += freq[j];
        }

        
        vector<long long> exact(mx + 1);

        for (int g = mx; g >= 1; g--) {
            long long m = multiple[g];
            exact[g] = m * (m - 1) / 2;

            for (int j = g + g; j <= mx; j += g)
                exact[g] -= exact[j];
        }

        // prefix
        vector<long long> pref(mx + 1);

        for (int g = 1; g <= mx; g++)
            pref[g] = pref[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};