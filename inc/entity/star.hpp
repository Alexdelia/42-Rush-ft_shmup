/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:16:08 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 19:51:55 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class star: public entity
{
	public:
		star(const int col);
		virtual ~star();
	
		virtual void	process(env &e);
};
