CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iheaders
OUT = area

SRC = main.cpp sources/Circulo.cpp sources/Elipse.cpp sources/Punto.cpp sources/Rectangulo.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
