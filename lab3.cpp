/* 
lab3

Variance

Justen Yeung
*/

#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	
	//input into the vector
	float input   = 0.0;
	//used for counting how many inputs
	float numbers = 0.0;
	//used to help calculate the mean (all the numbers added together)
	float all     = 0.0;
	//used to help calculate the variance
	float all2 = 0.0;
	//The vector
	std::vector<float> vectaaa;
	

	//pushing the inputs into the vector
	while(std::cin >>input){
		vectaaa.push_back(input);

		//count the number of inputs
		++numbers;
	}
	

	//explicitly iterate through the vector
	for (std::vector<float>::iterator I = vectaaa.begin(); I != vectaaa.end(); ++I) {
		//add all the numbers together
		all = all + *I;

	}


	//How many numbers were inputted
	std::cout << "There were "<<numbers<< " numbers.\n";
	


	//if the user inputs numbers
	if ( 0 < numbers){
		//The Mean
		float mean = all/numbers;
		std::cout << "The average was "<<mean<<'\n';
		if (1 < numbers){
			//implicitly iterate through the vector
			for (float& element : vectaaa) {
				//subtract mean from all numbbers, square, then add together
				all2 = all2 + (element - mean)*(element - mean);
			}
			//The variance
			float variance = all2/--numbers;
			std::cout << "The sample variance was "<<variance<<'\n';
		}
	}

	//clear the vector
	vectaaa.clear();
	//exit
	return 0;
}
/*
BROFIST
                   __
             /´¯/'   '/´¯¯`·¸
          /'/  /    /      /¨¯\
        ('(   ´   ´     ¯~/'   ')
         \                 '    /
          ''   \           _.·´
            \             (
*/