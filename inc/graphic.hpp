/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:11:13 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 13:06:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

#include <ncurses.h>

#define MSG_CUR_SCORE	"SCORE"

class graphic
{
	public:
		graphic();
		~graphic();
	private:
		graphic(const graphic &src);
		graphic &operator=(const graphic &rhs);
};

#endif
