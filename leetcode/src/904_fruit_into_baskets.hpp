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
            if (active_fruit_types[1] == -1) {
                active_fruit_types[1] = current_fruit_type;
                counter++;
                uniform_for_npos++;
            }
            else if (current_fruit_type == active_fruit_types[1]) {
                uniform_for_npos++;
                counter++;
            }
            else if (active_fruit_types[0] == -1) {
                active_fruit_types[0] = active_fruit_types[1];
                active_fruit_types[1] = current_fruit_type;
                counter++;
                uniform_for_npos = 1;
            }
            else if (current_fruit_type == active_fruit_types[0]) {
                active_fruit_types[0] = active_fruit_types[1];
                active_fruit_types[1] = current_fruit_type;
                uniform_for_npos = 1;
                counter++;
            }
            else {
                max_fruit = std::max(max_fruit, counter);
                active_fruit_types[0] = active_fruit_types[1];
                active_fruit_types[1] = current_fruit_type;
                counter = uniform_for_npos + 1;
                uniform_for_npos = 1;
            }
        }

        max_fruit = std::max(max_fruit, counter);

        return max_fruit;
    }
};
