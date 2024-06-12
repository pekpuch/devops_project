CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Itest -Ilibraries/SFML-2.6.1/include -fPIE -Wl,-rpath,libraries/SFML-2.6.1/lib
LDLIBS = -Llibraries/SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -lgtest -lgtest_main

SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,src/%.o,$(SRCS))

all: main run_script

main: $(OBJS)
	g++ $^ -o $@ $(LDLIBS)

src/%.o: src/%.cpp include/%.h
	g++ $(CXXFLAGS) -c $< -o $@

run_script:
	sh script.sh

clean:
	rm -f *.o *.out main main