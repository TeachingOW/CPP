#include <iostream>
#include "animal.h"
#include "cat.h"
using namespace std;


int main(int argc, char** argv) {
	/*
	animal a;
	a.play();
	a.sound();
	cout << a.species() <<"\n";

	cat c;
	c.sound(); 
	cout << "\n" <<c.species() <<"\n";
*/

animal *pa=new cat();
pa->play();
(*pa).play();
pa->sound();
(*pa).sound();
std::cout <<"\n";
delete pa;


pa=new animal();
pa->play();
(*pa).play();
pa->sound();
(*pa).sound();
std::cout <<"\n";
delete pa;
}