#pragma once

#include "entity.hpp"

class decor: public entity
{
	public:
		decor(const int row, const int col, const int speed, const std::string &sprite);
		virtual ~decor();
	
		virtual void	process(env &e);
};
