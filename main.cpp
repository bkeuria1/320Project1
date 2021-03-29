#include  <iostream>
#include "predictor.h"
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char*argv[]){

	map<unsigned long long,string> pcAddress;
	long long total  = 0;	
  // Temporary variables
  unsigned long long addr;
  string behavior;
  long target;
	long taken = 0;
	long notTaken = 0;
	ifstream infile(argv[1]);
	 while(infile >> std::hex >> addr >> behavior >> std::hex >> target) {
	   //cout<<i<<"."<<behavior<<endl;
	   pcAddress.insert(pair<unsigned long long,string>(addr,behavior));
	   if(behavior == "T") {
     		 taken++;
   	 }else {
      		notTaken++;
    	   }
	  total++;
	  }
	Predictor p(pcAddress);	
        ofstream myfile;
	myfile.open(argv[2]);
	myfile<<taken<<","<<total<<";\n";
	myfile<<notTaken<<","<<total<<";\n";



  return 0;



}
