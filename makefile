CXX=icpc
CXXFLAGS=-O3

nanogen: main.cpp
	$(CXX) $(CXXFLAGS) -o nanogen main.cpp
