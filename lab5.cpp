/*
lab5

Justen Yeung
*/

#include <iostream>
#include <string>
#include <vector>


class Person {
public:
	std::string name;
	int age;
};

std::vector<Person> sorttt(std::vector<Person> people){
	for(std::vector<Person>::iterator I = people.begin(); I!= people.end(); ++I){
		for(std::vector<Person>::iterator J = I; J != people.begin() and (*J).age < (*(J-1)).age; --J){
				std::swap(*J,*(J-1));
			}
		}
	for(std::vector<Person>::iterator I = people.begin(); I!= people.end(); ++I){
		//Swap from I down to begin until ordering is correct
		for(std::vector<Person>::iterator J = I; J != people.begin() and (*J).name < (*(J-1)).name; --J){
				std::swap(*J,*(J-1));
			}
	}
	return people;
}

void printtt(std::vector<Person> people){
	for (std::vector<Person>::iterator I = people.begin(); I != people.end(); ++I){
		std::cout<< (*I).name << ", "<< (*I).age << '\n';
	}
	return;
}
int main(int argc, char** argv){
	std::vector<Person> people;
	std::string name;
	int age;

	while (std::cin>>name>>age){
		Person hito;
		hito.name = name;
		hito.age = age;
		people.push_back(hito);
	}
	people = sorttt(people);
	printtt(people);
	return 0;
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