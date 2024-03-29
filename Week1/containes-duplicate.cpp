// problem link: https://leetcode.com/problems/contains-duplicate/description/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> umap;
        bool ans = false;
        for (int i = 0; i < nums.size(); i++){
            if (umap.find(nums[i]) != umap.end()) {
                ans = true;
                break;
            }
            umap.insert(nums[i]);
        }
        return ans;
    }
};
