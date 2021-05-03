#include <electric_field.h>
#include <catch2/catch.hpp>
#include <arrow.h>

TEST_CASE("Calculate Field Direction For A Single Positive Charge") {
    //Setting charge
    std::vector<Charge> charges;
    Charge charge_one(glm::vec2(430, 470), 1);
    charges.push_back(charge_one);

    SECTION("Arrow northwest of charge") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(200, 150));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-33777.9844, -46995.457));
    }

    SECTION("Arrow northeast of charge") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(600, 200));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(47042.4922, -74714.5468));
    }

    SECTION("Arrow southwest of charge") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(150, 500));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-112696.719, 12074.6484));
    }

    SECTION("Arrow southeast of charge") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(500, 600));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(195468.328, 363012.625));
    }
}

TEST_CASE("Calculate Field Direction For A Single Negative Charge") {
    //Setting charge
    std::vector<Charge> charges;
    Charge charge_one(glm::vec2(430, 470), -1);
    charges.push_back(charge_one);

    SECTION("Arrow northwest of charge") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(200, 150));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(33777.9844, 46995.457));
    }

    SECTION("Arrow northeast of charge") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(600, 200));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-47042.4922, 74714.5468));
    }

    SECTION("Arrow southwest of charge") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(150, 500));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(112696.719, -12074.6484));
    }

    SECTION("Arrow southeast of charge") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(500, 600));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-195468.328, -363012.625));
    }
}

TEST_CASE("Calculate Field Direction for two charges") {
    std::vector<Charge> charges;
    Charge charge_one(glm::vec2(430, 470), -1);
    charges.push_back(charge_one);
    Charge charge_two(glm::vec2(600, 600), -1);\
    charges.push_back(charge_two);

    SECTION("Arrow top left") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(200, 150));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(50250.543, 65527.0859));
    }

    SECTION("Arrow top right") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(600, 200));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-47042.4922, 130889.547));
    }

    SECTION("Arrow bottom left") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(150, 500));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(153985.984, -2899.25635));
    }

    SECTION("Arrow bottom right") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(500, 600));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(703331.688, -363012.625));
    }
}

TEST_CASE("Calculate Field Direction for positive and negative charge") {
    std::vector<Charge> charges;
    Charge charge_one(glm::vec2(430, 470), 1);
    charges.push_back(charge_one);
    Charge charge_two(glm::vec2(600, 600), -1);
    charges.push_back(charge_two);

    SECTION("Arrow top left") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(200, 150));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-17305.4258, -28463.8262));
    }

    SECTION("Arrow top right") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(600, 200));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(47042.4922, -18539.5449));
    }

    SECTION("Arrow bottom left") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(150, 500));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-71407.4531, 21250.041));
    }

    SECTION("Arrow bottom right") {
        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(500, 600));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(1094268.38, 363012.625));
    }
}

TEST_CASE("Field for different charge values") {
    std::vector<Charge> charges;

    SECTION("Large positive charges") {
        Charge charge_one(glm::vec2(430, 470), 90);
        charges.push_back(charge_one);
        Charge charge_two(glm::vec2(600, 600), 80);
        charges.push_back(charge_two);

        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(200, 150));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-4357823, -5712121.5));
    }

    SECTION("Small positive charges") {
        Charge charge_one(glm::vec2(430, 470), 8 * pow(10, -6));
        charges.push_back(charge_one);
        Charge charge_two(glm::vec2(600, 600), 4 * pow(10, -6));
        charges.push_back(charge_two);

        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(200, 150));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-0.336114109, -0.45009017));
    }

    SECTION("Large negative charges") {
        Charge charge_one(glm::vec2(430, 470), -60);
        charges.push_back(charge_one);
        Charge charge_two(glm::vec2(600, 600), -80);
        charges.push_back(charge_two);

        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(600, 700));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-3918621.25, -77205664));
    }

    SECTION("Small negative charges") {
        Charge charge_one(glm::vec2(430, 470), -8 * pow(10, -6));
        charges.push_back(charge_one);
        Charge charge_two(glm::vec2(600, 600), -4 * pow(10, -6));
        charges.push_back(charge_two);

        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(600, 700));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-0.522482812, -4.30208874));
    }

    SECTION("Large positive and negative charges") {
        Charge charge_one(glm::vec2(430, 470), 90);
        charges.push_back(charge_one);
        Charge charge_two(glm::vec2(600, 600), 80);
        charges.push_back(charge_two);
        Charge charge_three(glm::vec2(200,200), -80);
        charges.push_back(charge_two);

        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(100, 800));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-7230449.5, 4467917.5));
    }

    SECTION("Small positive and negative charges") {
        Charge charge_one(glm::vec2(430, 470), 7 * pow(10, -6));
        charges.push_back(charge_one);
        Charge charge_two(glm::vec2(600, 600), 2 * pow(10, -6));
        charges.push_back(charge_two);
        Charge charge_three(glm::vec2(200, 200), -4 * pow(10, -6));
        charges.push_back(charge_two);

        std::vector<Arrow> arrows;
        Arrow arrow(glm::vec2(100, 800));
        arrows.push_back(arrow);

        chargefield::ElectricField field(arrows, charges);

        glm::vec2 direction = field.CalculateFieldDirection(arrow.get_position());
        REQUIRE(direction == glm::vec2(-0.319367796, 0.25030449));
    }
}

TEST_CASE("Find Direction") {
    std::vector<Charge> charges;
    Charge charge_one(glm::vec2(430, 470), -1);
    charges.push_back(charge_one);
    Charge charge_two(glm::vec2(600, 600), -1);
    charges.push_back(charge_two);

    std::vector<Arrow> arrows;
    Arrow arrow(glm::vec2(600, 200));
    arrows.push_back(arrow);

    chargefield::ElectricField field(arrows, charges);
    SECTION("Field pointing southwest") {

        glm::vec2 end_point = field.FindDirection(glm::vec2(-5000, -8000), glm::vec2(150, 200));
        REQUIRE(end_point == glm::vec2(-4850, -7800));
    }

    SECTION("Field pointing southeast") {

        glm::vec2 end_point = field.FindDirection(glm::vec2(4000, -6000), glm::vec2(150, 200));
        REQUIRE(end_point == glm::vec2(4150, -5800));
    }

    SECTION("Field pointing northwest") {

        glm::vec2 end_point = field.FindDirection(glm::vec2(-5000, 3000), glm::vec2(150, 200));
        REQUIRE(end_point == glm::vec2(-4850, 3200));
    }

    SECTION("Field pointing northeast") {

        glm::vec2 end_point = field.FindDirection(glm::vec2(9000, 2000), glm::vec2(150, 200));
        REQUIRE(end_point == glm::vec2(9150, 2200));
    }
}

TEST_CASE("Calculate magnitude") {
    std::vector<Charge> charges;
    std::vector<Arrow> arrows;

    chargefield::ElectricField electric_field(arrows, charges);
    SECTION("Positive values") {
        glm::vec2 field{500, 100};
        REQUIRE( electric_field.CalculateMagnitude(field) == Approx(509.9019));
    }

    SECTION("Negative values") {
        glm::vec2 field{-200, -350};
        REQUIRE( electric_field.CalculateMagnitude(field) == Approx(403.113));
    }

    SECTION("Positive and negative component") {
        glm::vec2 field{2784, -1955};
        REQUIRE( electric_field.CalculateMagnitude(field) == Approx(3401.864));
    }
}
