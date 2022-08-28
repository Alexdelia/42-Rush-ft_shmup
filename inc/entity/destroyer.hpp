/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:40:03 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 22:40:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"
#include "rocket.hpp"

class destroyer: public entity
{
	public:
		destroyer(const size_t col);
		virtual ~destroyer();
	
		virtual void	process(env &e);
};

