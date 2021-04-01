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
        
	vector<long> branch;
    public:	
	Predictor();
	Predictor( vector<string>actions,vector< long> address, vector<long>branch);
	long AlwaysTaken();
	long NeverTaken();
        long SingleBit(int size);
        long DoubleBit(int size);
        long GShare(int historySize);
        long tournament();	
	pair<long,long> BTB();

};
#endif
