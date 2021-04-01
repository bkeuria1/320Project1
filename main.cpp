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
        vector<long>branch;;
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
	   branch.push_back(target);
	   if(behavior == "T") {
     		 taken++;
   	    }else {
      		notTaken++;
    	   }
	   // pcAddress.insert(pair<unsigned long long,string>(addr,behavior));
	  total++;
	  }
	
	Predictor pr(actions,address,branch);	
//	cout<<"The size of the map is "<<pcAddress.size()<<endl;
        ofstream myfile;
	myfile.open(argv[2]);
	myfile<<taken<<","<<total<<";\n";
	myfile<<notTaken<<","<<total<<";\n";
       
        int sizes [] = {16, 32, 128, 256, 512, 1024, 2048 };

	for(auto &i : sizes){
	    myfile<<pr.SingleBit(i)<<","<<total<<"; ";	          
	}
	myfile<<"\n";	

         for(auto &i : sizes){
            myfile<<pr.DoubleBit(i)<<","<<total<<"; ";           
        }
        myfile<<"\n";

       for(int i = 3;i<=11;i++){
	  myfile<<pr.GShare(i)<<","<<total<<"; ";
       }
	myfile<<"\n";

       myfile<<pr.tournament()<<","<<total<<"; "<<endl;
      myfile<<pr.BTB().first<<","<<pr.BTB().second<<";"<<endl;
  return 0;



}
