/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:03:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 14:50:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "shmup.hpp"
#include "entity/star.hpp"

static size_t rand_n_spawn(const int row, const size_t min, const size_t max)
{
	return (rand() % (int)row * ((rand() % (max - min + 1)) + min) / 100);
}

void	env::print_map()
{
	clear();
	for (std::unordered_map<size_t, entity>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
	{
		// color
		mvaddstr(it->second.get_row(), it->second.get_col(), it->second.get_sprite().c_str());
	}
}

void	env::play()
{
	int	key = 'p';

	// tmp
	this->_win_row = 42;
	this->_win_col = 42;

	this->print_map();
	while (!is_exit(key))
	{
		// debug key
		mvaddstr(49, 0, "              ");
		mvprintw(49, 0, "%d", key);

		// process position and action
		for (std::unordered_map<size_t, entity>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
			it->second.process();

		this->_delete_out_of_bound();

		// spawn stars
		const size_t r = rand_n_spawn(this->_win_row, 10, 20);
		for (size_t i = 0; i < r; i++)
			this->_add_entity(star(rand() % this->_win_col));

		this->print_map();

		key = getch();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
	}
}
