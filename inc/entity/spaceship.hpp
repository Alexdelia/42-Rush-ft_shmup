#pragma once

#include "entity.hpp"
#include "rocket.hpp"

class spaceship: public entity
{
	public:
		spaceship(const size_t col);
		virtual ~spaceship();
	
		virtual void	process(env &e);
};

