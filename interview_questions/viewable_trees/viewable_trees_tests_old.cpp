#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch2/catch.hpp"
#include "viewable_trees.hpp"

template <typename T>
std::ostream& operator << (std::ostream& stream, const std::vector<T>& v) {
    stream << "Vector( ";

    for (auto it = v.cbegin(); it != v.cend(); it++) {
        stream << *it;

        if (it + 1 != v.cend()) {
            stream << ", ";
        }
        else {
            stream << ")";
        }
    }

    return stream;
}

void test_vector_equality(std::vector<double> first, std::vector<double> second) {
    REQUIRE ( first.size() == second.size() );

    for (int i = 0; i < first.size(); i++) {
        CHECK ( first[i] == Approx(second[i]) );
    }
}


TEST_CASE("test cases") {

    std::vector<std::vector<double>> forest = {{1,1}, {1,2}, {-2,1}, {-2,-1}, {1,0}, {2,-1}, {0,0}};
    double alpha = 0.5 * M_PI;

    SECTION("data processing") {
        int base_count = 0;

        // TEST: make_forest_angles
        std::vector<double> angles = make_forest_angles(forest, base_count);
        std::vector<double> angles_res =
            {-2.6779450446, -0.463647609, 0.0, 0.7853981634, 1.1071487178, 2.6779450446};
        int base_count_res = 1;

        // Arggh! Approx check for vectors is an open PR in Catch2!  Get er done, people.
        test_vector_equality(angles, angles_res);
        CHECK ( base_count == base_count_res );

        // TEST: make_offset_angles
        std::vector<double> offset_angles = make_offset_angles(angles, alpha);
        std::vector<double> offset_angles_res =
            {-2.8198420992, -1.8925468812, 0.3217505544, 0.7853981634,
            1.5707963268, 1.8925468812, 3.463343208, 4.390638426};

        test_vector_equality(offset_angles, offset_angles_res);
    }

    SECTION("best angle computations") {
        int base_count = 0;
        std::vector<double> angles = make_forest_angles(forest, base_count);
        std::vector<double> offset_angles = make_offset_angles(angles, alpha);

        CHECK ( optimal_angle(angles, offset_angles, alpha) == 0.4 );
    }
}