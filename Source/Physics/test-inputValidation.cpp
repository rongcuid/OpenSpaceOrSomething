#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "NBPhysics.hpp"

TEST_CASE("Mass validation test", "[massIsValid]") {
    REQUIRE(massIsValid(0.0) == false);
    REQUIRE(massIsValid(1.0) == true);
    REQUIRE(massIsValid(-1.0) == false);
    REQUIRE(massIsValid(NAN) == false);
    REQUIRE(massIsValid(INFINITY) == false);
    REQUIRE(massIsValid(-INFINITY) == false);
    REQUIRE(massIsValid(DBL_EPSILON) == true);
    REQUIRE(massIsValid(-DBL_EPSILON) == false);
    REQUIRE(massIsValid(DBL_MAX) == true);
    REQUIRE(massIsValid(-DBL_MAX) == false);
}