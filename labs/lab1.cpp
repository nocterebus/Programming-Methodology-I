/*
Programming Methodology 1
Homework 1 (sum,mean,mode,odd,even)

Written by Justen Yeung
*/

#include <iostream>
#include <vector>
#include <algorithm>

//sorting code (least to greatest) to help find mode
typedef std::vector<int>::iterator iter;
iter findleast (iter begin, iter end) {
	//First check for an empty range
	if (begin == end) {
		return end;
	}
	//Otherwise the first element is the smallest seen so far
	iter  least = begin;
	//Check the other elements for something smaller
	do {
		if (*begin < *least){
			least = begin;
		}
		++begin;
	} while (begin != end);
	
	return least;
}
//sorting function
void sorttt(iter begin, iter end){
	for (iter I = begin; I != end ; ++I) {
		//iterate through and find the smallest number
		iter least = findleast(I,end);
		//place smallest number first
		std::swap(*I, *least);
	}
}

//initialize variables
float input = 0;
//number of inputs
float inputsss = 0;
//final resulting number
float result = 0;
//assuming that only integers will be inputed to test for even/odd
//since the compiler states that the types 'float' and 'double'
// are invalid to 'operator%' (compiled / tested previously)
int in = 0;
int count = 0;
//make some variables to find mode
int pastnumber;
int modecount = 0;

//main function
int main(int argc, char**argv) {
	
	//Return 0 when given proper arguments
	if (2 == argc){

		//convert the inputted argument to a string
		//this was
		std::string argument = (argv[1]);
		
		//summmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
		if (argument == "sum") {
			//stop at non number input
			while (std::cin >> input){
				//add all the numbers together
				result = result + input;
				++inputsss;
			}

			//return 3 if given no inputs
			if (inputsss == 0){
				return 3;
			}
		}

		//meannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
		else if (argument == "mean"){
			//stop at non number input
			while (std::cin >> input){
				//add all the numbers together
				result = result + input;
				++inputsss;
			}

			//return 3 if given no inputs
			if (inputsss == 0){
				return 3;
			}
			//after exiting loop (and there were inputs), find the average
			result = result/inputsss;
		}	

		//modeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
		else if (argument == "mode"){

			//Make a vector to use to determine mode
			std::vector<int> vectaaa;

			//stop at non number input
			while (std::cin >> input){
				//place input into vector
				vectaaa.push_back(input);
				++inputsss;	
				result = input;
			}			
			
			//sort input (least to greatest)
			sorttt(vectaaa.begin(), vectaaa.end());
			
			//Find most occuring number
			for (iter I = vectaaa.begin(); I != vectaaa.end(); ++I){
				//begin counting occurances				
				if (*I == pastnumber){
					++count;
					//save count if greater than past counts and set mode
					if (count > modecount){
						modecount = count;
						result = *I;
					}
				}
				//reset count once number changes
				else if (*I != pastnumber){
					count = 0;
				}
				pastnumber = *I;
			}

			//return 3 if given no inputs
			if (inputsss == 0){
				return 3;
			}
		}

		//oddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
		else if (argument == "odd"){
			//stop at non number input
			while (std::cin >> in){
				//count input
				++inputsss;
				//test for odd
				if (in%2 == 1){
					//+1 to amount of odd numbers counted
					++count;
				}
				result = count;
			}

			//return 3 if given no inputs
			if (inputsss == 0){
				return 3;
			}
		}

		//evennnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
		else if (argument == "even"){
			//stop at non number input
			while (std::cin >> in){
				//count input
				++inputsss;
				//test for even
				if (in%2 == 0){	
					//+1 to amount of even numbers counted			
					++count;					
				}
			result = count;
			}

			//return 3 if given no inputs
			if (inputsss == 0){
				return 3;
			}
		}

		else if ( argument != "even" and argument != "odd" and argument != "mode" and argument != "mean" and argument != "sum") {
			return 2;
		}


		//print the result and end the program (if didn't exit early)
		std::cout << result << '\n';
		return 0;
	}

	//Return 1 when given no arguments
	else if (1 == argc) {
		return 1;
	}


	//improper/unexpected argument
	else {
		return 2;
	}

}











/*
BROFIST
//           __   
//      /'`/'  `/'  `.
//   /'/  /    /      /' `\
// ('(   '   '     '~/''   `)
//  \                 '    /
//   ''   \           _..'
//     \             (
*/

