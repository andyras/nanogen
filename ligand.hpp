#ifndef __LIGAND__
#define __LIGAND__

#include <vector>

#include "atom.hpp"

class Ligand {
  public:
    void rotate(double degrees = 1);
  private:
    std::vector<Atom> atoms;
};

#endif
