#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;  // fruit type -> count
        int maxFruits = 0;
        int start = 0;

        for (int end = 0; end < fruits.size(); ++end) {
            basket[fruits[end]]++;

            // If more than 2 types of fruits, shrink window from the start
            while (basket.size() > 2) {
                basket[fruits[start]]--;
                if (basket[fruits[start]] == 0) {
                    basket.erase(fruits[start]);
                }
                start++;
            }

            maxFruits = max(maxFruits, end - start + 1);
        }

        return maxFruits;
    }
};
