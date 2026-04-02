// "Copyright [2024] <Dhruv Patel>"
#define BOOST_TEST_MODULE UniverseTest
#include <fstream>
#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include "Universe.hpp"
#include "CelestialBody.hpp"

NB::Universe loadUniverseFromFile(const std::string& filePath) {
    try {
        NB::Universe universe(filePath);
        return universe;
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("Could not open the file: " + filePath);
    }
}

BOOST_AUTO_TEST_CASE(testRadius) {
    auto universe = loadUniverseFromFile("planets.txt");
    BOOST_CHECK_CLOSE(universe.radius(), 2.50e+11, 0.01);
}

BOOST_AUTO_TEST_CASE(testNumPlanets) {
    auto universe = loadUniverseFromFile("planets.txt");
    BOOST_REQUIRE_EQUAL(universe.numPlanets(), 5);
}

BOOST_AUTO_TEST_CASE(testNumPlanetsA) {
    auto universe = loadUniverseFromFile("binary.txt");
    BOOST_REQUIRE_EQUAL(universe.numPlanets(), 2);
}

BOOST_AUTO_TEST_CASE(test_universe_output) {
    std::string inputData = R"(5
2.50e+11
1.4960e+11  0.0000e+00  0.0000e+00  2.9800e+04  5.9740e+24    earth.gif
2.2790e+11  0.0000e+00  0.0000e+00  2.4100e+04  6.4190e+23     mars.gif
5.7900e+10  0.0000e+00  0.0000e+00  4.7900e+04  3.3020e+23  mercury.gif
0.0000e+00  0.0000e+00  0.0000e+00  0.0000e+00  1.9890e+30      sun.gif
1.0820e+11  0.0000e+00  0.0000e+00  3.5000e+04  4.8690e+24    venus.gif
)";
    std::istringstream iss(inputData);
    NB::Universe universe;
    iss >> universe;
    std::ostringstream oss;
    oss << universe;
    std::string expectedOutput = R"(5
2.5e+11
1.496e+11 0 0 29800 5.974e+24 earth.gif
2.279e+11 0 0 24100 6.419e+23 mars.gif
5.79e+10 0 0 47900 3.302e+23 mercury.gif
0 0 0 0 1.989e+30 sun.gif
1.082e+11 0 0 35000 4.869e+24 venus.gif
)";
    BOOST_REQUIRE_EQUAL(oss.str(), expectedOutput);
}

BOOST_AUTO_TEST_CASE(timeA) {
    NB::Universe t;
    double time = 0.0;
    double T = 157788000.0;
    double d_t = 25000.0;

    std::ifstream file;
    file.open("planets.txt");
    file >> t;
    if (time < T) {
        t.step(d_t);
        time += d_t;
    }
    BOOST_CHECK_CLOSE(time, d_t, 0.1);
}

BOOST_AUTO_TEST_CASE(test_universe_body) {
    auto universe = loadUniverseFromFile("planets.txt");
    double Time = 31557600.0;
    double Deltatime = 15000.0;

    for (double currentTime = 0; currentTime <= Time; currentTime += Deltatime) {
        universe.step(Deltatime);
    }

    NB::CelestialBody earth = universe[0];

    BOOST_CHECK_CLOSE(earth.position().x, 1.49588e+11, 0.1);
    BOOST_CHECK_CLOSE(earth.position().y, -2.08959e+09, 0.1);
    BOOST_CHECK_CLOSE(earth.velocity().x, 416.318, 0.1);
    BOOST_CHECK_CLOSE(earth.velocity().y, 29796.9, 0.1);

    NB::CelestialBody sun = universe[3];
    BOOST_CHECK_CLOSE(sun.position().x, 595931, 0.1);
    BOOST_CHECK_CLOSE(sun.position().y, 6.23188e+06, 0.1);
    BOOST_CHECK_CLOSE(sun.velocity().x, -0.0585217, 0.1);
    BOOST_CHECK_CLOSE(sun.velocity().y, 0.163337, 0.1);
}



