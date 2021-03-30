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


pair<long,long>Predictor::SingleBit(int size){


   int correct = 0;
   vector<int> table(size,1);
  for (std::map<unsigned long long,string>::iterator it=pcAction.begin(); it!=pcAction.end(); ++it){
           int index = it->first%size;
	   int predicted = table.at(index);
	   string action = it->second;
	   if(action=="T" && predicted==1 || action=="NT" && predicted==0){
		correct++;
	   }
           //check for inaccurate result and update table;
       	  else if(action=="T"){
		table.at(index) = 0;
	  }
	 else if(action == "NT"){
		table.at(index) = 1;
	 }
    }
  return pair<long, unsigned long>(correct,pcAction.size());

}
