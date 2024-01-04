CXX = g++ 
CXXFLAGS = -Wall -I.
OBJS = baza_pojazdow.o pojazdy.o main.o 
DEPS = pojazdy.hpp baza_pojazdow.hpp 

%.o: %.cpp $(DEPS)
	$(CXX) -c $^ $(CXXFLAGS)

all: $(OBJS)
	$(CXX) -o $@ $(OBJS)

.PHONY: clean

clean: 
	rm -f $(OBJS) *.o