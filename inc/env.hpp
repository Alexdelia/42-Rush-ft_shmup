/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:31:18 by adelille          #+#    #+#             */
/*   Updated: 2022/08/26 23:44:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_HPP
# define ENV_HPP

# include "shmup.hpp"

#define MIN_ROW	42
#define MIN_COL 42

class env
{
	public:
		env();
		~env();

		//int	key;

		bool	init(void);
		bool	resize(void);
		void	play(void);

		void	set_row(const int row);
		void	set_col(const int col);
		void	set_score(const size_t score);

		int		get_row(void) const;
		int		get_col(void) const;
		size_t	get_score(void) const;

	private:
		env(const env &src);
		env &operator=(const env &rhs);

		int		_row;
		int		_col;

		size_t	_score;
};

#endif
