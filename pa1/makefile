all: test
test: Stress_ball.o Collection_test.o
	c++ -std=c++11 Stress_ball.o Collection_test.o Collection.o -o test
Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp
Collection.o: Collection.cpp Collection.h
	c++ -std=c++11 -c Collection.cpp
Collection_test.o: Collection_test.cpp
	c++ -std=c++11 -c Collection_test.cpp
clean
	rm -f *.o test
