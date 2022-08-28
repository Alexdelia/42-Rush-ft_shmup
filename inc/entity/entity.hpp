/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:46:39 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 10:52:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_HPP
# define ENTITY_HPP

#include "../shmup.hpp"
#include "../env.hpp"

#include <iostream>
#include <string>
#include <vector>

class env;

class entity
{
	protected:
		int			_row;
		int			_col;

		int			_zindex;

		int			_speed;
		int			_action;
		int			_action_counter;

		std::string	_sprite;
		int			_color_pair;

		bool		_is_killable;
		bool		_is_enemy;

	public:
		entity();
		entity(const int row,
			const int col,
			const int zindex,
			const int speed,
			const int action,
			const std::string &sprite,
			const int color_pair,
			const bool is_killable,
			const bool is_enemy);
		entity(const entity &src);
		virtual ~entity();
		entity &operator=(const entity &rhs);

		int	get_row() const;
		int	get_col() const;

		int	get_zindex() const;

		const std::string	&get_sprite() const;
		int					get_color_pair();

		void	set_row(const int row);
		void	set_col(const int col);

		virtual void				process(env &e);
		virtual std::vector<entity>	spawner();
};

#endif
