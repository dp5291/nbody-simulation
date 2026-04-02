// "Copyright [2024] <Dhruv Patel>"
#include <fstream>
#include <string>
#include "Universe.hpp"
#include "CelestialBody.hpp"

NB::Universe::Universe(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }
    file >> *this;
    file.close();
}

int NB::Universe::numPlanets() const {
    return num_planets;
}

double NB::Universe::radius() const {
    return Radius;
}

void NB::Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& body : bodies) {
        target.draw(*body, states);
    }
}

void NB::Universe::step(double t) {
    for (auto c : bodies) {
        for (auto cb : bodies) {
            if (c != cb) {
                c->moveacc(*cb, t);
            }
        }
    }
    for (auto c : bodies) {
        c->movepla(t);
    }
}

NB::CelestialBody& NB::Universe::operator[](int num) {
    return *bodies[num];
}

std::istream& NB::operator>>(std::istream &cin, Universe& nb) {
    cin >> nb.num_planets >> nb.Radius;

    for (int i = 0; i < nb.num_planets; ++i) {
        auto body = std::make_shared<NB::CelestialBody>();
        cin >> *body;
        nb.bodies.push_back(body);
    }

    return cin;
}

std::ostream& NB::operator<<(std::ostream& cout, const Universe& nb) {
    cout << nb.num_planets << std::endl;
    cout << nb.Radius << std::endl;
    for (const auto& body : nb.bodies) {
        cout << *body;
    }
    return cout;
}
