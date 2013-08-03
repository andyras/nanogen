CXX=icpc
CXXFLAGS=-O3 --std=c++11

nanogen: main.o ligand.o nano.o
	$(CXX) $(CXXFLAGS) -o nanogen main.o ligand.o nano.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

ligand.o: ligand.cpp ligand.hpp
	$(CXX) $(CXXFLAGS) -c ligand.cpp

nano.o: nano.cpp nano.hpp
	$(CXX) $(CXXFLAGS) -c nano.cpp

.PHONY: clean

clean:
	rm -f *.o
	rm -f nanogen
