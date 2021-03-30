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


pair<long,long>Predictor::DoubleBit(int size){


   int correct = 0;
   vector<int> table(size,3);
//3-strongly taken
//2-weakly taken
//1- weakly not taken
//0 - strongly not taken
  for (int i = 0; i<actions.size();i++){
           int index = address.at(i)%size;
           if(index == size)cout<<"wow"<<endl;
           int predicted = table.at(index);
           string action = actions.at(i);
           if(action == "T" && (predicted ==2 || predicted ==3)){
		correct++;
		if(predicted == 2)table.at(i) = 3;
          }

          else if(action == "NT"   && (predicted ==0 || predicted ==1)){
                 correct++;
		if(predicted == 1) table.at(i)=0;
	}
	else{
	 	//incorrect cases
		if(predicted == 2)table.at(i) = 1;
		if(predicted ==3)table.at(i) = 2;
		if(predicted == 1) table.at(i) = 2 ;
	}
               



    }

  return pair<long, unsigned long>(correct, actions.size());

}


