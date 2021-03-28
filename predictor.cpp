#include "predictor.h"
#include <iostream>
//using namespace std;
//Predictor::Predictor(map<long,string> pcAction):pcAction(pcAction){


Predictor::Predictor(){
}

pair<long,long>AlwaysTaken(){

  return pair<long, unsigned long>(0,0);
}
pair<long,long>NeverTaken(){

	return pair<long, unsigned long>(0,0);

}

