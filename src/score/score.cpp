/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:55:46 by adelille          #+#    #+#             */
/*   Updated: 2022/08/26 23:03:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.hpp"

static bool	write_score(t_env *e, char *username, const int fd)
{
	char	*tmp;

	tmp = ft_sttoa(e->score);
	if (!tmp)
		return (false);
	ft_putstr_fd(tmp, fd);
	free(tmp);
	ft_putstr_fd(" ", fd);
	tmp = ft_sttoa(e->top);
	if (!tmp)
		return (false);
	ft_putstr_fd(tmp, fd);
	free(tmp);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(username, fd);
	ft_putstr_fd("\n", fd);
	close(fd);
	return (true);
}

static void	get_username(t_env *e, char *username)
{
	size_t	i;

	clear();
	print_frame(e, CP_MENU);
	echo();
	attrset(A_BOLD);
	pmw(e, "Enter your name: ");
	e->key = getch();
	i = 0;
	while (i < 100 && e->key != '\n')
	{
		if (i > 0 && e->key == KEY_BACKSPACE)
			i--;
		else if (ft_isprint(e->key))
		{
			username[i] = (char)e->key;
			i++;
		}
		else if (is_exit(e->key) || e->key == KEY_RESIZE)
			break ;
		e->key = getch();
	}
	attrset(A_NORMAL);
	username[i] = '\0';
}

bool	save_score(t_env *e)
{
	int		fd;
	char	username[101];

	clear();
	print_frame(e, CP_SCORE);
	curs_set(1);
	attrset(A_BOLD | COLOR_PAIR(CP_SCORE));
	mvprintw(e->row / 2 - 3,
		(e->col - (ft_strlen(MSG_CUR_SCORE) + 1 + ft_stlen(e->score))) / 2,
		"%s %ld", MSG_CUR_SCORE, e->score);
	pmw(e, "do you want to save your score");
	attrset(A_BOLD);
	mvaddstr(e->row / 2 + 1, (e->col - 5) / 2, "[y/n]");
	move(e->row / 2 + 2, e->col / 2 - 1);
	attrset(A_NORMAL);
	e->key = getch();
	if (e->key != 'y' && e->key != 'Y' && e->key != '\n')
		return (true);
	get_username(e, username);
	fd = open(SCORE_PATH, O_CREAT | O_RDWR | O_APPEND, 0664);
	if (fd < 0)
		return (false);
	return (write_score(e, username, fd));
}

bool	score::score(const env &e)
{
	clear();
	graphic::print_frame_score(e, CP_SCORE);
	graphic::print_header_score(e);
	if (!read_score(s))
		pmw(e, "NO SCORE");
	else
	{
		sort_score(s, sort);
		print_score(e, s, sort);
	}
	if (getch() == KEY_RESIZE)
	{
		if (!resize(e))
			return (false);
		if (!choose_score(e))
			return (false);
	}
	curs_set(1);
	return (true);
}
