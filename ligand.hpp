#ifndef __LIGAND__
#define __LIGAND__

#include "atom.hpp"

class Ligand {
  public:
    void rotate(double degrees = 1);
  private:
    vector<Atom> atoms;
}

#endif
