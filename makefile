all: crypto testCrypto

INC = -I include
CFLAGS = -std=c++14 -g
LDFLAGS = -lpthread -lgtest -lgtest_main
OBJ = bin/Converter.o 
TESTOBJ = bin/tests.Converter.o bin/tests.AllTests.o

testCrypto: $(TESTOBJ) $(OBJ)
	g++ $(TESTOBJ) $(OBJ) $(LDFLAGS) -o testCrypto

crypto: $(OBJ) bin/Sandbox.o
	g++ $(OBJ) bin/Sandbox.o $(CLAGS) -o crypto

bin/tests.%.o: tests/tests.%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

bin/%.o: src/%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

clean:
	rm -r bin/*.o crypto testCrypto

