#include "entity/spaceship.hpp"

spaceship::spaceship(const size_t col): entity(0, col, 2, 6, 3, "$", 0)
{}

spaceship::~spaceship()
{}

void	spaceship::process(env &e)
{
	this->_action_counter++;
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() + 1);
	if (_action_counter == _action) {
		e._add_entity(new rocket(this->_row, this->_col));
		this->_action_counter = 0;
	}
}
