# # Makefile for compiling your_class.cxx

# ROOTCFLAGS = $(shell root-config --cflags)
# ROOTLIBS = $(shell root-config --libs)

# CXX = g++
# CXXFLAGS = -Wall -O2 $(ROOTCFLAGS)
# LIBS = $(ROOTLIBS)

# SRC = your_class.cxx
# OBJ = $(SRC:.cxx=.o)
# EXE = your_program

# $(EXE): $(OBJ)
# 	$(CXX) -o $@ $(OBJ) $(LIBS)

# %.o: %.cxx
# 	$(CXX) $(CXXFLAGS) -c $<

# clean:
# 	@rm -f $(EXE) $(OBJ)
