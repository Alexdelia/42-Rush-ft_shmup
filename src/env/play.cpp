/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:03:49 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 21:21:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "graphic.hpp"
#include "shmup.hpp"
#include "keys.hpp"
#include "entity/player.hpp"
#include "entity/star.hpp"
#include "entity/asteroid.hpp"
#include "entity/spaceship.hpp"
#include "entity/destroyer.hpp"
#include "entity/boss.hpp"

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
	attrset(A_NORMAL);
	graphic::print_stats(*this);
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
				if ((*it)->get_sprite() != "🙭" && (*it2)->get_sprite() != "🙭" 
					&& (*it)->get_sprite() != "." && (*it2)->get_sprite() != ".")	
					this->_score += (*it)->get_is_enemy() ? (*it2)->get_attack_power() : (*it)->get_attack_power();
			}
		}
	}
}

void	env::_spawn_script(bool *b_boss)
{
	const int	now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - this->_begin).count();

	if (now < 0)
	{
	// spawn stars
	/*const size_t r = rand_n_spawn(this->_win_col, 100, 200);
	for (size_t i = 0; i < r; i++)
		this->add_entity(new star(rand() % this->_win_col));*/

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
	else if (now > 0 && *b_boss == false)
	{
		*b_boss = true;
		this->add_entity(new boss(this->_win_col / 2));


		this->add_entity(new decor(get_boss()->get_row(), get_boss->get_col(), get_boss()->get_speed(), "("));
		this->add_entity(new decor(get_boss()->get_row(), get_boss->get_col(), get_boss()->get_speed(), "("));
		this->add_entity(new decor(get_boss()->get_row(), get_boss->get_col(), get_boss()->get_speed(), "("));
		this->add_entity(new decor(get_boss()->get_row(), get_boss->get_col(), get_boss()->get_speed(), "("));
		this->add_entity(new decor(get_boss()->get_row(), get_boss->get_col(), get_boss()->get_speed(), "("));
		this->add_entity(new decor(get_boss()->get_row(), get_boss->get_col(), get_boss()->get_speed(), "("));
		this->add_entity(new decor(get_boss()->get_row(), get_boss->get_col(), get_boss()->get_speed(), "("));
		this->add_entity(new decor(get_boss()->get_row(), get_boss->get_col(), get_boss()->get_speed(), "("));





		this->_boss = new boss(this->_win_col / 2);
		this->add_entity(this->_boss);
	}
}

void	env::play()
{
	int		key = 'p';
	bool	boss = false;

	// tmp
	/*this->_win_row = 42;
	this->_win_col = 42;*/
	this->set_begin(std::chrono::steady_clock::now());
	this->print_map();
	while (!keys::is_exit(key))
	{
		// process position and action
		for(std::unordered_set<entity *>::iterator it = this->_entities.begin(); it != this->_entities.end(); ++it)
			(*it)->process(*this);

		this->_kill_out_of_bound();
		this->_collision();
		if (this->_player->get_hp() <= 0 || (this->_player2 && this->_player2->get_hp() <= 0)
				|| (this->_boss && this->_boss->get_hp() <= 0))
			return ;
		this->_delete_killed();
		this->_spawn_script(&boss);

		if (this->_player->get_hp() < 100 && this->_tick % 4 == 0)
		{
			this->_player->set_hp(this->_player->get_hp() + 1);
			if (this->_player->get_hp() >= 100)
				this->_player->set_hp(100);
		}
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
