/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:43:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 09:43:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class asteroid: public entity
{
	public:
		asteroid(const size_t col);
		virtual ~asteroid();
	
		virtual void	process(env &e);
};

