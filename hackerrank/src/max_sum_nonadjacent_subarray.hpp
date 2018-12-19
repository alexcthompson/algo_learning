/*
Max sum of non-adjacent subarray, HackerRank problem found here:
https://www.hackerrank.com/challenges/max-array-sum/problem?

See the Jupyter notebook `max_sum_nonadjacent_subarray.ipynb` for an explanation
of this solution.
*/

#include <algorithm>

int maxSubsetSum(std::vector<int> arr) {
    if (arr.size() == 1) return arr[0];
    else if (arr.size() == 2) return std::max(arr[0], arr[1]);

    std::vector<int> subres = {arr[0], std::max(arr[0], arr[1])};

    for (int i = 2; i < arr.size(); i++) {
        int new_subres = std::max({arr[i], arr[i] + subres[i-2], subres[i-1]});
        subres.push_back(new_subres);
    }

    return subres.back();
}