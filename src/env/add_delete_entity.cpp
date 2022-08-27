/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_delete_entity.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:16:16 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 12:50:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.hpp"
#include "env.hpp"
#include "entity.hpp"

void	env::add_entity(entity e)
{
	this->_entities[this->_next_id++] = e;
}

void	env::add_entities(const std::vector<entity> &entities)
{
	for (std::vector<entity>::const_iterator it = entities.begin(); it != entities.end(); ++it)
		this->add_entity(*it);
}

void	env::delete_entity(const size_t id)
{
	this->_entities.erase(id);
}

void	env::delete_entities(const std::vector<size_t> &ids)
{
	for (std::vector<size_t>::const_iterator it = ids.begin(); it != ids.end(); ++it)
		this->delete_entity(*it);
}
