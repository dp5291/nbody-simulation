// "Copyright [2024] <Dhruv Patel>"
#ifndef CELESTIALBODY_HPP  // _HOME_DHRUV5291_COMPUTING4_PS4A_CELESTIALBODY_HPP_
#define CELESTIALBODY_HPP  // _HOME_DHRUV5291_COMPUTING4_PS4A_CELESTIALBODY_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
const int window_height = 800;
const int window_width = 800;
const double radius = 2.50e+11;
const double G = 6.67e-11;
namespace NB {
class CelestialBody : public sf::Drawable {
 private:
        sf::Vector2<double> pos;
        sf::Vector2<double> vel;
        double Mass;
        sf::Texture texture;
        sf::Sprite sprite;
        std::string planet;
        std::string imageName;
 protected:
        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

 public:
        void movepla(double t);
        void moveacc(CelestialBody const &cb, double t);
        sf::Vector2f position() const;
        sf::Vector2f velocity() const;
        double mass() const;
        std::string get_planet();
        friend std::istream& operator>>(std::istream& cin, CelestialBody& nb1);
        friend std::ostream& operator<<(std::ostream& COUT, const CelestialBody& nb1);
};
    std::istream& operator>>(std::istream& cin, CelestialBody& body);
    std::ostream& operator<<(std::ostream& COUT, const CelestialBody& body);
}  //  namespace NB
#endif
