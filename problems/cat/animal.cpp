#include <iostream>
//#include <animal.h> //incorrect

#include "animal.h" //correct

animal::animal()
{
	std::cout <<"animal constructor \n";
}
void animal::play() {
std::cout <<"animal play\n";
}

void animal::sound() {
	std::cout << "Animal sounds \n  ";
}

std::string animal::species() {
	return "generic";
}

animal::~animal(){
std::cout <<"animal desconstructor\n";
}

