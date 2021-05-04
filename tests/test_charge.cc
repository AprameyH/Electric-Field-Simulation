#include <charge.h>
#include <catch2/catch.hpp>

TEST_CASE("Test IsPositive") {
    SECTION("Positive value") {
        Charge charge(glm::vec2(100, 100), 34);
        REQUIRE(charge.is_positive() == true);
    }

    SECTION("Negative value") {
        Charge charge(glm::vec2(100, 100), -771);
        REQUIRE(charge.is_positive() == false);
    }

    SECTION("0") {
        Charge charge(glm::vec2(100, 100), 0);
        REQUIRE(charge.is_positive() == true);
    }
}