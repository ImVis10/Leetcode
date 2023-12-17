class FoodRatings {
    unordered_map<string, pair<string , int>> foodToCusineAndRatings;
    // unordered_map<string, string> foodToCuisine;
    unordered_map<string, set<pair<int, string>>> highestRatedFood;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCusineAndRatings[foods[i]] = {cuisines[i], ratings[i]};
            // foodToCuisine[foods[i]] = cuisines[i];
            highestRatedFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        // update foodRatings map
        int oldRating = foodToCusineAndRatings[food].second;
        foodToCusineAndRatings[food].second = newRating; 
        
        // find the cuisine for the food so that we can update the ratings in highestRatedFood
        string cuisine = foodToCusineAndRatings[food].first;

        // update the highestRatedFood with the newRating for the cuisine, food combination
        highestRatedFood[cuisine].erase({-oldRating, food});
        highestRatedFood[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return highestRatedFood[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */