/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:45:59 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 21:43:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.hpp"

bool	keys::is_exit(const int key)
{
	return (key == KEY_DC
		|| key == KEY_END
		|| key == KEY_EXIT
		|| key == KEY_ESCAPE
		|| key == KEY_CC
		|| key == KEY_CD
		|| key == 'e'
		|| key == 'E');
}