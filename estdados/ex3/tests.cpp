#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "ex3.cpp"
#include <algorithm> 
#include <stdlib.h>

std::vector<int> create_vec(int ll ){
    std::vector<int> a;
    a.reserve(ll);
    for (int i=0; i<ll; i++){
        a[i] = rand();
    }
    return a;
}

TEST_CASE( "shell_sort()", "[listas]" ) {
    int qte = 15;
    int len = 10000;
    for(int i=0; i<qte; i++){
        std::vector<int> a = create_vec(len);
        std::vector<int> b(a);
        std::sort (b.begin(), b.end());  
        REQUIRE( shell_sort(a) == b);
    }
}
