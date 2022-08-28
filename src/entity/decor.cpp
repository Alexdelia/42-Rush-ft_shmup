#include "entity/decor.hpp"
#include "graphic.hpp"

decor::decor(const int row, const int col, const int speed, const std::string &sprite):
	entity(row, col, -1, speed, 0, sprite, CP_STAR, false, true, 1, 100)
{}

decor::~decor()
{}

void	decor::process(env &e)

{
	if (e.get_tick() % this->_speed == 0 && this->_row < 15)
		this->_row++;

	if (this->_row == 15)
	{
		if (this->_action_counter >= 160)
			this->_action_counter = 0;

		if (this->_action_counter > 0 && this->_action_counter < 10)
			boss_shoot(e, this->_col, this->_row);
		else if (this->_action_counter > 20 && this->_action_counter < 30)
			this->_col--;
		else if (this->_action_counter > 40 && this->_action_counter < 50)
			boss_shoot(e, this->_col, this->_row);
		else if (this->_action_counter > 60 && this->_action_counter < 70)
			this->_col++;
		else if (this->_action_counter > 80 && this->_action_counter < 90)
			boss_shoot(e, this->_col, this->_row);
		else if (this->_action_counter > 100 && this->_action_counter < 110)
			this->_col++;
		else if (this->_action_counter > 120 && this->_action_counter < 130)
			boss_shoot(e, this->_col, this->_row);
		else if (this->_action_counter > 140 && this->_action_counter < 150)
			this->_col--;

		this->_action_counter++;
	}
}