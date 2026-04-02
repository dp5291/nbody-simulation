// "Copyright [2024] <Dhruv Patel>"
#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "CelestialBody.hpp"

namespace NB {
class Universe : public sf::Drawable {
 private:
        int num_planets;
        std::vector<std::shared_ptr<CelestialBody>> bodies;
        double Radius;

 protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 public:
        Universe() = default;
        explicit Universe(const std::string& filename);
        double radius() const;
        int numPlanets() const;
        void step(double t);
        CelestialBody& operator[](int num);
        friend std::istream& operator>>(std::istream &cin, Universe& nb);
        friend std::ostream& operator<<(std::ostream& cout, const Universe& nb);
};
    std::istream& operator>>(std::istream& cin, Universe& nb);
    std::ostream& operator<<(std::ostream& cout, const Universe& nb);
}  // namespace NB
#endif
