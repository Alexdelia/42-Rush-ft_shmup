/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_save_score.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:35:11 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 17:37:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "score.hpp"
#include "keys.hpp"

#include <string.h>

bool	score::read_score()
{
	/*char	*file;
	size_t	size;
	int		fd;

	fd = open(SCORE_PATH, O_RDONLY);
	if (fd < 0)
		return (false);
	file = gal(fd, &size, TRUE);
	if (!file)
		return (false);
	save_score_from_file(s, file, size);
	free(file);
	close(fd);*/
	return (true);
}

static std::string	get_username(const env &e)
{
	std::string	username;
	int			key;
	size_t		i;

	clear();
	graphic::print_frame(e.get_win_row(), e.get_win_col(), CP_MENU);
	echo();
	attrset(A_BOLD);
	graphic::pmw(e.get_win_row(), e.get_win_col(), "Enter your name: ");

	key = getch();
	i = 0;
	while (key != '\n')
	{
		if (i > 0 && key == KEY_BACKSPACE)
			i--;
		else if (isprint(key))
		{
			username[i] = (char)key;
			i++;
		}
		else if (keys::is_exit(key) || key == KEY_RESIZE)
			break ;
		key = getch();
	}
	attrset(A_NORMAL);
	username[i] = '\0';
	return (username);
}

bool	score::save_score(const env &e)
{
	std::ofstream	ofs;
	std::string		username;
	int				key;

	if (!e.get_score())
		return (false);

	clear();
	graphic::print_frame(e.get_win_row(), e.get_win_col(), CP_SCORE);
	curs_set(1);
	attrset(A_BOLD | COLOR_PAIR(CP_SCORE));
	mvprintw(e.get_win_row() / 2 - 3,
		(e.get_win_col() - strlen(MSG_CUR_SCORE) + 1 + graphic::ft_stlen(e.get_score())) / 2,
		"%s %ld", MSG_CUR_SCORE, e.get_score());
	graphic::pmw(e.get_win_row(), e.get_win_col(), "do you want to save your score ?");
	attrset(A_BOLD);
	mvaddstr(e.get_win_row() / 2 + 1, (e.get_win_col() - 5) / 2, "[y/n]");
	move(e.get_win_row() / 2 + 2, e.get_win_col() / 2 - 1);
	attrset(A_NORMAL);

	key = getch();
	if (key != 'y' && key != 'Y' && key != '\n')
		return (true);

	username = get_username(e);
	ofs.open(SCORE_PATH, std::ios::in | std::ios::out | std::ios::app | std::fstream::out);
	if (!ofs)
		return (false);
	ofs << e.get_score() << ' ' << username << std::endl;
	ofs.close();

	return (true);
}