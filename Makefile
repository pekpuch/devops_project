CXXFLAGS = -std=c++11 -Iinclude -Ilibraries/SFML-2.6.1/include -fPIE
LDLIBS = -Llibraries/SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,src/%.o,$(SRCS))

all: main

main: $(OBJS)
	g++ $^ -o $@ $(LDLIBS)

src/%.o: src/%.cpp include/%.h
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o *.out main main