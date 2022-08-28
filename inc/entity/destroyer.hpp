#pragma once

#include "entity.hpp"
#include "rocket.hpp"

class destroyer: public entity
{
	public:
		destroyer(const size_t col);
		virtual ~destroyer();
	
		virtual void	process(env &e);
};

