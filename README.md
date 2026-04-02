# N-Body Gravitational Simulation

A two-part physics simulation of gravitational interactions between celestial bodies, built in C++ with SFML.

## Features
- Static universe renderer (Part A)
- Dynamic orbital simulation using leapfrog integration (Part B)
- Newton's law of gravitation for force, velocity, and position updates
- Configurable simulation time T and timestep delta-t via command line
- Smart pointer (shared_ptr) memory management for celestial bodies
- Prints final universe state to terminal after simulation ends

## Technologies
C++17, SFML, Smart Pointers (shared_ptr), OOP, Boost Unit Testing, Make

## How to Build and Run
```bash
make
./NBody 157788000.0 25000.0 < planets.txt
```

## Screenshots
![NBody Simulation](nbody_simulation.png)
