class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=max(rec1[0],rec2[0]);
        int x2=min(rec2[2],rec1[2]);
        int y1=max(rec1[1],rec2[1]);
        int y2=min(rec2[3],rec1[3]);
        if(x1<x2 && y1<y2)return 1;
        return 0;
    }
};