/*
Justen Yeung
Lab 8
Template for quicksort
*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
template <typename namba>
namba ptition(namba begin,namba end){
	//this should never be called with an empty range
	if (begin == end){
		return end;
	}
	namba pivot = begin;
	namba split = begin;
	for (namba I = ++begin; I != end; ++I){
		//Advance the split and swap if we find something <= *pivot
		if (*I <= *pivot){
			++split;
			std::swap(*I, *split);
		}
	} 
	//Move the pivot to the end of the split range
	std::swap(*split, *pivot);
	//The pivot is now at split so return that location
	return split;
}
template <typename namba>
void qsort(namba begin, namba end){
	//No need to sort with 0 or 1 elements
	if (2 > std::distance(begin, end)){
		return;
	}

	//Partition
	namba middle = ptition(begin,end);
	//Quicksort both sides
	qsort(begin, middle);
	//don't include pivot in the range
	++middle;
	qsort(middle, end);
}
//templated print
template<typename container>
void printcontainer (container& c){
	typedef typename container::iterator iterator;
	std::cout<<*c.begin();
	//++c.begin();
	for(iterator I = std::next(c.begin()); I != c.end(); ++I){
		std::cout<<", "<<*I;
	}
	std::cout<<'\n';
}

int main(int argc, char** argv){

std::vector<int> v = {5,1,4,2,8,18,3,33};
std::list<int> l = {23,14,31,57,28,49};



qsort(v.begin(),v.end() );

qsort(l.begin(),l.end() );

std::cout<<"The sorted vector is:\n";
printcontainer(v);

std::cout<<"The sorted list is:\n";
printcontainer(l);

	return 0;
}