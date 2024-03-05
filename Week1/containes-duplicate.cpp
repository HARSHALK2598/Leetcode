class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> umap;
        bool ans = false;
        for (int i = 0; i < nums.size(); i++){
            if (umap.find(nums[i]) != umap.end()) {
                ans = true;x
                break;
            }
            umap.insert(nums[i]);
        }
        return ans;
    }
};
