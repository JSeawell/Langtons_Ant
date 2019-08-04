# Makefile for Lab#1

# Name: Jake Seawell
# Date: 09/24/18
# Description: This Makefile shows all the files
# necessary to compile and run the executable
# file "RunAnt", for CS162 Project#1.

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = Ant.o LangtonsAnt.o choiceFunction.o intVal.o
SRCS = Ant.cpp LangtonsAnt.cpp LangtonsAntMain.cpp choiceFunction.cpp intVal.cpp
HDRS = Ant.hpp LangtonsAnt.hpp choiceFunction.hpp intVal.hpp


RunAnt: Ant.o choiceFunction.o intVal.o LangtonsAnt.o LangtonsAntMain.cpp
	${CXX} ${OBJS} LangtonsAntMain.cpp -o RunAnt

Ant.o: Ant.cpp Ant.hpp
	${CXX} -c Ant.cpp

LangtonsAnt.o: LangtonsAnt.cpp LangtonsAnt.hpp
	${CXX} -c LangtonsAnt.cpp

choiceFunction.o: choiceFunction.cpp choiceFunction.hpp
	${CXX} -c choiceFunction.cpp

intVal.o: intVal.cpp intVal.hpp
	g++ -c intVal.cpp

clean:
	rm *.o RunAnt

#target(what to create): dependencies(what is used to make)
#(tab)action(rule to build)
