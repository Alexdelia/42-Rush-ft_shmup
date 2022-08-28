/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:50:55 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 19:53:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/lazer.hpp"
#include "graphic.hpp"

lazer::lazer(const int row, const int col):
	entity(row, col, -1, 1, 0, " ", CP_HP, false, true, 1, 5)
{}

lazer::~lazer()
{}

void	lazer::process(env &e)
{
	(void)e;
	this->_row++;
}
