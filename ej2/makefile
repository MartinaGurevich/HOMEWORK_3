CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iheaders

SRC = main.cpp sources/Circulo.cpp sources/Elipse.cpp sources/Punto.cpp sources/Rectangulo.cpp
OUT = figura.out

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
