CXX = g++ 
CXXFLAGS = -Wall -I.
OBJS = baza_pojazdow.o pojazdy.o ui.o main.o 
DEPS = pojazdy.hpp baza_pojazdow.hpp uui.hpp

%.o: %.cpp $(DEPS)
	$(CXX) -c $^ $(CXXFLAGS)

all: $(OBJS)
	$(CXX) -o $@ $(OBJS)

.PHONY: clean

clean: 
	rm -f $(OBJS) *.o
	rm -f $(OBJS) *.gch