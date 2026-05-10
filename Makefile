CXX := g++
CXXFLAGS := -std=c++17 -O2

SOURCES := main.cpp User.cpp MutualFund.cpp Portfolio.cpp Transaction.cpp MarketEngine.cpp FileManager.cpp AnalyticsManager.cpp
OBJECTS := $(SOURCES:.cpp=.o)
TARGET := app

# Set these if SFML is not in default paths
SFML_INCLUDE ?=
SFML_LIB ?=

INCLUDES :=
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

ifneq ($(SFML_INCLUDE),)
INCLUDES += -I$(SFML_INCLUDE)
endif
ifneq ($(SFML_LIB),)
LIBS += -L$(SFML_LIB)
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
