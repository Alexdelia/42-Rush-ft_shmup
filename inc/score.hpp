/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:44:35 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 17:46:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORE_HPP
# define SCORE_HPP

# include "env.hpp"
# include "graphic.hpp"

# include <iostream>
# include <fstream>

# ifndef SCORE_PATH
#  define SCORE_PATH	"./.score.txt"
# endif

# define MAX_READ_SCORE	42

typedef struct s_score
{
	std::string	username;
	size_t		score;
}				t_score;

class score
{
	public:
		static const size_t	max_read_score = 42;

		score(env &e);
		~score();

		bool	read_score();
		void	sort_score();
		bool	choose_score(env &e);
		bool	save_score(const env &e);

		std::vector<s_score>	s;
		std::vector<size_t>		sort;

	private:
		score();
		score(const score &src);
		score &operator=(const score &rhs);
};

#endif
