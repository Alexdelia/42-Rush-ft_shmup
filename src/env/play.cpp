/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:03:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 12:03:16 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.hpp"

static void	spawn_star(const env &e)
{
	(void)e;
	return ;
}

void	env::play(void)
{
	int	key = 'p';

	while (!is_exit(key))
	{
		spawn_star(*this);
		clear();
		// std::cout << "play" << std::endl;
		mvaddstr(4, 4, "play");
		mvaddstr(0, 0, "              ");
		mvprintw(0, 0, "%d", key);

		key = getch();
	}
}
