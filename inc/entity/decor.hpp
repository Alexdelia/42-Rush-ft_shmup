/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:40:08 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 22:40:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity.hpp"

class decor: public entity
{
	public:
		decor(const int row, const int col, const int speed, const std::string &sprite );
		virtual ~decor();
	
		virtual void	process(env &e);
};
