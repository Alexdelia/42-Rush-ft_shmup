/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:33:29 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 11:39:10 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class player: public entity
{
	private:
		int		_shoot_timer;

	public:
		player(const int row, const int col);
		virtual ~player();
	
		virtual void	process(env &e);

		void			shoot(env &e);
	
	private:
		void			_spawn_rocket(env &e);
};
