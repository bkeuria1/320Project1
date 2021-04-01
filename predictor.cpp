#include "predictor.h"
#include <iostream>
//Predictor::Predictor(map<long,string> pcAction):pcAction(pcAction){
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
Predictor::Predictor(){
}

Predictor::Predictor(vector<string>_actions,vector<long>_address,vector<long>_branch):actions(_actions), address(_address), branch(_branch){}
long Predictor::SingleBit(int size){


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
  return correct;

}

long Predictor::DoubleBit(int size){


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

  return correct;

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
 bool gCorrect;
 bool bCorrect; 
 int tableSize = 2048;
 int ghr = 0;
 int correct = 0;
 vector<int>bTable(tableSize,3);
 vector<int>gTable(tableSize,3);
 vector<int>sTable(tableSize,0);
 //3 -predictor 1 (b)
//2 weakly predictor 1 (b)
//1 weak predictor 2 (g)
//0 predictor 2 (g)
int bc =0;
for(int i =0;i<actions.size();i++){
    string action = actions.at(i);
    long bIndex = address.at(i)%tableSize;
    long sIndex = address.at(i)%tableSize;
    long gIndex = ghr ^ bIndex;
    int bPredicted = bTable.at(bIndex);
    int gPredicted = gTable.at(gIndex);  
  //check if bimodal is correct
 if(action=="T" &&( bTable.at(bIndex)==3 || bTable.at(bIndex)==2)){
 	bCorrect = true;
        if(bTable.at(bIndex)==2)bTable.at(bIndex)=3;
 }
   else if(action == "NT"   && (bTable.at(bIndex) ==0 || bTable.at(bIndex)==1)){
                 bCorrect = true;           
	
                if(bTable.at(bIndex) == 1) bTable.at(bIndex)=0;
    }
else{
  //incorrect cases
  
  bCorrect = false;
   if(bPredicted == 2)bTable.at(bIndex) = 1;
                if(bPredicted ==3)bTable.at(bIndex) = 2;
                if(bPredicted == 1)bTable.at(bIndex) = 2 ;
                if(bPredicted == 0 )bTable.at(bIndex) = 1;
}   


//check if gshare is correct
 if(action=="T" &&( gTable.at(gIndex)==3 || gTable.at(gIndex)==2)){
        gCorrect = true;
       
        if(gTable.at(gIndex)==2)gTable.at(gIndex)=3;
 }      
   else if(action == "NT"   && (gTable.at(gIndex) ==0 || gTable.at(gIndex)==1)){
                 gCorrect = true;
             
                if(gTable.at(gIndex) == 1) gTable.at(gIndex)=0;
    }           
else{
  
  gCorrect = false;
  if(gPredicted == 2)gTable.at(gIndex) = 1;
                if(gPredicted ==3)gTable.at(gIndex) = 2;
                if(gPredicted == 1)gTable.at(gIndex) = 2 ;
                if(gPredicted == 0 )gTable.at(gIndex) = 1;
}
//update gshare
	int addedBit = (action == "T") ? 1: 0;
        ghr<<=1;
        ghr |= addedBit;
        ghr &= (1<<11)-1;   
//selector stuff

//check if we predicted correctly
if(gCorrect && (sTable.at(sIndex) == 0|| sTable.at(sIndex)==1))correct++;
 if(bCorrect && (sTable.at(sIndex) == 2 || sTable.at(sIndex)==3))correct++;
//check where we need to transition too

int selected = sTable.at(sIndex);

if(!gCorrect && bCorrect && selected!=3 )sTable.at(sIndex)+=1;
if(gCorrect && !bCorrect && selected !=0)sTable.at(sIndex)-=1;
}


return correct;

}

pair<long,long> Predictor::BTB(){
  int tableSize = 512;
 bool nextPC = false;
   long b;
  long attempted = 0;
  vector<int>bi(tableSize,1);
  vector<int> btb(tableSize,0);
  long correct = 0;
  for(int i = 0; i<branch.size();i++){
     string action = actions.at(i);

     int index;
     //if(nextPC) index = b%tableSize;
      index = address.at(i)%tableSize;	
     //read from btb if predicted taken
     int predicted = bi.at(index);
     if(predicted == 1){
        if(action == "T"){
	  
	 if(btb.at(index)==branch.at(i)){
		correct++;
		b = btb.at(index);
		nextPC = true;
	}else{
	    nextPC = false;
     
	btb.at(index) = branch.at(i);
	}
	}
	attempted++;
      	
     }
     //update bimodal if inncorrect
    if(action == "NT" && predicted==1)bi.at(index) = 0;
    if(action == "T" && predicted==0)bi.at(index) = 1;
  }

 return pair<long,long>(correct,attempted);
}



