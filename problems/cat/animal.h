#pragma once
#include <string>

	class animal {

	public:
		animal();
		 void play();

		 virtual void sound();

		std::string species();

		virtual ~animal();
	};
