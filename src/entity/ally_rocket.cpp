/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ally_rocket.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:44:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 13:10:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/ally_rocket.hpp"
#include "graphic.hpp"

ally_rocket::ally_rocket(const int row, const int col, const int attack_power):
	entity(row, col, 1, 1, 0, "'", CP_PLAYER, false, false, 1, attack_power)
{}

ally_rocket::~ally_rocket()
{}

void	ally_rocket::process(env &e)
{
	if (e.get_tick() % this->_speed == 0)
		this->_row--;
}
