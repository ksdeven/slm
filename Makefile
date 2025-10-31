
TARGET = slm

#COMPILER & FLAGS
CXX = g++
CXXFLAGS = -Wall -std=c++17

OBJS = main.o kgram.o
#Execuatble
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

#cpp to O
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean
clean:
	rm -f *.o $(TARGET)
