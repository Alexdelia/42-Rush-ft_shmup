/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:29:09 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 19:38:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class boss: public entity
{
	public:
		boss(const int col);
		virtual ~boss();
	
		virtual void	process(env &e);
};
