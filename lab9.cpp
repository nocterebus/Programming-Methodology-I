

//Justen Yeung
//lab9.cpp
//queue






#include <iostream>
#include <queue>
#include <stack>
#include <list>

template <typename taipu>
class myQueue {
private:
	std::stack<taipu> input, output;
public:
	taipu front();
	taipu back();
	void push(taipu value);
	void pop();
	unsigned int size();
	bool empty();
};


template <typename taipu>
taipu myQueue<taipu>::front() {
	while (!input.empty()){
		for(int i = 0;i < input.size(); ++i){
			output.push(input.top());
			input.pop();
		}
	}
	return output.top();
}

template <typename taipu>
taipu myQueue<taipu>::back() {
	return input.top();
}
template <typename taipu>
void myQueue<taipu>::push(taipu value) {
	input.push(value);
}
template <typename taipu>
void myQueue<taipu>::pop() {
	while (!input.empty()){
		for(int i = 0;i < input.size(); ++i){
			output.push(input.top());
			input.pop();
		}
	}
	output.pop();
	while (!output.empty()){
		for(int i = 0;i < output.size(); ++i){
			input.push(output.top());
			output.pop();
		}
	}
}
template <typename taipu>
unsigned int myQueue<taipu>::size() {
	return input.size()+output.size();
}
template <typename taipu>
bool myQueue<taipu>::empty() {
	return input.empty();	
}


int main(int argc, char**argv){
    myQueue<int> q1, q2;
    
    for(int i = 0; i < 10; ++i){
        q1.push(i);
    }
    std::cout<< "Initial Queue:"<<'\n';
    while(!q1.empty()){
        std::cout << q1.front() << " " ;
        q2.push(q1.front());
        q1.pop();
    }
    std::cout<<'\n'<<"Size of Q2 (Q1 Reversed): "<<q2.size()<<'\n';
    std::cout<<"Back element of Q2: "<<q2.back()<<'\n';
    
}




//Result should be
//Initial Queue:
//0 1 2 3 4 5 6 7 8 9
//Size of Q2 (Q1 Reversed): 10
//Back element of Q2: 9
