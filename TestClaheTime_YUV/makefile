INCLUDE = $(shell pkg-config --cflags opencv)
LIBS = $(shell pkg-config --libs opencv)
SOURCES = $(wildcard *.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

TARGET = main
$(TARGET):$(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) -I $(INCLUDE) $(LIBS)
$(OBJECTS):$(SOURCES)
	g++ -c $(SOURCES)
clean:
	rm $(OBJECTS) $(TARGET)

%.o:%.cpp
	g++ -I $(INCLUDE) -o $@ -c $<