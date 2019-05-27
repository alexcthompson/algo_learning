#pragma once

#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;  // leave this in even though Ben would scold me!

// TODO
// redo wrapping, test wrapping
// make sure you handle endpoint copies correctly
// count trees at 0,0 as base rate
// Note, atan2 ranges from (-pi, pi]

const double epsilon = 0.0000000001;

vector<double> make_forest_angles(vector<vector<double>> forest, int& base_count) {
    // creates a vector of all the angles of trees that are not at (0,0)
    // and for every tree at (0,0), since it can be seen from all angles, increments base_count
    vector<double> forest_angles;

    for (auto tree : forest) {
        if (tree[0] == 0 && tree[1] == 0) {
            base_count++;
        }
        else {
            forest_angles.push_back(atan2(tree[1], tree[0]));
        }
    }

    std::sort(forest_angles.begin(), forest_angles.end());

    return forest_angles;
}


vector<double> make_offset_angles(vector<double> angles, const double& alpha) {
    vector<double> offset_angles;

    // angles on the right edge of range that need to be compared w/ angles on left edge
    for (auto angle : angles) {
        if (angle >= M_PI - 0.5 * alpha) {
            offset_angles.push_back(angle + 0.5 * alpha - 2 * M_PI);
        }
    }

    for (auto angle : angles) {
        offset_angles.push_back(angle + 0.5 * alpha);
    }

    // angles on the left edge of range that need to be compared w/ angles on right edge
    for (auto angle : angles) {
        if (angle <= -M_PI + 0.5 * alpha) {
            offset_angles.push_back(angle + 0.5 * alpha + 2 * M_PI);
        }
    }

    return offset_angles;
}


double optimal_angle(const vector<double>& angles, const vector<double>& offset_angles,
    const double& alpha) {
    // record the position of the max_count of visible trees so far,
    // and the angle that yielded that count
    std::cout << "epsilon = " << epsilon << std::endl << std::endl;

    int max_count = 0;
    double max_angle = angles[0];

    // left and right edges of the window of trees currently under consideration
    int left = 0, right = 0;

    // current count of visible trees
    int current_count = 0;

    for (auto angle : angles) {
        // computes count of visible trees for current angle, and updates max_count if warranted
        // could be up to N steps but amortize across all trees is O(n)
        while (left < offset_angles.size() && offset_angles[left] < angle - epsilon) {
            left++;
            current_count = std::max(current_count - 1, 0);
        }

        while (right < offset_angles.size() && offset_angles[right] < angle - epsilon) {
            right++;
        }

        while (right < offset_angles.size() && offset_angles[right] <= angle + alpha + epsilon) {
            right++;
            current_count++;
        }

        if (current_count > max_count) {
            max_count = current_count;
            max_angle = angle;
        }
        std::cout << "angle: " << angle << "; count: " << current_count
                  << "; last offset angle added: " << offset_angles[right - 1] << ".\n";
    }

    return max_angle;
}

// double optimal_angle(std::vector<std::vector<double>> forest, double alpha) {
//   // call tree_angle on each element of the *forest* and return
//   // list of angles
//   vector<double> angles;

//   for (auto tree : forest) {
//     angles.push_back(atan2(tree[1], tree[0]));
//   }

//   std::sort(angles.begin(), angles.end());

//   vector<double> angles_plus;

//   for (auto tree : angles) {
//     double new_angle = (tree + alpha / 2 + M_PI % (2 * M_PI)) - M_PI
//     angles_plus.push_back(new_angle);
//   }

//   std::map<double, int> counts; // count of visible trees from an angle

//   int i = 0;
//   int j = 0;

//   while (i < angles.size()) {
//     double difference = angles_plus(j) - angles(i);

//     if (difference < alpha) {
//       counts[i] += 1;
//       j++;
//     }
//     else {
//       i++;
//     }


//   }

//   return -999;
// }

// int main() {
// 	cout<<"Hello";
// 	return 0;
// }