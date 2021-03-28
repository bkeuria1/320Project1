predictors: main.o predictor.o
	g++ -o predictors main.o predictor.o
main.o: main.cpp predictor.h
	g++ -c main.cpp
predictor.o: predictor.cpp predictor.h
	g++ -c predictor.cpp
clean:
	rm predictors main.o predictor.o




