/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:44:35 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 00:29:31 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORE_HPP
# define SCORE_HPP

# include "shmup.hpp"

# ifndef SCORE_PATH
#  define SCORE_PATH	"./.score.txt"
# endif

typedef struct s_score
{
	std::string	username;
	size_t		score;
}				t_score;

class score
{
	public:
		static const size_t	max_read_score = 42;

		score(const env &e);
		~score();

		bool	choose_score(const env &e);
		bool	save_score(const env &e);

		std::vector<s_score>	s;
		std::vector<size_t>		sort;

	private:
		score();
		score(const score &src);
		score &operator=(const score &rhs);
};

#endif
