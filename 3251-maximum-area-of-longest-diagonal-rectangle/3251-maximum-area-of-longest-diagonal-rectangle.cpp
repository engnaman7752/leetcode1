class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area=-1;
        double dig=0;
        for(int i=0;i<dimensions.size();i++){
            double x=sqrt((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]));
            if(x>=dig)
            {
                if(x==dig)
                area=max(area,dimensions[i][0]*dimensions[i][1]);
                else
               { area=dimensions[i][0]*dimensions[i][1];
                dig=x;}
            }
        }
        return area;
    }
};