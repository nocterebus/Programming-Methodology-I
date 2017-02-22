/*
*Lab 2 
*
*drawing BOXESSSS
*
*Written by Justen Yeung
*/

#include <iostream>

int main(int argc, char** argv){
	if (7 != argc) {
		cout<<"Incorrect number of arguments!\n";
		return 0;
	}
		//string str(argv[6]);
		int columns = std::stoi(std::string (argv[1]));
		int rows = std::stoi(std::string (argv[2]));
		int column_offset = std::stoi(std::string (argv[3]));	
		int row_offset = std::stoi(std::string (argv[4]));
		int width = std::stoi(std::string (argv[5]));
		int height = std::stoi(std::string (argv[6]));


	for (int row = 0; row <= rows; ++row) {
		for(int column = 0; column <= columns; ++column) {
			if (row > row_offset and row <= row_offset + height and column > column_offset and column <= column_offset + width) {
				cout<<'X';
			}
			else{
				cout<<' ';
			}
		}
		//Go to next row
		cout<<'\n';
	}
	return 0;
}