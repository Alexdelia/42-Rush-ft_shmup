/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_delete_entity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:16:16 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 14:00:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"

void	env::_add_entity(entity e)
{
	this->_entities[this->_next_id++] = e;
}

void	env::_add_entities(const std::vector<entity> &entities)
{
	for (std::vector<entity>::const_iterator it = entities.begin(); it != entities.end(); ++it)
		this->_add_entity(*it);
}

void	env::_delete_entity(const size_t id)
{
	this->_entities.erase(id);
}

void	env::_delete_out_of_bound()
{
	for (std::unordered_map<size_t, entity>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
	{
		if (it->second.get_row() >= this->_win_row
			|| it->second.get_col() >= this->_win_col
			|| it->second.get_row() < 0
			|| it->second.get_col() < 0)
			this->_delete_entity(it->first);
	}
}
