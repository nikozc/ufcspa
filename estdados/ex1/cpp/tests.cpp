#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include "ex1.cpp"

std::vector<std::vector<int>> listas = {{0, 1, -2, 3, -4},
                                        {0, 0, 0, 0},
                                        {-1, -1, -1, -1, -1, -1}};

TEST_CASE( "contaElementosNegativos()", "[listas]" ) {
    REQUIRE( contaElementosNegativos(listas[0]) == 2 );
    REQUIRE( contaElementosNegativos(listas[1]) == 0 );
    REQUIRE( contaElementosNegativos(listas[2]) == 6 );
}

TEST_CASE( "contaOcorrenciasValor()", "[listas]" ) {
    REQUIRE( contaOcorrenciasValor(listas[0], -2) == 1 );
    REQUIRE( contaOcorrenciasValor(listas[1], 0) == 4 );
    REQUIRE( contaOcorrenciasValor(listas[2], -1) == 6 );
}

TEST_CASE( "temElementosDistintos()", "[listas]" ) {
    REQUIRE( temElementosDistintos(listas[0]) == true );
    REQUIRE( temElementosDistintos(listas[1]) == false );
    REQUIRE( temElementosDistintos(listas[2]) == false );
}

TEST_CASE( "retornaPosicaoMaiorElemento()", "[listas]" ) {
    REQUIRE( retornaPosicaoMaiorElemento(listas[0]) == 3 );
    REQUIRE( retornaPosicaoMaiorElemento(listas[1]) == 0 );
    REQUIRE( retornaPosicaoMaiorElemento(listas[2]) == 0 );
}
