/*
Lab7
Inheritance
Justen Yeung
*/

#include <iostream>
#include <string>
#include <vector>


class Shape {
public:
	//initialize variables
	float area = 0;
	float perimeter = 0;
	std::string name;
	virtual float get_perimeter() = 0;
	virtual float get_area() = 0;
	virtual ~Shape(){};
};

//Rectangleeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
class Rectangle : public Shape {
public:
	//specific variables
	float h;
	float w;
	//Shape variables altered to specifications
	float get_area(){
		area = h*w;
		return area;
	};
	float get_perimeter(){
		perimeter = h*2 + w*2;
		return perimeter;
	};
	//constructor
	Rectangle(float height, float width){
		h = height;
		w = width;
		name = "Rectangle";
	};
	virtual ~Rectangle(){};
};

//Circleeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
class Circle : public Shape {
public:
	float r;
	float get_area();
	float get_perimeter();
	//constructer
	Circle(float radius);
	virtual ~Circle(){};
};
//get_area and get_perimeter and counstructor could also be altered 
	//outside the class but this takes more lines
Circle::Circle(float radius){
	r = radius;
	name = "Circle";
};
float Circle::get_area(){
	area = 3.14159 * r * r;
	return area;
};
float Circle::get_perimeter(){
	perimeter = 2 * 3.14159 * r;
	return perimeter;
};


//Trianguruuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
class Triangle : public Shape {
public:
	float b;
	float h;
	float s1;
	float s2;
	float get_area(){
		area = b*h / 2;
		return area;
	};
	float get_perimeter(){
		perimeter = b + s1 + s2;
		return perimeter;
	};
	//constructor
	Triangle(float base, float height, float side1, float side2){
		b = base;
		h = height;
		s1 = side1;
		s2 = side2;
		name = "Triangle";
	};
	virtual ~Triangle(){};
};

//Squuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuure
class Square : public Rectangle {
public:
	Square(float side) : Rectangle(side, side){
		h = side;
		w = side;
		name = "Square";
	};
};


int main(int argc, char** argv){
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(3.5, 4.5));
    shapes.push_back(new Circle(2));
    shapes.push_back(new Triangle(4,3,5,6));
    shapes.push_back(new Square(4));
    
    for (Shape* s : shapes)
    {
         std::cout << "The area for this "<<s->name<<" is " << s->get_area() << std::endl;
         std::cout << "The perimeter for this "<<s->name<<" is " << s->get_perimeter() << std::endl;
    }
 
    //Delete the pointers at the end
    for (Shape* s : shapes)
    {
        delete s;
    }
    return 0;
}
 
/*

                  ____.----.
        ____.----'          \
        \                    \
         \                    \
          \                    \
           \          ____.----'`--.__
            \___.----'          |     `--.____
           /`-._                |       __.-' \
          /     `-._            ___.---'       \
         /          `-.____.---'                \
        /            / | \                       \
       /            /  |  \                   _.--'
       `-.         /   |   \            __.--'
          `-._    /    |    \     __.--'     |
            | `-./     |     \_.-'           |
            |          |                     |
            |          |                     |
            |          |                     |
            |          |                     |
            |          |                     |   
            |          |                     |
     _______|          |                     |_______________
            `-.        |                  _.-'
               `-.     |           __..--'
                  `-.  |      __.-'
                     `-|__.--'

*/


/*

BWAAAAAAAAAAAAAAAAAAAAAAAAA
　　　 /￣ ヽ 　　　　　　　　　　　　　　       ＿＿＿__　　　　　　　　　　     r'￣ヽ
 　　/　 　}｢}　　　　　　　　　 　     γ´ 　　 　 　 　    ｀ヽ　　 　 　 　  r{./r　}
　　 ｉ　　  /　　　　　　　　　   　　  /イ ／ /{　　 ﾊ　　　  　 ＼　　　　　   Υ '　 │
　　 | 　.′　　　　　　　　　     ィ´　::,y=ﾐ 乂: /=ﾐ}:.|　 　  丶 　 　 　 > 　 |
　  |￣￣l　　 　 　 　 　 　  / .::/　　′  　″ 　 \/! 　  i   ;　  　  | ￣￣|
　  |  　|　　　　　　　 　　　　 /　 ::{　 /￣￣￣｀ヽ 　′　 .:|:i 　 ;  　  |　 　 |
　　r―――　・・・￢　　　¨¨¨¨　￣￣￣￣￣￣￣￣￣￣{　}　|:|　j:! | :.い　　　|　 　 |
　　|　　　　　　　　　　　　　　　　　　　　　　　　　　　　 /\′　ｲ:|　/:|:|:::} }￣￣|　 　 |
　 　v　　　　　　　　　　　　　       　　　　　　 　  /\ |:|/::!::!::/ ﾉ　 　 }　 　 !
 　 　\/ 　 　 　＿＿＿＿＿＿＿＿＿＿＿＿＿____/\j:{::::::::イ 　　　/ 　 　./
　　 　 \/´　　　　　　　 　 　 　 　    　 　 　 　 　  ｢￣￣ う厂￣￣￣｀　ｰ{　　　 /
　　　　 |　　　　　　　　　　　　　　　　　       　 　 　 | 　　 て{ 　　　 　 { 　 　 /
　　　　 |　　　　　　　　　　　　　　　　　       　 　 　 |　 　 ￣ヾ.,　　　　　　　 　/
　　　　 |　　　　　　　　　　　　　　　      　　 　 　 　 |　　　 　 ￣´￣　￣￣｢￣￣
　　　　 |　　　　　　　　　　　　　　　　      　 　 　 　 |　　　　　　   　　　　　|
　　　　 |　　　　　　　　　　　　　      　　　　 　 　 　 |　　　　　　   　　　　　|
　　　　 |　　　　　　　　　　　　　　　　　       　 　 　 |　　   　　　　　　　　　|
*/