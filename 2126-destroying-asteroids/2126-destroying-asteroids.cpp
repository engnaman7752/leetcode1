class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int i=0;
        int n=asteroids.size();
        int maxx=*max_element(asteroids.begin(),asteroids.end());
        while(i<n){
            if(mass>=maxx)return true;
            if(mass>=asteroids[i]){
                mass+=asteroids[i];
                i++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};