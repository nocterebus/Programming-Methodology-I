/*
Justen Yeung
Lab 10

*/

#include <iostream>
#include <map>
#include <utility>
#include <vector>



int main(int argc, char** argv){
std::cout<<"Please enter your numbers\n";
//instantiate a map to hold values
//<key,value>
std::map<int,int> MERP;
//input variable to carry input value
int input;
//mode value
int mode;
//mode count
int count = 0;
//accepts input until input is not an integer
while (std::cin>>input) {
	if(MERP.count(input) > 0) {
		MERP[input]++;
	}
	else{
		MERP[input] = 1;
	}
} 

for(std::map<int,int>::iterator it = MERP.begin(); it != MERP.end(); ++it){
	if ((it->second) > count){
		count = (*it).second;
		mode = it->first;
	}
}

std::cout<<"The mode is "<<mode<<'\n';
	return 0;
}