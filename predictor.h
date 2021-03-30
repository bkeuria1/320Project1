#ifndef PREDICTOR_H
#define PREDICTOR_H
#include <string>
#include <vector>
#include <map>
using namespace std;
class Predictor{
    private:
//	map<unsigned long long,string> pcAction;
	vector<string>actions;
	vector< long> address;
	//vector<unsigned long long> branch;
    public:	
	Predictor();
	Predictor( vector<string>actions,vector< long> address);
	pair<long,long>AlwaysTaken();
	pair<long,long>NeverTaken();
	pair<long,long>SingleBit(int size);
        pair <long,long>DoubleBit(int size);
	

};
#endif
