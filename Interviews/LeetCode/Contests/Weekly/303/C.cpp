class FoodRatings {
public:
    map<string, set<int>> highestRatedCuisineFood;
    map<pair<string, int>, set<string>> bestFoodForThisRating;
    map<string, int> currentFoodRating;
    map<string, string> cuisineForThisFood;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            currentFoodRating[foods[i]] = ratings[i];
            cuisineForThisFood[foods[i]] = cuisines[i];
            highestRatedCuisineFood[cuisines[i]].insert(ratings[i]);
            bestFoodForThisRating[ {cuisines[i], ratings[i]}].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        int prevRatingOfFood = currentFoodRating[food];
        string findCuisine = cuisineForThisFood[food];
        bestFoodForThisRating[ {findCuisine, prevRatingOfFood}].erase(food);
        if (bestFoodForThisRating[ {findCuisine, prevRatingOfFood}].size() == 0) {
            highestRatedCuisineFood[findCuisine].erase(prevRatingOfFood);
        }
        currentFoodRating[food] = newRating;
        highestRatedCuisineFood[findCuisine].insert(newRating);
        bestFoodForThisRating[ {findCuisine, newRating}].insert(food);
    }

    string highestRated(string cuisine) {
        int highestRating = *highestRatedCuisineFood[cuisine].rbegin();
        return *bestFoodForThisRating[ {cuisine, highestRating}].begin();
    }
};