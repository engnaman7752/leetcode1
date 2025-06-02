class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> indegree(n, 0);
        vector<int> candies(n, 1);
        queue<int> q;

        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ratings[i] > ratings[i - 1]) indegree[i]++;
            if (i < n - 1 && ratings[i] > ratings[i + 1]) indegree[i]++;
        }

        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0) q.push(i);

        while (!q.empty()) {
            int i = q.front(); q.pop();
        
            if (i > 0 && ratings[i] < ratings[i - 1]) {
                if (candies[i - 1] < candies[i] + 1) {
                    candies[i - 1] = candies[i] + 1;
                    q.push(i - 1);
                }
            }
            
            if (i < n - 1 && ratings[i] < ratings[i + 1]) {
                if (candies[i + 1] < candies[i] + 1) {
                    candies[i + 1] = candies[i] + 1;
                    q.push(i + 1);
                }
            }
        }

    int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=candies[i];
        }
        return sum;    }
};
