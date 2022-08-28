/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:52 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 20:53:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/boss.hpp"
#include "entity/lazer.hpp"
#include "graphic.hpp"

boss::boss(const int col):
	entity(4, col, 0, 5, 0, "x", CP_RED, true, true, 210, 100)
{
	this->_action_counter = 0;
}

boss::~boss()
{}

inline static void boss_shoot(env &e, const int col, const int row)
{
	for (size_t i = 0; i < 5; i++)
		e.add_entity(new lazer(row + 1, col - 2 + i));
}

void	boss::process(env &e)
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
int boss::get_row() const { return (this->_row); }
int boss::get_col() const { return (this->_col); }
int boss::get_speed() const { return (this->_speed); }
int boss::get_action_counter() const { return (this->_action_counter); }
