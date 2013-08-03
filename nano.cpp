#define DEBUG_NANO

#include "nano.hpp"

Nano::Nano(const char * nanoFile) {
  if (nanoFile == NULL) {
    std::cout << "ERROR: specify an input coordinate file";
  }

  //// read in coordinate data from file
  std::ifstream data(nanoFile);

  // the first two lines in the file don't matter
  // TODO discard first two lines

  // placeholder atom
  Atom a;

  // for each line in the file, create an atom
  while (data >> a.element >> a.x >> a.y >> a.z) {
    // TODO do I really need this method?
    atoms.emplace_back(a);
  }

  // clean up
  data.close();

  // move the data to be centered at the origin
  setOrigin();
  shiftToOrigin();

  // create the vector of surface atoms
  findSurfaceAtoms();
}

//// public methods
void Nano::addLigand(const Ligand) {
  return;
}

void Nano::writeCoords() {
  return;
}

//// private methods
void Nano::setOrigin() {
  return;
}

void Nano::shiftToOrigin() {
  return;
}

void Nano::findSurfaceAtoms() {
  return;
}
