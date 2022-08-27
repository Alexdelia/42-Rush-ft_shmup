/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 17:48:49 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"
#include "graphic.hpp"

int main(void)
{
	env e;

	if (!e.init())
		return (1);

	if (!graphic::menu(e))
		return (2);

	e.play();
	
	// save score
	return (0);
}
