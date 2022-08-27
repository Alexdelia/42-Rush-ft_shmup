/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:33:38 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 17:32:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.hpp"

int	r(const int val)
{
	return ((val * 1000) / 256);
}

static void	create_colors_front(void)
{}

static void	create_colors_back(void)
{
	init_color(COLOR_B_64, r(0xf6), r(0x5e), r(0x3b));
	init_color(COLOR_B_2048, r(0xed), r(0xc2), r(0x20));
}

static void	init_pairs(void)
{}

static void	main_colors(void)
{
	init_color(C_LOW_GREEN, r(0x34), r(0x8c), r(0x46));
	init_color(C_WINDOW, r(0x31), r(0x28), r(0x21));
	init_color(C_BOARD, r(0x84), r(0x79), r(0x6b));
}

static void	main_pairs(void)
{
	init_pair(CP_RED, COLOR_RED, C_WINDOW);
	init_pair(CP_GREEN, COLOR_GREEN, C_WINDOW);
	init_pair(CP_MENU, COLOR_MAGENTA, C_WINDOW);
	init_pair(CP_PLAY, COLOR_GREEN, C_WINDOW);
	init_pair(CP_BOARD, C_WINDOW, C_BOARD);
	init_pair(CP_SCORE, COLOR_B_2048, C_WINDOW);
	init_pair(CP_EXIT, COLOR_B_64, C_WINDOW);
	init_pair(CP_WINDOW, COLOR_WHITE, C_WINDOW);
}

bool	graphic::init_color(void)
{
	if (!has_colors())
	{
		std::cout << "ERROR: your terminal does not support colors" << std::endl;
		return (false);
	}
	else if (!can_change_color())
	{
		std::cout << "ERROR: your terminal does not support color change" << std::endl;
		return (false);
	}

	start_color();

	create_colors_front();
	create_colors_back();
	main_colors();
	main_pairs();
	init_pairs();

	bkgd(COLOR_PAIR(CP_WINDOW));

	return (true);
}
