class cmp {
public:
    bool operator()(const pair<int,string> &a,const pair<int,string> &b) const {
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
};

class FoodRatings {
public:
    
    unordered_map<string,string> food_cuisines;
    unordered_map<string,int> ratings_map;
    unordered_map<string,set<pair<int,string>,cmp>> data;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            data[cuisines[i]].insert({ratings[i],foods[i]});
            food_cuisines[foods[i]]=cuisines[i];
            ratings_map[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        data[food_cuisines[food]].erase({ratings_map[food],food});
        data[food_cuisines[food]].insert({newRating,food});
        ratings_map[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        return data[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */