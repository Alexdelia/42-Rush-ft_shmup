/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmup.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:52:52 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 14:45:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHMUP_HPP
# define SHMUP_HPP

# define FPS		10

# define KEY_ESCAPE	27
# define KEY_CC		3
# define KEY_CD		4

#include <ncurses.h>

bool	is_exit(const int key);

#endif
