#include "predictor.h"
#include <iostream>
//Predictor::Predictor(map<long,string> pcAction):pcAction(pcAction){
#include <string>
#include <bits/stdc++.h>
#include <vector>
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
cout<<table.size()<<endl;
  for (int i = 0; i<actions.size();i++){
           int index = address.at(i)%size;
          
           int predicted = table.at(index);
           string action = actions.at(i);
           if(action == "T" && (predicted ==2 || predicted ==3)){
		correct++;
		if(predicted == 2)table.at(index) = 3;
          }
          
          else if(action == "NT"   && (predicted ==0 || predicted ==1)){
                 correct++;
		if(predicted == 1) table.at(index)=0;
	}
	else{
	 	//incorrect cases
		if(predicted == 2)table.at(index) = 1;
		if(predicted ==3)table.at(index) = 2;
		if(predicted == 1) table.at(index) = 2 ;
 		if(predicted == 0 )table.at(index) = 1;
	}
               



    }

  return pair<long, unsigned long>(correct, actions.size());

}
long Predictor::GShare(const int historySize){
	/*
	string Sghr;
        vector<string>Vghr (historySize,"0");
	for(int i = 0 ;i<Vghr.size();i++){
		Sghr.append(Vghr.at(i));
	}
       */

	int ghr = 0;
	int correct = 0;  
	//3 -strongly taken
	//2 - weak taken
	//1 - weak not taken
	//0 -strong not taken
	vector<int>table(2048,3);
	for(int i =0; i<actions.size();i++){
	    string action = actions.at(i);
	    long pc = address.at(i)%2048;
	  // cout<<i<<endl;
	    long index = ghr ^ pc;
	    int predicted = table.at(index); 
             if(action == "T" && (predicted ==2 || predicted ==3)){
                correct++;
                if(predicted == 2)table.at(index) = 3;
          }     
          
          else if(action == "NT"   && (predicted ==0 || predicted ==1)){
                 correct++; 
                if(predicted == 1) table.at(index)=0;
        }       
        else{
                //incorrect cases
                if(predicted == 2)table.at(index) = 1;
                if(predicted ==3)table.at(index) = 2;
                if(predicted == 1) table.at(index) = 2 ;
                if(predicted == 0 )table.at(index) = 1;
        }   
	//update ghr
	//bitset

	        
	int addedBit = (action == "T") ? 1: 0;
	ghr <<=1;
       ghr |= addedBit;
	ghr &=(1<< historySize)-1;
}

 return correct;

}
long Predictor::tournament(){
 bool gCorrect = false;
 bool bCorrect = false; 
 int tableSize = 2048;

 vector<int>gTable(tableSize,3);
 vector<int>sTable(table,3);
 //3 -predictor 1 (b)
//2 weakly predictor 1 (b)
//1 weak predictor 2 (g)
//0 predictor 2 (g)



}
