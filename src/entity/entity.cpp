/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:37:51 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 12:44:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity.hpp"

entity::entity(): _row(0), _col(0), _zindex(0), _speed(0), _action(0), _color_pair(0)
{
	this->_sprite = "";
}

entity::~entity()
{
}

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
	this->_sprite = rhs._sprite;
	this->_color_pair = rhs._color_pair;
	return (*this);
}

int					entity::get_row() const { return (this->_row); }
int					entity::get_col() const { return (this->_col); }
int					entity::get_zindex() const { return (this->_zindex); }
const std::string	&entity::get_sprite() const { return (this->_sprite); }
int					entity::get_color_pair() { return (this->_color_pair); }
