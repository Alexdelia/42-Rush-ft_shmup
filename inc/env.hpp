/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:31:18 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 14:41:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_HPP
# define ENV_HPP

#include "entity/entity.hpp"

#include <ncurses.h>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <thread>

#define MIN_WIN_ROW	42
#define MIN_WIN_COL	42

class env
{
	private:
		int		_win_row;
		int		_win_col;
		size_t	_score;
		size_t	_next_id;
		std::unordered_map<size_t, entity>	_entities;

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
		size_t	get_score() const;

		void	set_win_row(const int row);
		void	set_win_col(const int win_col);
		void	set_score(const size_t score);

	private:
		env(const env &src);
		env &operator=(const env &rhs);

		void	_add_entity(entity e);
		void	_add_entities(const std::vector<entity> &entities);
		void	_delete_entity(const size_t id);
		void	_delete_out_of_bound();
};

#endif
