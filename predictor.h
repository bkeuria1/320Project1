#ifndef PREDICTOR_H
#define PREDICTOR_H
#include <string>
#include <map>
using namespace std;
class Predictor{
    private:
	map<unsigned long long,string> pcAction;
    public:
	Predictor();
	Predictor(map<unsigned long long,string>);
	pair<long,long>AlwaysTaken();
	pair<long,long>NeverTaken();

	

};
#endif
