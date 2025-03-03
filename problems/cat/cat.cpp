#include "cat.h"


cat::cat(){

	std::cout << "Cat constructor\n";
}
std::string cat::species() {
	return "cat";
}

void cat::sound() {
	std::cout << "meow";
}

cat::~cat(){

	std::cout <<"cat desconstructor\n";
}