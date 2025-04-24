CXX = g++
CXXFLAGS = -std=c++11 -Ilib/tinyxml2 

OBJS = main.o  lib/tinyxml2/tinyxml2.o

H_OBJS = highways.o  lib/tinyxml2/tinyxml2.o
all: main highways graph

main: $(OBJS)
	$(CXX) $(OBJS) -o main


graph: lib/tinyxml2/tinyxml2.o graph.o
	$(CXX) lib/tinyxml2/tinyxml2.o graph.o -o graph

highways: $(H_OBJS)
	$(CXX) $(H_OBJS) -o highways

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp

highways.o: highways.cpp 
	$(CXX) -I .  $(CXXFLAGS) -c highways.cpp

graph.o: graph.cpp 
	$(CXX) -I .  $(CXXFLAGS) -c graph.cpp

lib/tinyxml2/tinyxml2.o: lib/tinyxml2/tinyxml2.cpp
	$(CXX) $(CXXFLAGS) -c lib/tinyxml2/tinyxml2.cpp -o lib/tinyxml2/tinyxml2.o

clean:
	rm -f *.o graph main highways lib/tinyxml2/*.o
