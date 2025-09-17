class FoodRatings {
public:
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if(a.first != b.first) return a.first < b.first;   // higher rating first
            return a.second > b.second;                       // lexicographically smaller first
        }
    };

    // food -> {cuisine, rating}
    unordered_map<string, pair<string,int>> foodInfo;

    // cuisine -> max heap of (rating, food)
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, cmp>> cuisineHeaps;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineHeaps[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto &[cuisine, rating] = foodInfo[food];
        rating = newRating;
        cuisineHeaps[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto &pq = cuisineHeaps[cuisine];
        while(true){
            auto [r,f] = pq.top();
            auto [c,actualRating] = foodInfo[f];
            if(actualRating == r) return f;   // valid top
            pq.pop(); // outdated entry
        }
    }
};
