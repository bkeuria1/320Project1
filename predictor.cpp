#include "predictor.h"
#include <iostream>
//Predictor::Predictor(map<long,string> pcAction):pcAction(pcAction){
#include <string.h>
using namespace std;
Predictor::Predictor(){
}

Predictor::Predictor(map<unsigned long long,string>_pcAction):pcAction(_pcAction){
}	
pair<long,long>Predictor::AlwaysTaken(){
  int correct = 0;
  for (std::map<unsigned long long,string>::iterator it=pcAction.begin(); it!=pcAction.end(); ++it){
            if(it->second=="T"){
		cout<<"correct"<<endl;	
		correct++;
	   }
    } 
  return pair<long, long>(correct,pcAction.size());
}
pair<long,long>Predictor::NeverTaken(){

 
   int correct = 0;
  for (std::map<unsigned long long,string>::iterator it=pcAction.begin(); it!=pcAction.end(); ++it){
            if(it->second=="NT"){
                correct++;
           }
    }
  return pair<long, unsigned long>(correct,pcAction.size());

}

