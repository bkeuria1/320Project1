#include "predictor.h"
#include <iostream>
//Predictor::Predictor(map<long,string> pcAction):pcAction(pcAction){
#include <string.h>
using namespace std;
Predictor::Predictor(){
}

Predictor::Predictor(vector<string>_actions,vector<long>_address ):actions(_actions), address(_address){
}

/*
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

*/
pair<long,long>Predictor::SingleBit(int size){


   int correct = 0;
   vector<int> table(size,1);
  for (int i = 0; i<actions.size();i++){
           int index = address.at(i)%size;
	   int predicted = table.at(index);
	   string action = actions.at(i);
	   if(predicted==1){
		if (action == "T"){correct++;}
		else{
 		table.at(index) = 0;
		}
		
	  }

 	  else if(predicted==0){
                if (action== "NT"){correct++;}
                else{
                 table.at(index) = 1;
                }

 

    }
}
  return pair<long, unsigned long>(correct, actions.size());

}
