/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:31:18 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 15:15:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_HPP
# define ENV_HPP

#include "entity/entity.hpp"

#include <ncurses.h>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <thread>

#define MIN_WIN_ROW	42
#define MIN_WIN_COL	42

class entity;

class env
{
	private:
		int		_win_row;
		int		_win_col;
		size_t 	_tick;
		size_t	_score;
		std::unordered_set<entity *>	_entities;

	public:
		env();
		~env();

		//int	key;

		bool	init();
		//bool	resize();
		void	play();
		void	print_map();

		int		get_win_row() const;
		int		get_win_col() const;
		size_t	get_tick() const;
		size_t	get_score() const;

		void	set_win_row(const int row);
		void	set_win_col(const int win_col);
		void	set_score(const size_t score);
		void	_add_entity(entity *e);

	private:
		env(const env &src);
		env &operator=(const env &rhs);

		void	_add_entities(const std::vector<entity *> &entities);
		void	_delete_entity(entity *e);
		void	_delete_entities();
		void	_delete_out_of_bound();
};

#endif
