all: crypto test

INC = -I include
CFLAGS = -std=c++14 -g
LDFLAGS = -lpthread -lgtest -lgtest_main
OBJ = bin/Buffer.o 
TESTOBJ = bin/tests.Buffer.o bin/tests.AllTests.o

test: $(TESTOBJ) $(OBJ)
	g++ $(TESTOBJ) $(OBJ) $(LDFLAGS) -o test

crypto: $(OBJ) bin/Sandbox.o
	g++ $(OBJ) bin/Sandbox.o $(CLAGS) -o crypto

bin/tests.%.o: tests/tests.%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

bin/%.o: src/%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

clean:
	rm -r bin/*.o crypto test

