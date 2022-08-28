/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_delete_entity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:16:16 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 10:34:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"

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

void	env::_delete_out_of_bound()
{
	std::unordered_set<entity *>::iterator it = this->_entities.begin();

	while (it != this->_entities.end())
	{
		if ((*it)->get_row() < 0
			|| (*it)->get_row() >= this->_win_row
			|| (*it)->get_col() < 0
			|| (*it)->get_col() >= this->_win_col)
		{
			delete *it;
			it = this->_entities.erase(it);
		}
		else
			++it;
	}
}
