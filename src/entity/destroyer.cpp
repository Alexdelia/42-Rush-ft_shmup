
#include "entity/destroyer.hpp"

destroyer::destroyer(const size_t col): entity(0, col, 3, 8, 400, "$", 0)
{}

destroyer::~destroyer()
{}

void	destroyer::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->set_row(this->get_row() + 1);
	if (_action_counter == _action) {
		e.add_entity(new rocket(this->_row + 1, this->_col, 0));
		e.add_entity(new rocket(this->_row + 1, this->_col, 1));
		e.add_entity(new rocket(this->_row + 1, this->_col, -1));
		this->_action_counter = 0;
	} else
		this->_action_counter++;

}
