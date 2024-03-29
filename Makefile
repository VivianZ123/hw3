CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all:  llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
OBJS=llrec-test.o

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

llrec-test.o: llrec-test.cpp llrec.h llrec.cpp 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 