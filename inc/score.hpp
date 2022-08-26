/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:44:35 by adelille          #+#    #+#             */
/*   Updated: 2022/08/26 23:09:14 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORE_HPP
# define SCORE_HPP

# include "shmup.hpp"

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

		std::vector<s_score>	s;
		std::vector<size_t>		sort;

	private:
		score();
		score(const score &src);
		score &operator=(const score &rhs);
};

#endif
