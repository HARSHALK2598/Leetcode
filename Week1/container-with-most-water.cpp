// Problem link: https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1, maxArea = -1, currArea = -1;
        while(start < end){
            currArea = min(height[start], height[end]) * (end - start);
            maxArea = currArea > maxArea ? currArea : maxArea;
            if (height[start] < height[end]) start += 1;
            else end -= 1;
        }
        return maxArea;
    }
};
