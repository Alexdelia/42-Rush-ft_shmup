/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:11:13 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 11:26:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "shmup.hpp"

#define MSG_CUR_SCORE	"SCORE"

class graphic
{
	public:
		graphic();
		~graphic();

		static bool init_color(void);
		
		static bool	menu(void);
		static void	print_menu(void);

		static void	print_score(const env &e, const score &s);
		static void	print_frame_score(const env &e, const int color);
		static void	print_header_score(const env &e);
	
	private:
		graphic(const graphic &src);
		graphic &operator=(const graphic &rhs);
};