/*
From an interview, was asked to count the number of distinct pairs of nums in a which summed to k.
*/

#include <unordered_map>
#include <vector>

using namespace std;

int numberOfPairs(vector<int> a, long k) {
    std::unordered_map<long, int> seen_elems;
    int distinct_pairs = 0;

    for (auto num : a) {
        std::cout << "num = " << num << std::endl;
        seen_elems[num]++;

        std::cout << "seen_elems[num] = " << seen_elems[num] << std::endl;
        std::cout << "seen_elems[k - num] = " << seen_elems[k - num] << std::endl;

        if (num == k - num) {
            if (seen_elems[num] == 2) { distinct_pairs++; }
        }
        else if (seen_elems[num] == 1 && seen_elems[k - num] > 0) {
            distinct_pairs++;
        }

        std::cout << "distinct_pairs = " << distinct_pairs << std::endl;
    }

    return distinct_pairs;
}