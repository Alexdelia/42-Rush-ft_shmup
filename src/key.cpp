/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:45:59 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 12:03:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.hpp"

bool	is_exit(const int key)
{
	return (key == KEY_DC
		|| key == KEY_END
		|| key == KEY_EXIT
		|| key == KEY_ESCAPE
		|| key == KEY_CC
		|| key == KEY_CD);
}