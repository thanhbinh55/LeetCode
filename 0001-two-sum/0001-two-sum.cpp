class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<pair<int, int>> b;
        for(int i = 0; i < nums.size(); i++){
            b.push_back({nums[i], i});
        }
        sort(b.begin(), b.end());

        for(int i = 0; i < nums.size(); i++){
            int need = target - b[i].first;

            auto l = lower_bound(
                b.begin(),
                b.end(),
                make_pair(need, -1)
            );

            for(auto p = l; p != b.end() && p->first == need; p++){
                if(p->second != b[i].second){
                     ans.push_back(b[i].second);
                    ans.push_back(p->second);
                    break;
                }
            }
            if (!ans.empty()){ break;}
        } 

        return ans;
    }
};