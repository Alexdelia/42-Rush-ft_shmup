/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_delete_entity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:16:16 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 21:23:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "entity/player.hpp"

void	env::add_entity(entity *entity)
{
	this->_entities.insert(entity);
}

void	env::_add_entities(const std::vector<entity *> &entities)
{
	for (std::vector<entity *>::const_iterator it = entities.begin(); it != entities.end(); ++it)
		this->_entities.insert(*it);
}

void	env::_delete_entity(entity *e)
{
	delete e;
	this->_entities.erase(e);
}

void	env::_delete_entities()
{
	for (std::unordered_set<entity *>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
		delete *it;
	this->_entities.clear();
}

void	env::_kill_out_of_bound()
{
	for (std::unordered_set<entity *>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
	{
		if ((*it)->get_row() < 0
			|| (*it)->get_row() >= this->_win_row
			|| (*it)->get_col() < 0
			|| (*it)->get_col() >= this->_win_col)
			(*it)->set_hp(0);
	}
}

void	env::_delete_killed()
{
	std::unordered_set<entity *>::iterator it = this->_entities.begin();

	while (it != this->_entities.end())
	{
		if ((*it)->get_hp() <= 0)
		{
			delete *it;
			it = this->_entities.erase(it);
		}
		else
			++it;
	}
}

void	env::add_multi()
{
	this->_player2 = new player(this->_win_row, (int)this->_win_col * 1.5);
	add_entity(this->_player2);
}
