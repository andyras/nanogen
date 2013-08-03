#ifndef __NANO__
#define __NANO__

#include <vector>
#include <fstream>
#include <iostream>

#include "atom.hpp"
#include "ligand.hpp"

class Nano {
  public:
    // default constructor
    Nano(const char * nanoFile = NULL);
    // methods
    void addLigand(const Ligand);
    void writeCoords(const char * outFile);
  private:
    // all atoms in particle
    std::vector<Atom> atoms;
    // surface atoms
    std::vector<Atom> surfAtoms;
    // origin
    Atom origin;
    //// methods
    void setOrigin();
    void shiftToOrigin();
    void findSurfaceAtoms();
};

#endif
