class FoodRatings {
public:
    // Map food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;

    // Map cuisine -> ordered set of { -rating, food }
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = foodInfo[food];
        // Remove old rating entry
        cuisineFoods[cuisine].erase({-oldRating, food});
        // Insert new rating entry
        cuisineFoods[cuisine].insert({-newRating, food});
        // Update food rating
        oldRating = newRating;
    }
    
    string highestRated(string cuisine) {
        // First element in set has highest rating (because we store -rating)
        return cuisineFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
