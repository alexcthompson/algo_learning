#pragma once

#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

const double epsilon = 0.0000000001;

vector<double> make_forest_angles(vector<vector<double>> forest) {
    // creates a vector of all the angles of trees that are not at (0,0)
    // and for every tree at (0,0), since it can be seen from all angles, increments base_count
    vector<double> forest_angles;

    for (auto tree : forest) {
        forest_angles.push_back(atan2(tree[1], tree[0]));
    }

    std::sort(forest_angles.begin(), forest_angles.end());

    return forest_angles;
}

double optimal_angle(const vector<double>& angles, const double& alpha) {
    // record the position of the max_count of visible trees so far,
    // and the angle that yielded that count

    int max_count = 0;            // max count for window so far
    double max_left_angle = angles[0]; // angle of that max count window
    int left = 0;                 // index of the left edge of the window of trees
    int current_count = 0;        // current count of visible trees

    for (int i = 0; i < angles.size(); i++) {
        // find count of visible trees w/ left viewing edge set to angles[i]
        current_count = std::max(current_count - 1, 0);

        // test other trees for visibilty
        while (left < angles.size() &&
               angles[left] <= angles[i] + alpha + epsilon) {
            left++;
            current_count++;
        }

        while (angles[left % angles.size()] < angles[i] &&
               angles[left % angles.size()] + 2 * M_PI - angles[i] <= alpha + epsilon) {
            left++;
            current_count++;
        }

        if (current_count > max_count) {
            max_count = current_count;
            max_left_angle = angles[i];
        }

    }

    // add 0.5 * alpha and wrap
    return fmod(max_left_angle + 0.5 * alpha + M_PI, 2 * M_PI) - M_PI;
}
