CXXFLAGS := -std=c++20 -fPIC -g -Wpedantic -Wall -Wextra

SOURCES  := $(wildcard *.cpp)
OBJECTS  := $(strip $(patsubst %.cpp, %.o, $(SOURCES)))
TARGET   := rand

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CXXFLAGS += -O0
else
	CXXFLAGS += -O3
endif

.PHONY: all
all: $(TARGET).so

.PHONY: clean
clean:
	rm -f *.o $(TARGET)

$(TARGET).so: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -shared $(OBJECTS) -o $@

$(OBJECTS): %.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
