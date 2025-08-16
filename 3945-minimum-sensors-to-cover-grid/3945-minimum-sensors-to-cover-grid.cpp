class Solution {
public:
    int minSensors(int n, int m, int k) {
        int s=(2*k)+1;
        int row = ceil((double)n / s);
        int col = ceil((double)m / s);
        return row*col;
        
    }
};