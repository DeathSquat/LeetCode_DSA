#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    // price[shop, movie]
    unordered_map<long long, int> price;
    // unrented[movie] = set of {price, shop}
    unordered_map<int, set<pair<int,int>>> unrented;
    // rented movies = set of {price, shop, movie}
    set<tuple<int,int,int>> rented;

    long long key(int shop, int movie) {
        return ((long long)shop << 32) | movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            price[key(shop, movie)] = p;
            unrented[movie].insert({p, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int cnt = 0;
        for (auto &[p, s] : unrented[movie]) {
            res.push_back(s);
            if (++cnt == 5) break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int p = price[key(shop, movie)];
        unrented[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = price[key(shop, movie)];
        rented.erase({p, shop, movie});
        unrented[movie].insert({p, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &[p, s, m] : rented) {
            res.push_back({s, m});
            if (++cnt == 5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
