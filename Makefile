CXXFLAGS = -std=c++11 -Iinclude -Ilibraries/SFML-2.6.1/include
LDLIBS = -Llibraries/sfml-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all: main

main: src/main.o
	g++ $^ -o $@ $(LDLIBS)

src/%.o: src/%.cpp include/%.h
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o *.out main
