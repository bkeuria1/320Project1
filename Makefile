predictors: main.o predictor.o
	g++ -std=c++11 -o predictors main.o predictor.o
main.o: main.cpp predictor.h
	g++  -std=c++11 -c main.cpp
predictor.o: predictor.cpp predictor.h
	g++ -std=c++11  -c predictor.cpp
clean:
	rm predictors main.o predictor.o




