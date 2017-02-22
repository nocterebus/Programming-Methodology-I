/*
Lab6
classes and operators
Justen Yeung
*/

#include <iostream>

class Complex {
public:
	//parts of Complex class
	//multiplying by 1.0 didn't convert to float for division so 
		//parts created as float instead of int
	float real;
	float imaginary;

	//Constructor
	Complex (float a, float b) {
		real = a;
		imaginary = b;
	};
};



//Operator Ovaloadinnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
Complex operator+(Complex a, Complex b) {
	return Complex((a.real+b.real),
						(b.imaginary+a.imaginary));
}
Complex operator-(Complex a, Complex b) {
	return Complex((a.real-b.real),
						(a.imaginary-b.imaginary));
}
Complex operator*(Complex a, Complex b) {
	return Complex((a.real*b.real - a.imaginary*b.imaginary),
						(a.real*b.imaginary + b.real*a.imaginary));
}
Complex operator/(Complex a, Complex b) {
	return Complex(((a.real*b.real + a.imaginary*(-b.imaginary))*1.0/(
						(b.real*b.real)+(b.imaginary*b.imaginary))),

					((a.real*(-b.imaginary) + b.real*a.imaginary)*1.0/(
						(b.real*b.real)+(b.imaginary*b.imaginary))));
}


 //Also define the left stream operator:
std::ostream& operator<<(std::ostream& os, Complex c){
	 //print out the real part
	 os<<c.real;
	 //if the imaginary part is negative, don't print a "+"
	 if (c.imaginary < 0) {
	 	os<<c.imaginary<<"i";
	 }
	 else {
	 	os<<"+"<<c.imaginary<<"i";
	 }
	 return os;
}


int main(int argc,char** argv) {
//initialize imaginary numbers
Complex a(0,0);
Complex b(0,0);

	std::cout<<"Please enter the real part of your first number:";
	std::cin>> a.real;
	std::cout<<"Please enter the imaginary part of your first number:";
	std::cin>> a.imaginary;
	std::cout<<"Please enter the real part of your second number:";
	std::cin>> b.real;
	std::cout<<"Please enter the imaginary part of your second number:";
	std::cin>> b.imaginary;

	//additionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
	std::cout<<a<<" + "<<b<<" = "<<(a+b)<<'\n';
	//sbutractionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
	std::cout<<a<<" - "<<b<<" = "<<(a-b)<<'\n';
	//multiplyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
	std::cout<<a<<" * "<<b<<" = "<<(a*b)<<'\n';
	//b squaredddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
	std::cout<<b<<" * "<<b<<" = "<<(b*b)<<'\n';
	//divisionnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn
	std::cout<<a<<" / "<<b<<" = "<<(a/b)<<'\n';

	return 0;
}

/*

MESSAGE BOARD
　 　 　 　 ／　::::::::::::::＼:::::::＼
　　　　 　.::／:::::::::::::::|:::::::〈｢＼
　 　  /:.::/: :::::::::::::j:／〉:::::::〈
 　  /::.::i/ ::::::: /:::/｀''く／〉::-=ﾆV　　　　　  r‐v‐ｯ￢--､_
　  /:::.::i:::::／::厶:::/‐一　""ト--:::ﾍ-------}　|　| | '´|__________
  ,:.::.:: :::::::／ /:/　　　＿／ ﾍ::::|￣￣￣￣￣|　| |　し'ﾞ￣￣￣￣￣ ￣|
  ;:::::: i:::::／　 /／　斗ｯ七卞ﾘ　 Y ￣|　　　　 　  しﾍ_ﾉし'　 　　 　　　  　  |
  |:::::: i__彡＿　 ／　　　 乂＾(ソ　　　ん' |　　　　█▀▀ █▀█ █▀█ █▀█　　　　  　 |
  |:::::::| 斗ｯ七卞　　　　　 　／／／　　 ） |　　　　█░█ █ █ █ █ █ █　　　　  　 |
  |:.:|:::|ヽ乂＾(ソ　　　　　　　　　 　  　 ´ノ|　　　　▀▀▀ ▀▀▀ ▀▀▀ ▀▀  　 　 　  |
  |:.:|:::小 　 　 　 　丶　　　　　 　 　 /／]　　　　　　　　　　　　　　　　　　　 　  　 |
  |::,:::|-ﾍ／／　　　　 　ノ￣)　　　  /:｀ヽ|　    ┐　　　　　　　　　　　　　　    　 |
　 }:::,:::\//\　　　　　(_　　　　　　 .ｲ￣＼｝ 　／ｰﾉ　█▀▀ ▀█▀ █ █ █▀▀ █▀▀   |
  八:::,:::,　 ゝ　　　 　 　 　 　 ／　| 　　｣／　／　　▀▀█  █  █ █ █▀▀ █▀▀   |
　　  \/\::::,　 　 ｀ﾆ =-　,,_ 　　´　ﾏ)＞'　／　　　 ▀▀▀  ▀  ▀▀▀ ▀   ▀  　 「＼
　　　　 　 、:::,　　　　 　y‐j　　　 　　〃　 　ｰ┴‐┐　　　　　　　　　　　　　　　    　 　 | 　＼
　　　 　 　 ＼::,　　 　／ ノ|　　　　 //　　 ｰ＜丿　　　　　 　 　 　 　 　 　  　    |    ＼
　　　　　　 　  ＼:\/／／ _丿　 　 //　　　　 __〕　　　　　　　　　　　　　　　　　    　　|　　　   ＼
　　　　　　　　-‐＜＼〉 厶ﾆﾆ二二＞く/　　　　　､_　|　　　　　　　　　　　　　　　　 　    　 |
　　　　／|　〔　　　　　|　　　　／ 　　 ＼　　　／て ノ-------------_____________|＼  
*/