/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:31:18 by adelille          #+#    #+#             */
/*   Updated: 2022/08/26 22:13:35 by adelille         ###   ########.fr       */
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

		int	key;

		bool	init(void);
		bool	resize(void);
		void	play(void);

		void	set_row(const int row);
		void	set_col(const int col);

		int		get_row(void) const;
		int		get_col(void) const;

	private:
		env(const env &src);
		env &operator=(const env &rhs);

		int	_row;
		int	_col;
};

#endif
