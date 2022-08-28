/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:20:13 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 21:46:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "entity/player.hpp"

void	env::_handle_input(const int key)
{
	if ((key == 'w' || key == 'W' || key == 'z' || key == 'Z')
			&& this->_player->get_row() > 0)
		this->_player->set_row(this->_player->get_row() - 1);
	else if ((key == 's' || key == 'S')
			&& this->_player->get_row() < this->_win_row - 1)
		this->_player->set_row(this->_player->get_row() + 1);
	else if (key == 'd' || key == 'D')
	{
		if (this->_player->get_col() == this->_win_col - 1)
			this->_player->set_col(0);
		else
			this->_player->set_col(this->_player->get_col() + 1);
	}
	else if (key == 'a' || key == 'A' || key == 'q' || key == 'Q')
	{
		if (this->_player->get_col() == 0)
			this->_player->set_col(this->_win_col - 1);
		else
			this->_player->set_col(this->_player->get_col() - 1);
	}
	else if (key == ' ')
		this->_player->shoot(*this);
	else if (this->_player2)
	{
		if (key == KEY_UP
				&& this->_player2->get_row() > 0)
			this->_player2->set_row(this->_player2->get_row() - 1);
		else if (key == KEY_DOWN
				&& this->_player2->get_row() < this->_win_row - 1)
			this->_player2->set_row(this->_player2->get_row() + 1);
		else if (key == KEY_RIGHT)
		{
			if (this->_player2->get_col() == this->_win_col - 1)
				this->_player2->set_col(0);
			else
				this->_player2->set_col(this->_player2->get_col() + 1);
		}
		else if (key == KEY_LEFT)
		{
			if (this->_player2->get_col() == 0)
				this->_player2->set_col(this->_win_col - 1);
			else
				this->_player2->set_col(this->_player2->get_col() - 1);
		}
		else if (key == '0')
			this->_player2->shoot(*this);
	}
}
