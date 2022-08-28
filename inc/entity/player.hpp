/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:33:29 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 09:28:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class player: public entity
{
	public:
		player(const int row, const int col);
		virtual ~player();
	
		virtual void	process(env &e);

		void			spawn_rocket(env &e);
};
