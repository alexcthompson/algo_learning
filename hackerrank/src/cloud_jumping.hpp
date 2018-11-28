/*
HackerRank problem "Jumping on the Clouds"
https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
*/

#pragma once

#include <vector>

int jumpingOnClouds(std::vector<int> c) {
    int single_jumps_required = 0;
    int double_jumps_required = 0;
    int zeros_count = 0;

    auto it = c.cbegin();

    while (it != c.cend()) {
        if (*it == 0) zeros_count++;
        else {
            if (zeros_count % 2 == 0) single_jumps_required++;
            zeros_count = 0;
        }

        it++;
    }

    if (zeros_count % 2 == 0) single_jumps_required++;

    double_jumps_required = (c.size() - 1 - single_jumps_required) / 2;

    return single_jumps_required + double_jumps_required;
}