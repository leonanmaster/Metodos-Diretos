CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = metodos_diretos_app
SOURCES = main.cpp metodos_diretos.cpp triangular.cpp QR.cpp
HEADERS = triangular.hpp metodos_diretos.hpp QR.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp $(HEADERS) # Certifique-se de que esta linha depende de todos os cabeçalhos
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)