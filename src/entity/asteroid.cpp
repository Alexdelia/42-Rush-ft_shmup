#include "entity/asteroid.hpp"

asteroid::asteroid(const size_t col): entity(0, col, 0, 2, 0, "*", 0)
{}

asteroid::~asteroid()
{}

void	asteroid::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() + 1);
}
