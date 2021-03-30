#include  <iostream>
#include <vector>
#include<fstream>
#include<string>
#include "predictor.h"
using namespace std;

int main(int argc, char*argv[]){

//	map<unsigned long long,string> pcAddress;
	long long total  = 0;	
	vector< long>address;
	vector<string>actions;
  // Temporary variables
	  unsigned long long addr;
 	 string behavior;
	  long target;
	long taken = 0;
	long notTaken = 0;
	ifstream infile(argv[1]);
	 while(infile >> std::hex>> addr >> behavior >> std::hex >> target) {
	   //cout<<i<<"."<<behavior<<endl;
	//   cout<<addr<<","<<behavior<<endl;
	   address.push_back(addr);
	   actions.push_back(behavior);
	 
	   if(behavior == "T") {
     		 taken++;
   	    }else {
      		notTaken++;
    	   }
	   // pcAddress.insert(pair<unsigned long long,string>(addr,behavior));
	  total++;
	  }
	
	Predictor pr(actions,address);	
//	cout<<"The size of the map is "<<pcAddress.size()<<endl;
        ofstream myfile;
	myfile.open(argv[2]);
	myfile<<taken<<","<<total<<";\n";
	myfile<<notTaken<<","<<total<<";\n";
	
	
	pair<long,long>single = pr.SingleBit(32);
	myfile<<single.first<<","<<single.second<<";";



  return 0;



}
