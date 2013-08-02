#ifndef __NANO__
#define __NANO__

#include "atom.hpp"
#include "ligand.hpp"

class Nano {
  public:
    // default constructor
    Nano(const char * nanoFile = NULL);
    // methods
    addLigand(const Ligand);
  private:
    // all atoms in particle
    vector<Atom> atoms;
    // surface atoms
    vector<Atom> surfAtoms;
}

#endif
