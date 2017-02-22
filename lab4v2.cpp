/*
n!/(k!*(n-k)!)
*/



#include <iostream>

//Binomial coefficient
int bc (int n, int k){
	
	//Stopping condition
	if(k == 0 or n == 0 or (n-k) == 0){
		return 1;

	}

	else if (1 <= k <= (n-1) and 0 <= n){

		return (bc(n-1,k-1) + bc(n-1,k));
	}

	else if (k >= n){
		std::cout << "k cannot be greater than n.\n";
		return 0;

	}

	else {
		return 0;
	}

}
int n = 0;
int k = 0;

//Main Function
int main (int argc, char** argv){
	
	
	if (argc != 3){
		std::cout << "Incorrect number of arguments.\n";
		return 0;
	}
	else {
		int n = std::stoi(std::string (argv[1]));
		int k = std::stoi(std::string (argv[2]));
		std::cout << "The number of permutations of "<<argv[1]<<" choose "<<argv[2]<<" is:"<<bc(n,k)<<'\n';

		return 0;
	}
}
