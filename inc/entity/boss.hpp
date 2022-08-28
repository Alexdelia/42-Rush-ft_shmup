/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:29:09 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 19:31:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class boss: public entity
{
	private:
		int		_shoot_timer;

	public:
		boss(const int row, const int col);
		virtual ~boss();
	
		virtual void	process(env &e);

		void			shoot(env &e);
	
	private:
		void			_spawn_rocket(env &e);
};
