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
#ifdef DEBUG_NANO
  for (int ii = 0; ii < atoms.size(); ii++) {
    std::cout << "Atom " << ii << " is " << atoms[ii].element << " at ("
              << atoms[ii].x << "," << atoms[ii].y << "," << atoms[ii].z << ")."
              << std::endl;
  }
#endif
}

//// public methods
void Nano::addLigand(const Ligand) {
  return;
}

/* write out the coordinates of the nanoparticle to a new file */
void Nano::writeCoords(const char * outFile) {
  std::ofstream output(outFile);
  
  // first line is number of atoms, second is blank
  output << atoms.size() << std::endl << std::endl;

  // one line for each atom
  for (int ii = 0; ii < atoms.size(); ii++) {
    output << atoms[ii].element << " " << atoms[ii].x << " "
           << atoms[ii].y << " " << atoms[ii].z << std::endl;
  }
  output.close();

  return;
}

//// private methods
/* calculates the center of all atomic coordinates of a nano.*/
void Nano::setOrigin() {
  double sumX = 0.0;
  double sumY = 0.0;
  double sumZ = 0.0;

  for (int ii = 0; ii < atoms.size(); ii++) {
    sumX += atoms[ii].x;
    sumY += atoms[ii].y;
    sumZ += atoms[ii].z;
  }
  
  // set origin
  origin.x = sumX/atoms.size();
  origin.y = sumY/atoms.size();
  origin.z = sumZ/atoms.size();

#ifdef DEBUG_NANO
  std::cout << "Origin of nano is at ("
            << origin.x << "," << origin.y << "," << origin.z << ")."
            << std::endl;
#endif
  return;
}

/* shift all atomic coordinates so that the particle is centered at the origin. */
void Nano::shiftToOrigin() {
  for (int ii = 0; ii < atoms.size(); ii++) {
    atoms[ii].x -= origin.x;
    atoms[ii].y -= origin.y;
    atoms[ii].z -= origin.z;
  }

  origin.x = 0.0;
  origin.y = 0.0;
  origin.z = 0.0;

  return;
}

void Nano::findSurfaceAtoms() {
  return;
}
