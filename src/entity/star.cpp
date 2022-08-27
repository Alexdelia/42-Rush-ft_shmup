/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:16:00 by adelille          #+#    #+#             */
/*   Updated: 2022/08/27 15:03:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entity/star.hpp"

star::star(const size_t col): entity(0, col, -1, 1, 0, ".", 0)
{}

star::~star()
{}

void	star::process()
{
	mvaddstr(51, 0, "star::process()");
	this->set_row(this->get_row() + 1);
}
