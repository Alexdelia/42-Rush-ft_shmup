#include "entity/decor.hpp"
#include "graphic.hpp"

decor::decor(const int row, const int col, const int speed, const std::string &sprite):
	entity(row, col, -1, speed, 0, sprite, CP_STAR, false, true, 1, 100)
{}

decor::~decor()
{}

void	decor::process(env &e)
{
	(void)e;
	this->_row++;
}
