class MovieRentingSystem {
private:
    // movie -> {price, shop}
    map<int, set<pair<int,int>>> available;
    // {price, shop, movie} for all rented movies
    set<tuple<int,int,int>> rented;
    // {shop, movie} -> price
    map<pair<int,int>, int> priceOf;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceOf[{shop, movie}] = price;
            available[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        auto it = available.find(movie);
        if (it == available.end()) return res;
        int cnt = 0;
        for (auto &p : it->second) {
            res.push_back(p.second);
            if (++cnt == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceOf[{shop, movie}];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceOf[{shop, movie}];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &t : rented) {
            res.push_back({get<1>(t), get<2>(t)});
            if (++cnt == 5) break;
        }
        return res;
    }
};