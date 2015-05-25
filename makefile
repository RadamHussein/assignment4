CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

CXX = tournament.cpp
CXX += lineup.cpp
CXX += loserStack.cpp
CXX += character.cpp
CXX += barbarian.cpp
CXX += bluemen.cpp
CXX += reptile.cpp
CXX += goblin.cpp
CXX += shadow.cpp
CXX += character.h
CXX += lineup.h
CXX += loserStack.h
CXX += node.h
CXX += barbarian.h
CXX += bluemen.h
CXX += reptile.h
CXX += goblin.h
CXX += shadow.h

default:
	g++ -std=c++0x ${CXX} -o prog
