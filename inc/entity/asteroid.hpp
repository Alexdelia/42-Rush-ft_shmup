#pragma once

#include "entity.hpp"

class asteroid: public entity
{
	public:
		asteroid(const size_t col);
		virtual ~asteroid();
	
		virtual void	process(env &e);
};

