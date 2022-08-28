/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:50:57 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 19:52:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class lazer: public entity
{
	public:
		lazer(const int row, const int col);
		virtual ~lazer();
	
		virtual void	process(env &e);
};