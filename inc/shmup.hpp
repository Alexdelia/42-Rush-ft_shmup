/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:52:52 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 12:14:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <ncurses.h>
# include <iostream>
# include <fstream>

# include "env.hpp"
# include "graphic.hpp"
# include "entity.hpp"

# define KEY_ESCAPE	27
# define KEY_CC		3
# define KEY_CD		4

bool	is_exit(const int key);
