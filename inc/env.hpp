/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:31:18 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 13:06:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_HPP
# define ENV_HPP

#include "entity.hpp"

#include <ncurses.h>
#include <vector>
#include <unordered_map>

#define MIN_WIN_ROW	42
#define MIN_WIN_COL	42

class env
{
	public:
		env();
		~env();

		//int	key;

		bool	init(void);
		//bool	resize(void);
		void	play(void);

		void	add_entity(entity e);
		void	add_entities(const std::vector<entity> &entities);
		void	delete_entity(const size_t id);
		void	delete_entities(const std::vector<size_t> &ids);

		void	set_win_row(const int row);
		void	set_win_col(const int win_col);
		void	set_score(const size_t score);

		int		get_win_row(void) const;
		int		get_win_col(void) const;
		size_t	get_score(void) const;

	private:
		env(const env &src);
		env &operator=(const env &rhs);

		int		_win_row;
		int		_win_col;
		size_t	_score;
		size_t	_next_id;
		std::unordered_map<size_t, entity>	_entities;
};

#endif
