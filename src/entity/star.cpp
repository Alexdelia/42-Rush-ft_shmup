/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:16:00 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 22:11:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/star.hpp"
#include "graphic.hpp"

star::star(const size_t col): entity(0, col, -1, 1, 0, ".", CP_STAR)
{}

star::~star()
{}

void	star::process(env &e)
{
	(void)e;
	this->set_row(this->get_row() + 1);
}
