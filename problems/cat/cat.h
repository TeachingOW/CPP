#pragma once
#include "animal.h"
#include <iostream>

class cat : public animal {
public:
	cat();
	std::string species();

	void sound();
	~cat();
};
