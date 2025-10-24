// 001-TestCase.cpp
// And write tests in the same file:
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "../point.hpp"

TEST_CASE("Point: Konstruktoren") {
    SECTION("Init mit Werten") {
        Point p{2, 3};
        REQUIRE(p.m_x == 2);
        REQUIRE(p.m_y == 3);
    }
    SECTION("Default-Konstruktor") {
        Point p;
        REQUIRE(p.m_x == 0);
        REQUIRE(p.m_y == 0);
    }
}

TEST_CASE("Point: move verschiebt relativ") {
    Point p{1, 1};
    p.move(2, -3);
    REQUIRE(p.m_x == 3);
    REQUIRE(p.m_y == -2);
}

TEST_CASE("Point: distance_to – euklidisch & robust") {
    Point a{0, 0};
    Point b{3, 4};
    REQUIRE( a.distance_to(b) == Catch::Approx(5.0).margin(1e-12) );
    REQUIRE( b.distance_to(a) == Catch::Approx(5.0).margin(1e-12) );
    REQUIRE( a.distance_to(a) == Catch::Approx(0.0).margin(1e-12) );
}


TEST_CASE("Point: Große/negative Koordinaten") {
    Point p1{-1000, -1000};
    Point p2{1000, 1000};
    REQUIRE( p1.distance_to(p2) == Catch::Approx(2828.4271247461903).margin(1e-10) );
}

TEST_CASE("Point: Stabilität bei vielen aufeinanderfolgenden move-Aufrufen") {
    Point p{0, 0};
    for (int i = 0; i < 1000000; ++i) {
        p.move(1, 1);
    }
    REQUIRE(p.m_x == 1000000);
    REQUIRE(p.m_y == 1000000);
}

TEST_CASE("Point: Dreiecksgleichung der Abstände") {
    Point p1{0, 0};
    Point p2{3, 0};
    Point p3{0, 4};
    double d12 = p1.distance_to(p2);
    double d23 = p2.distance_to(p3);
    double d31 = p3.distance_to(p1);
    REQUIRE( d12 + d23 >= d31 - 1e-12 );
    REQUIRE( d23 + d31 >= d12 - 1e-12 );
    REQUIRE( d31 + d12 >= d23 - 1e-12 );
}

// Compile & run:
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success
// - cl -EHsc -I%CATCH_SINGLE_INCLUDE% 010-TestCase.cpp && 010-TestCase --success

// Expected compact output (all assertions):
//
// prompt> 010-TestCase --reporter compact --success
// 010-TestCase.cpp:14: failed: Factorial(0) == 1 for: 0 == 1
// 010-TestCase.cpp:18: passed: Factorial(1) == 1 for: 1 == 1
// 010-TestCase.cpp:19: passed: Factorial(2) == 2 for: 2 == 2
// 010-TestCase.cpp:20: passed: Factorial(3) == 6 for: 6 == 6
// 010-TestCase.cpp:21: passed: Factorial(10) == 3628800 for: 3628800 (0x375f00) == 3628800 (0x375f00)
// Failed 1 test case, failed 1 assertion.