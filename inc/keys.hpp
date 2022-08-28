/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:18:20 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 16:38:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_HPP
# define KEYS_HPP

# define KEY_ESCAPE	27
# define KEY_CC		3
# define KEY_CD		4

#include <ncurses.h>

class keys
{
	public:
		static bool	is_exit(const int key);
	
	private:
		keys();
		keys(const keys &);
		~keys();
		keys &operator=(const keys &);
};

#endif
