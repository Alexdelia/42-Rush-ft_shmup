/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:46:39 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 11:15:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "shmup.hpp"

class entity
{
	public:
		entity();
		~entity();

		int	get_row() const;
		int	get_col() const;

		int	get_zindex() const;

		const std::string	&get_sprite() const;
		int					get_color_pair();

		virtual void				process() const = 0;
		virtual std::vector<entity>	spawner() const = 0;
	
	private:
		entity(const entity &src);
		entity &operator=(const entity &rhs);

		int			_row;
		int			_col;

		int			_zindex;

		int			_speed;
		int			_action;

		std::string	_sprite;
		int			_color_pair;
};

#endif
