// Problem link: https://leetcode.com/problems/video-stitching/
class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        if (a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        if (clips.size() == 1){
            if (clips[0][0] == 0 && clips[0][1] >= time) return 1;
            else return -1;
        }
        sort(clips.begin(), clips.end(), compare);
        if (clips[0][0] != 0) return -1;
        int totalClips = 1;
        int prevInd = 0, currInd = 1, nextInd = currInd;
        while(clips[currInd][0] == 0 && currInd < clips.size()){ currInd += 1;}
        nextInd = prevInd = currInd - 1;
        if (clips[prevInd][1] >= time) return totalClips;
        while(currInd < clips.size()){ 
            
            if (clips[prevInd][1] < clips[currInd][0] ){
                prevInd = nextInd;
                totalClips += 1;    
            }
            if (clips[currInd][0] <= clips[prevInd][1] && clips[currInd][1] > clips[prevInd][1] && clips[currInd][1] > clips[nextInd][1]){
                nextInd = currInd;
                if (clips[nextInd][1] >= time) return totalClips+1;
            }
            
            currInd += 1;
        }
        if ( nextInd != prevInd){
            prevInd = nextInd;
            totalClips += 1;
        }
        if (clips[prevInd][1] < time) return -1;
        return totalClips;
    }
};
