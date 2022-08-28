/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:20:13 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 09:29:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "entity/player.hpp"

void	env::_handle_input(const int key)
{
	if ((key == KEY_UP || key == 'w' || key == 'W' || key == 'z' || key == 'Z')
			&& this->_player->get_row() > 0)
		this->_player->set_row(this->_player->get_row() - 1);
	else if ((key == KEY_DOWN || key == 's' || key == 'S')
			&& this->_player->get_row() < this->_win_row)
		this->_player->set_row(this->_player->get_row() + 1);
	else if (key == KEY_RIGHT || key == 'd' || key == 'D')
	{
		if (this->_player->get_col() == this->_win_col - 1)
			this->_player->set_col(0);
		else
			this->_player->set_col(this->_player->get_col() + 1);
	}
	else if (key == KEY_LEFT || key == 'a' || key == 'A' || key == 'q' || key == 'Q')
	{
		if (this->_player->get_col() == 0)
			this->_player->set_col(this->_win_col - 1);
		else
			this->_player->set_col(this->_player->get_col() - 1);
	}
	else if (key == ' ')
		this->_player->spawn_rocket(*this);
	// maybe bomb
}
