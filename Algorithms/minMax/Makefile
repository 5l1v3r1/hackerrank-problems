CXX=g++
CXFLAGS=-Wc++14-extensions -Wall -stdlib=libc++ -std=c++14 -pedantic
LDFLAGS=
EXEC=minMax
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

minMax: minMax.o
	@$(CXX) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper:
	@rm -rf $(EXEC)
