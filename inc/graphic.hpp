/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:11:13 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 19:25:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

# include "env.hpp"

# define MIN_WIN_ROW	30
# define MIN_WIN_COL	40

# define STATS_W		30
# define STATS_W_S		"                              "

# define MSG_PLAY		"PLAY"
# define MSG_EXIT		"EXIT"
# define MSG_WON		"WON"
# define MSG_LOST		"GAMEOVER"

# define C_LOW_GREEN	232
# define C_WINDOW		233
# define C_BOARD		234
# define COLOR_B_64		231
# define COLOR_B_2048	230

# define C_PLAYER		229
# define C_STAR			228
# define C_ROCKET		227
# define C_HP			226

# define CP_0			1
# define CP_GREEN		3
# define CP_MENU		5
# define CP_PLAY		6
# define CP_BOARD		7
# define CP_SCORE		9
# define CP_EXIT		10
# define CP_WINDOW		11
# define CP_RED			12

# define CP_PLAYER		13
# define CP_STAR		14
# define CP_ROCKET		15
# define CP_HP			16

class score;

class graphic
{
	public:
		static bool init_color(void);
		
		static bool	menu(env &e);
		static void	print_menu(const env &e);
		static void	print_frame(const int row, const int col, const int color);

		static void	print_stats(env &e);
		static void	print_header_score(const env &e);
	
		static void		pmw(const int row, const int col, const std::string &str);
		static bool		valid_size(const int row, const int col);
		static void		frame_resize(const int row, const int col);
		static size_t	ft_stlen(size_t n);
	
	private:
		graphic();
		~graphic();
		graphic(const graphic &src);
		graphic &operator=(const graphic &rhs);
};

#endif
