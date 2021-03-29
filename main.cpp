#include  <iostream>
#include "predictor.h"
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char*argv[]){

	map<unsigned long long,string> pcAddress;
	int i = 1;	
  // Temporary variables
  unsigned long long addr;
  string behavior;
  long target;
	ifstream infile(argv[1]);
	 while(infile >> std::hex >> addr >> behavior >> std::hex >> target) {
	   cout<<i<<"."<<behavior<<endl;
	   pcAddress.insert(pair<unsigned long long,string>(addr,behavior));
	   i++;
	  }
	Predictor p(pcAddress);
	cout<<pcAddress.size()<<endl;
	cout<< p.AlwaysTaken().first<<","<<p.NeverTaken().second<<endl;

  return 0;



}
