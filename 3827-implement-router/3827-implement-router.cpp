#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ordered_set of (timestamp, uid)
typedef tree<pair<int,int>, null_type, less<pair<int,int>>,
             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Router {
public:
    queue<tuple<int,int,int,int>> q;
    set<tuple<int,int,int>> st;                   
    unordered_map<int, ordered_set> mp;        
    map<tuple<int,int,int>, int> packetUid;      
    int limit;
    int uidCounter = 0;

    Router(int memoryLimit) : limit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        if (limit == 0) return false; 

        auto packet = make_tuple(source, destination, timestamp);
        if (st.find(packet) != st.end()) return false; 

        if ((int)st.size() == limit) {
            auto old = q.front(); q.pop();
            int osrc = get<0>(old), odst = get<1>(old), otime = get<2>(old), ouid = get<3>(old);
            st.erase(make_tuple(osrc, odst, otime));
            auto it = mp.find(odst);
            if (it != mp.end()) it->second.erase({otime, ouid});
            packetUid.erase(make_tuple(osrc, odst, otime));
        }

        int uid = ++uidCounter;
        q.emplace(source, destination, timestamp, uid);
        st.insert(packet);
        mp[destination].insert({timestamp, uid});
        packetUid[packet] = uid;
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto tp = q.front(); q.pop();
        int a = get<0>(tp), b = get<1>(tp), c = get<2>(tp), u = get<3>(tp);
        st.erase(make_tuple(a,b,c));
        auto it = mp.find(b);
        if (it != mp.end()) it->second.erase({c,u});
        packetUid.erase(make_tuple(a,b,c));
        return {a,b,c};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = mp.find(destination);
        if (it == mp.end()) return 0;
        ordered_set &os = it->second;
        int left = os.order_of_key({startTime, numeric_limits<int>::min()});
        int right = os.order_of_key({endTime, numeric_limits<int>::max()});
        return right - left;
    }
};
