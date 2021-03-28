#ifndef PREDICTOR_H
#define PREDICTOR_H
#include <string>
#include <map>
using namespace std;
class Predictor{
    private:
	map<long,string> pcAction;
    public:
	Predictor();
	//Predictor(map<long,string>);
	pair<long,long>AlwaysTaken();
	pair<long,long>NeverTaken();

	

};
#endif
