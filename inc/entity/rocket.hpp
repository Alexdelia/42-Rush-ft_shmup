/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:43:35 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 09:43:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class rocket: public entity
{
	public:
		rocket(const int row, const int col);
		virtual ~rocket();
	
		virtual void	process(env &e);
};
