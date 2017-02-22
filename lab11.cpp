/*
Justen Yeung
Lab11
functional programming
*/


#include <iostream>
#include <algorithm>
#include <vector>

bool iseven(int i){
	return ((i%2) == 0);
}
bool isneg(int i){
	return (i<0);
}
int main (){
	int input;
	std::vector<int> vectaaa;
	while (std::cin>>input){
		vectaaa.push_back(input);
	}

	int evens = count_if(vectaaa.begin(),vectaaa.end(), iseven);
	std::cout<<"There are "<<evens<<" even numbers.\n";

	std::vector<int>::iterator neg = find_if(vectaaa.begin(),vectaaa.end(), isneg);
	std::cout<<"The first negative element is "<<*neg<<'\n';
	return 0;
}