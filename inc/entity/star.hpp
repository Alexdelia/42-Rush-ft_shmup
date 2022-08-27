/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:16:08 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 14:59:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class star: public entity
{
	public:
		star(const size_t col);
		virtual ~star();
	
	protected:
		virtual void	_process();
};
