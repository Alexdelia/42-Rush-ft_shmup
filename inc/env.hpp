/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:31:18 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 15:42:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "entity/entity.hpp"

#include <ncurses.h>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <thread>

class entity;

class player;

class env
{
	private:
		int		_win_row;
		int		_win_col;
		size_t 	_tick;
		size_t	_score;
		std::unordered_set<entity *>	_entities;
		player							*_player;
		std::chrono::steady_clock::time_point _begin;

	public:
		env();
		~env();

		bool	init();
		bool	resize();
		void	play();
		void	gameover();
		void	print_map();

		int		get_win_row() const;
		int		get_win_col() const;
		size_t	get_tick() const;
		size_t	get_score() const;
		player	*get_player() const;
		std::chrono::steady_clock::time_point get_begin() const;

		void	set_win_row(const int row);
		void	set_win_col(const int win_col);
		void	set_score(const size_t score);
		void	set_begin(const  std::chrono::steady_clock::time_point begin);

		void	add_entity(entity *e);


	private:
		env(const env &src);
		env &operator=(const env &rhs);

		void	_add_entities(const std::vector<entity *> &entities);
		void	_delete_entity(entity *e);
		void	_delete_entities();
		void	_kill_out_of_bound();
		void	_delete_killed();

		void	_collision();

		void	_spawn_script();
		void	_handle_input(const int key);
};
