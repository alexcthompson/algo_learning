/*
Solution for LeetCode #904 'Fruit Into Baskets'
https://leetcode.com/problems/fruit-into-baskets/
*/
#include <vector>

class Solution {
private:
    int max_fruit = 0;
    int counter = 0;
    int uniform_for_npos = 0;
    int active_fruit_types [2] = {-1, -1};

public:
    void reset_solution() {
        max_fruit = 0;
        counter = 0;
        uniform_for_npos = 0;
        active_fruit_types[0] = -1;
        active_fruit_types[1] = -1;
    }
    int totalFruit(std::vector<int>& tree) {
        for (auto current_fruit_type : tree) {
            if (current_fruit_type != active_fruit_types[1]) {
                if (current_fruit_type != active_fruit_types[0]) {
                    max_fruit = std::max(max_fruit, counter);
                    counter = uniform_for_npos;
                }

                uniform_for_npos = 0;
                active_fruit_types[0] = active_fruit_types[1];
                active_fruit_types[1] = current_fruit_type;
            }

            uniform_for_npos++;
            counter++;
        }

        max_fruit = std::max(max_fruit, counter);

        return max_fruit;
    }
};
