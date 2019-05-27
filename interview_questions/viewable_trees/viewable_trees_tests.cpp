#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "viewable_trees.hpp"

void test_vector_equality(std::vector<double> first, std::vector<double> second) {
    REQUIRE ( first.size() == second.size() );

    for (int i = 0; i < first.size(); i++) {
        CHECK ( first[i] == Approx(second[i]) );
    }
}

TEST_CASE("test cases") {

    std::vector<std::vector<double>> forest = {{1,1}, {1,2}, {-2,1}, {-2,-1}, {1,0}, {2,-1}};
    double alpha = 0.5 * M_PI;

    SECTION("tests") {
        std::vector<double> angles = make_forest_angles(forest);
        std::vector<double> angles_res =
            {-2.6779450446, -0.463647609, 0.0, 0.7853981634, 1.1071487178, 2.6779450446};

        // Arggh! Approx check for vectors is an open PR in Catch2!  Get er done, people.
        test_vector_equality(angles, angles_res);

        CHECK ( optimal_angle(angles, alpha) == Approx(0.3217505544) );

        angles = {0.0, 0.1, 0.2, 0.3, 1.75, 1.76, 1.77, 1.78, 1.79};
        CHECK ( optimal_angle(angles, alpha) == Approx(1.0853981634) );
    }
}