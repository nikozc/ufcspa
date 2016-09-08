#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
/* #include "../../../catch.hpp" */
#include "../catch.hpp"
#include "ex3.cpp"


TEST_CASE( "Testa repr", "[repr]" ) {
    ListaDupla l;
    No n1(1);
    No n2(2);
    No n3(3);
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    std::vector<int> v = l.get_vector_repr();
    std::vector<int> r = {1, 2, 3};
    REQUIRE( v == r);
}

TEST_CASE( "Testa append", "[append]" ) {
    ListaDupla l;
    No n1(1);
    No n2(2);
    No n3(3);
    No n4(4);
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    l.append(&n4);
    std::vector<int> v = l.get_vector_repr();
    std::vector<int> r = {1, 2, 3, 4};
    REQUIRE( v == r);
}

TEST_CASE( "Testa insert", "[insert]" ) {
    ListaDupla l;
    No n1(1);
    No n2(2);
    No n3(3);
    No n4(4);
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    l.append_pos(&n4, 1);
    std::vector<int> v = l.get_vector_repr();
    std::vector<int> r = {1, 4, 2, 3};
    REQUIRE( v == r);
}

TEST_CASE( "Testa preppend", "[preppend]" ) {
    ListaDupla l;
    No n1(1);
    No n2(2);
    No n3(3);
    No n4(4);
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    l.preppend(&n4);
    std::vector<int> v = l.get_vector_repr();
    std::vector<int> r = {4, 1, 2, 3};
    REQUIRE( v == r);
}

TEST_CASE( "Testa busca", "[busca]" ) {
    ListaDupla l;
    No n1(1);
    No n2(2);
    No n3(3);
    No n4(4);
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    l.append(&n4);
    /* Casos limites */
    No* n = l.search_by_value(1);
    REQUIRE( n == &n1);
    n = l.search_by_value(4);
    REQUIRE( n == &n4);
}

TEST_CASE( "Testa remocao", "[remocao]" ) {
    ListaDupla l;
    No n1(1);
    No n2(2);
    No n3(3);
    No n4(4);
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    l.append(&n4);
    std::vector<int> v = l.get_vector_repr();
    std::vector<int> r = {1, 2, 3, 4};
    REQUIRE( v == r);
    l.del_node(0);
    r = { 2, 3, 4 };
    v = l.get_vector_repr();
    REQUIRE( v == r);
    l.del_node(1);
    r = { 2, 3 };
    v = l.get_vector_repr();
    REQUIRE( v == r);
}
