/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:37:51 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 10:52:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/entity.hpp"

entity::entity(): _row(0), _col(0), _zindex(0), _speed(0), _action(0), _action_counter(0), _color_pair(0), _is_killable(true), _is_enemy(true)
{
	this->_sprite = "";
}

entity::entity(
	const int row,
	const int col,
	const int zindex,
	const int speed,
	const int action,
	const std::string &sprite,
	const int color_pair,
	const bool is_killable,
	const bool is_enemy
	):
	_row(row),
	_col(col),
	_zindex(zindex),
	_speed(speed), 
	_action(action),
	_action_counter(action),
	_sprite(sprite),
	_color_pair(color_pair),
	_is_killable(is_killable),
	_is_enemy(is_enemy)
{
	this->_sprite = sprite;
}

entity::~entity()
{}

entity::entity(const entity &src)
{
	*this = src;
}

entity &entity::operator=(const entity &rhs)
{
	this->_row = rhs._row;
	this->_col = rhs._col;
	this->_zindex = rhs._zindex;
	this->_speed = rhs._speed;
	this->_action = rhs._action;
	this->_action_counter = rhs._action_counter;
	this->_sprite = rhs._sprite;
	this->_color_pair = rhs._color_pair;
	return (*this);
}

/*void	entity::process()
{
	this->_action_counter--;
	if (this->_action_counter == 0)
	{
		this->_action_counter = this->_action;
		// do something
	}
}*/

void	entity::process(env &e)
{
	(void)e;
}

std::vector<entity>	entity::spawner()
{
	return (std::vector<entity>());
}

int					entity::get_row() const { return (this->_row); }
int					entity::get_col() const { return (this->_col); }
int					entity::get_zindex() const { return (this->_zindex); }
const std::string	&entity::get_sprite() const { return (this->_sprite); }
int					entity::get_color_pair() { return (this->_color_pair); }

void				entity::set_row(const int row) { this->_row = row; }
void				entity::set_col(const int col) { this->_col = col; }
