/*
Lab 4
Recursive function
Justen Yeung
*/

#include <iostream>

//collatz function included before Main
int collatz (int start, int steps = 0){
	
	//Stopping condition
	if(start == 1){
		std::cout<<start<<'\n';
		std::cout<<"For a total of "<<steps<<" steps.\n";
		return 1;
	}

	//If the user inputs 0
	else if (start == 0){
		std::cout << "Your input is "<<start<<'\n';
		return 0;
	}

	//If the user inputs anything greater than 1
	else {		
		//If the number is currently odd
		if (start%2 == 1){
			//print the number
			std::cout <<start<<" ";
			//step + 1
			++steps;
			//multiply by 3 and add 1
			return collatz(start*3+1,steps);
		}
		//If the number is currently even
		else{
			//print the number
			std::cout <<start<<" ";
			//Step + 1
			++steps;
			//divide by 2
			return collatz(start/2,steps);
		}
	}
}
int a = 0;
int steps = 0;
//Main Function
int main (int argc, char** argv){
	
	
	std::cout << "Please enter the start number here:\n";
	std::cin >> a;
	collatz(a, steps);
	return 0;
}




























/*
BROFIST
                  __   
             /'`/'  `/'  `.
          /'/  /    /      /' `\
        ('(   '   '     '~/''   `)
         \                 '    /
          ''   \           _..'
            \             (
*/

