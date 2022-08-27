/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:46:39 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 12:53:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "shmup.hpp"

#include <vector>

class entity
{
	public:
		entity();
		~entity();
		entity(const entity &src);
		entity &operator=(const entity &rhs);

		int	get_row() const;
		int	get_col() const;

		int	get_zindex() const;

		const std::string	&get_sprite() const;
		int					get_color_pair();

		virtual void				process();
		virtual std::vector<entity>	spawner();
	
	private:

		int			_row;
		int			_col;

		int			_zindex;

		int			_speed;
		int			_action;

		std::string	_sprite;
		int			_color_pair;
};
