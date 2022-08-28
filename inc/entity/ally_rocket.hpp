/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ally_rocket.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:43:43 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 09:44:17 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class ally_rocket: public entity
{
	public:
		ally_rocket(const int row, const int col);
		virtual ~ally_rocket();
	
		virtual void	process(env &e);
};