// Approach:
// 1. Use an unordered set to track available ingredients and supplies.
// 2. Use a boolean array to mark recipes as cooked.
// 3. Iterate through recipes and check if all required ingredients are available.
// 4. If a recipe can be made, add it to the supplies set and mark it as cooked.
// 5. Repeat the process until no more recipes can be made.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        vector<string> result;
        unordered_set<string> st(supplies.begin(), supplies.end());  
        vector<bool> cooked(n, false);
        int cnt = n;
        while(cnt--) {
            for (int i = 0; i < n; i++) {
                if (cooked[i])
                    continue;
                bool canmake = true;
                for (int j = 0; j < ingredients[i].size(); j++) {
                    if (st.find(ingredients[i][j]) == st.end()) {
                        canmake = false;
                        break;
                    }
                }
                if (canmake) {
                    st.insert(recipes[i]);
                    result.push_back(recipes[i]);
                    cooked[i] = true;
                }
            }
        }
        return result;
    }
};
