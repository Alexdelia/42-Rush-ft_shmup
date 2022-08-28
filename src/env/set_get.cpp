/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:53:02 by adelille          #+#    #+#             */
/*   Updated: 2022/08/28 14:46:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.hpp"

/*bool	env::set_files(const std::string &possible, const std::string &allowed)
{
	{
		struct stat	buffer;
		if (stat(possible.c_str(), &buffer) == -1)
		{
			std::cerr << s_error() << possible << " does not exist"
				<< "\033[0m" << std::endl;
			return (false);
		}
		else
			this->_possible_words_file = possible;
	}
	{
		struct stat	buffer;
		if (stat(allowed.c_str(), &buffer) == -1)
		{
			std::cerr << s_error() << allowed << " does not exist"
				<< "\033[0m" << std::endl;
			return (false);
		}
		else
			this->_allowed_words_file = allowed;
	}

	return (true);
}*/

void	env::set_win_row(const int win_row)
{ this->_win_row = win_row; }
void	env::set_win_col(const int win_col)
{ this->_win_col = win_col; }
void	env::set_score(const size_t score)
{ this->_score = score; }
void	env::set_begin(const std::chrono::steady_clock::time_point begin)
{ this->_begin = begin; }



int		env::get_win_row(void) const
{ return (this->_win_row); }
int		env::get_win_col(void) const
{ return (this->_win_col); }
size_t	env::get_score(void) const
{ return (this->_score); }
size_t	env::get_tick(void) const
{ return (this->_tick); }
player	*env::get_player(void) const
{ return (this->_player); }
std::chrono::steady_clock::time_point env::get_begin() const 
{ return this->_begin; }
