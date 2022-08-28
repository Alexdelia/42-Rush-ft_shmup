/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:16:00 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 09:28:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/player.hpp"
#include "graphic.hpp"

player::player(const int row, const int col): entity(row - 2, (int)col / 2, 0, 0, 0, "^", CP_PLAYER)
{}

player::~player()
{}

void	player::process(env &e)
{
	(void)e;
}

void	player::spawn_rocket(env &e)
{
	(void)e;
}
