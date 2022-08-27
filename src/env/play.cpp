/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:03:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 18:23:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "shmup.hpp"
#include "entity/star.hpp"
#include "keys.hpp"
#include "entity/asteroid.hpp"
#include "entity/spaceship.hpp"


static size_t rand_n_spawn(const int col, const size_t min, const size_t max)
{
	return (rand() % (int)col * ((rand() % (max - min + 1)) + min) / 1000);
}

void	env::print_map()
{
	clear();
	for(std::unordered_set<entity *>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
	{
		attrset(COLOR_PAIR((*it)->get_color_pair()));
		mvaddstr((*it)->get_row(), (*it)->get_col(), (*it)->get_sprite().c_str());
		attrset(A_NORMAL);
	}
}

void	env::play()
{
	int	key = 'p';
	// tmp
	/*this->_win_row = 42;
	this->_win_col = 42;*/

	this->print_map();
	while (!keys::is_exit(key))
	{
		// debug key
		mvaddstr(49, 0, "              ");
		mvprintw(49, 0, "%d", key);

		// process position and action
		for(std::unordered_set<entity *>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
			(*it)->process(*this);

		this->_delete_out_of_bound();

		// spawn stars
		// const size_t r = rand_n_spawn(this->_win_col, 100, 200);
		// for (size_t i = 0; i < r; i++)
		// 	this->_add_entity(new star(rand() % this->_win_col));

		const size_t r_asteroids = rand_n_spawn(this->_win_col, 0, 20);
		for (size_t i = 0; i < r_asteroids; i++)
			this->_add_entity(new asteroid(rand() % this->_win_col));


		const size_t r_spaceships = rand_n_spawn(this->_win_col, 0, 15);
		for (size_t i = 0; i < r_spaceships; i++)
			this->_add_entity(new spaceship(rand() % this->_win_col));


		this->print_map();

		key = getch();
		if (key == KEY_RESIZE)
			if (!this->resize())
				return ;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
		this->_tick++;
	}
}
