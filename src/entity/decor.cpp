#include "entity/decor.hpp"
#include "graphic.hpp"
#include "env.hpp"
#include "entity/boss.hpp"

decor::decor(const int row, const int col, const int speed, const std::string &sprite):
	entity(row, col, -1, speed, 0, sprite, CP_DECOR, false, true, 1, 100)
{}

decor::~decor()
{}

void	decor::process(env &e)
{
	int cnt = e.get_boss()->get_action_counter();
	if (e.get_tick() % this->_speed == 0 && this->_row < 15)
		this->_row++;
	if (this->_row == 15)
	{
		if (cnt >= 160)
			cnt = 0;
		else if (cnt > 20 && cnt < 30)
			this->_col--;
		else if (cnt > 60 && cnt < 70)
			this->_col++;

		else if (cnt > 100 && cnt < 110)
			this->_col++;
		else if (cnt > 140 && cnt < 150)
			this->_col--;
	}
}