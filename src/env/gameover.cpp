/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:43:06 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 16:45:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "keys.hpp"
#include "entity/player.hpp"

void	env::gameover()
{
	this->get_player()->set_hp(0);
	erase();
	this->print_map();
	int	key = 'z';
	while (!keys::is_exit(key))
	{
		key = getch();
	}
}
