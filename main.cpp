#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>

#include "atom.hpp"
#include "ligand.hpp"
#include "nano.hpp"

#define DEBUG

int main(int argc, char ** argv) {
  try {
    //// get the name of the input file
    char * inputFile;
    if (argc < 2) {
      inputFile = "nano.xyz";
    }
    else {
      inputFile = argv[1];
    }
#ifdef DEBUG
  std::cout << "Input file is " << inputFile << std::endl;
#endif
    
    // create a nano from the data file
    Nano nano(inputFile);

    // write out the new nano coordinates
    nano.writeCoords("newNano.xyz");
  }
  catch (...) {
    std::cout << "DANGER! DANGER! BROKEN NANO!" << std::endl;
    //std::cout << "Runtime error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
