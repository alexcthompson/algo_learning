/*
A super quick implementation to count the # of elements w/ count >= 2.
Done under time pressure.
*/

#include <unordered_map>
#include <vector>

using std::vector;

int countDuplicates(vector<int> numbers) {
    std::unordered_map<int,int> elem_counts;
    int dup_count = 0;

    for (auto num : numbers) {
        if (elem_counts[num] == 1) {
            dup_count++;
        }

        elem_counts[num]++;
    }

    return dup_count;
}
