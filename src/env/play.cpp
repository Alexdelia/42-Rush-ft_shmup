/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:03:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 10:48:47 by cmenasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "shmup.hpp"
#include "keys.hpp"
#include "entity/player.hpp"
#include "entity/star.hpp"
#include "entity/asteroid.hpp"
#include "entity/spaceship.hpp"
#include "entity/destroyer.hpp"

static size_t rand_n_spawn(const int col, const size_t min, const size_t max)
{
	return (rand() % (int)col * ((rand() % (max - min + 1)) + min) / 1000);
}

void	env::print_map()
{
	erase();
	for(std::unordered_set<entity *>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
	{
		attrset(COLOR_PAIR((*it)->get_color_pair()));
		mvaddstr((*it)->get_row(), (*it)->get_col(), (*it)->get_sprite().c_str());
		//attrset(A_NORMAL);
	}
	//refresh();
}

void	env::_collision()
{
	for (std::unordered_set<entity *>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
	{
		for (std::unordered_set<entity *>::iterator it2 = it; it2 != this->_entities.end(); ++it2)
		{
			if ((*it)->get_is_enemy() != (*it2)->get_is_enemy()
				&& (*it)->get_row() == (*it2)->get_row()
				&& (*it)->get_col() == (*it2)->get_col())
			{
				if ((*it)->get_is_killable())
					(*it)->set_hp((*it)->get_hp() - (*it2)->get_attack_power());
				if ((*it2)->get_is_killable())
					(*it2)->set_hp((*it2)->get_hp() - (*it)->get_attack_power());
				
				this->_score += (*it)->get_attack_power();
			}
		}
	}
}

void	env::_spawn_script()
{
		// spawn stars
		const size_t r = rand_n_spawn(this->_win_col, 100, 200);
		for (size_t i = 0; i < r; i++)
			this->add_entity(new star(rand() % this->_win_col));

		const size_t r_asteroids = rand_n_spawn(this->_win_col, 0, 20);
		for (size_t i = 0; i < r_asteroids; i++)
			this->add_entity(new asteroid(rand() % this->_win_col));

		const size_t r_spaceships = rand_n_spawn(this->_win_col, 0, 15);
		for (size_t i = 0; i < r_spaceships; i++)
			this->add_entity(new spaceship(rand() % this->_win_col));
      
    const size_t r_destroyers = rand_n_spawn(this->_win_col, 0, 15);
		for (size_t i = 0; i < r_destroyers; i++)
			this->add_entity(new destroyer(rand() % this->_win_col));
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
		// process position and action
		for(std::unordered_set<entity *>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
			(*it)->process(*this);

		this->_kill_out_of_bound();
		this->_collision();
		if (this->_player->get_hp() <= 0)
			return ;
		this->_delete_killed();
		this->_spawn_script();

		// gained hp on tick
		this->_handle_input(key);

		this->print_map();

		key = 0;
		key = getch();
		if (key == KEY_RESIZE)
			if (!this->resize())
				return ;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / FPS));
		this->_tick++;
	}
}
