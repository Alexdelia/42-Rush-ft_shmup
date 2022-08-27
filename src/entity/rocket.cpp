#include "entity/rocket.hpp"

rocket::rocket(const int row, const int col): entity(row, col, 1, 4, 0, "!", 0)
{}

rocket::~rocket()
{}

void	rocket::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() + 1);
}
