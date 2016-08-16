#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../catch.hpp"
#include "ex2.cpp"

std::vector<std::vector<int>> bagunca = {{0, 1, -2, 3, -4},
                                        {10, 0, 6, 3},
                                        {-1, -10, -1, 7, 1, 1}};

std::vector<std::vector<int>> ordem =  {{-4, -2, 0, 1, 3},
                                        {0, 3, 6, 10},
                                        {-10, -1, -1, 1, 1, 7}};

TEST_CASE( "bubble_sort()", "[listas]" ) {
    REQUIRE( bubble_sort(bagunca[0]) == ordem[0]);
    REQUIRE( bubble_sort(bagunca[1]) == ordem[1]);
    REQUIRE( bubble_sort(bagunca[2]) == ordem[2]);
}

TEST_CASE( "quick_sort()", "[listas]" ) {
    REQUIRE( quick_sort(bagunca[0]) == ordem[0]);
    REQUIRE( quick_sort(bagunca[1]) == ordem[1]);
    REQUIRE( quick_sort(bagunca[2]) == ordem[2]);
}

TEST_CASE( "selection_sort()", "[listas]" ) {
    REQUIRE( selection_sort(bagunca[0]) == ordem[0]);
    REQUIRE( selection_sort(bagunca[1]) == ordem[1]);
    REQUIRE( selection_sort(bagunca[2]) == ordem[2]);
}
