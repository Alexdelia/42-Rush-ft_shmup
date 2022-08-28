/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaceship.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:43:54 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 09:43:55 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"
#include "rocket.hpp"

class spaceship: public entity
{
	public:
		spaceship(const size_t col);
		virtual ~spaceship();
	
		virtual void	process(env &e);
};

