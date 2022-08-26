/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/08/26 22:09:21 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.hpp"

int main(void)
{
	env e;

	if (!e.init())
		return (1);

	if (!graphic::menu())
		return (2);

	e.play();
	
	// save score
	return (0);
}
