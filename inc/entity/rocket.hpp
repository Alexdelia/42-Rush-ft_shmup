#pragma once

#include "entity.hpp"

class rocket: public entity
{
	public:
		rocket(const int row, const int col);
		virtual ~rocket();
	
		virtual void	process(env &e);
};

