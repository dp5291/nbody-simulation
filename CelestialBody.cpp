// "Copyright [2024] <Dhruv Patel>"
#include "CelestialBody.hpp"
#include <iomanip>
#include <string>

void NB::CelestialBody::draw(sf::RenderTarget& window,
 sf::RenderStates states) const {
    window.draw(sprite, states);
}

sf::Vector2f NB::CelestialBody::position() const {
    return sf::Vector2f(static_cast<float>(pos.x), static_cast<float>(pos.y));
}

sf::Vector2f NB::CelestialBody::velocity() const {
    return sf::Vector2f(static_cast<float>(vel.x), static_cast<float>(vel.y));
}

double NB::CelestialBody::mass() const {
    return Mass;
}

void NB::CelestialBody::moveacc(CelestialBody const &cb, double t) {
    double distancex = cb.pos.x - pos.x;
    double distancey = cb.pos.y - pos.y;

    double r2 = (distancex * distancex) + (distancey * distancey);
    double r = sqrt(r2);
    double F = ((G * Mass * cb.Mass) / r2);

    double Fx = F * distancex / r;
    double Fy = F * distancey / r;

    double accelx = Fx/Mass;
    double accelY = Fy/Mass;

    vel.x += (accelx * t);
    vel.y += (accelY * t);
}

void NB::CelestialBody::movepla(double t) {
    pos.x += (vel.x * t);
    pos.y += (vel.y * t);

double xCoord = ((pos.x / radius) * (window_width / 2)) + (window_width / 2);
double yCoord = ((-(pos.y / radius) * (window_height / 2)) + (window_height / 2));
sprite.setPosition(xCoord, yCoord);
}



std::istream& NB::operator>>(std::istream& cin, CelestialBody& nb1) {
    cin >> nb1.pos.x >> nb1.pos.y >> nb1.vel.x >> nb1.vel.y >> nb1.Mass;
    cin >> nb1.imageName;
    nb1.planet = "nbody/" + nb1.imageName;
    if (!nb1.texture.loadFromFile(nb1.planet)) {
        std::cout << "Failed to load " << std::endl;
        return cin;
    } else {
        nb1.sprite.setTexture(nb1.texture);
    }
    double xCoord = (((nb1.pos.x / radius) * (window_width / 2)) + (window_width / 2));
    double yCoord = ((-(nb1.pos.y / radius) * (window_height / 2)) + (window_height / 2));

    sf::FloatRect bounds = nb1.sprite.getLocalBounds();
    nb1.sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    nb1.sprite.setPosition(xCoord, yCoord);
    return cin;
}

std::string NB::CelestialBody::get_planet() {
    return planet;
}

std::ostream& NB::operator<<(std::ostream& COUT, const CelestialBody& nb1) {
    COUT << nb1.pos.x << " ";
    COUT << nb1.pos.y << " ";
    COUT << nb1.vel.x << " ";
    COUT << nb1.vel.y << " ";
    COUT << nb1.Mass << " ";
    COUT << nb1.imageName << std::endl;

    return COUT;
}
