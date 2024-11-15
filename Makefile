# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2022/08/28 22:39:43 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_shmup
CXX =	c++
RM = 	rm -rf

CXXFLAGS =	-Wall -Werror -Wextra
CXXFLAGS +=	-std=c++11

CXXFLAGS +=	-g3
# CXXFLAGS +=	-fsanitize=address

LKFLAGS =	-MMD -MP

#NCFLAGS =	-lncurses
NCFLAGS =	-std=c11
NCFLAGS +=	$(shell ncursesw5-config --cflags --libs)
#NCFLAGS +=	-D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600 -Wl,-Bsymbolic-functions -lncursesw -ltinfo

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	SRCS	#

SRCSPATH =	./src/
OBJSPATH =	./obj/
INC =		./inc/

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

#SRCS =		$(wildcard $(SRCSPATH)*.cpp) $(wildcard $(SRCSPATH)**/*.cpp)
SRCS =		$(call rwildcard,$(SRCSPATH),*cpp)
SRCSNAME =	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME =	$(SRCSNAME:.cpp=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))

# *************************************************************************** #

define	progress_bar
	@i=0
	@while [[ $$i -le $(words $(SRCS)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	@printf "$(B)]\r[$(D)"
endef

# *************************************************************************** #
#	RULES	#

$(OBJSPATH)%.o: $(SRCSPATH)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(LKFLAGS) -I$(INC) -c $< -o $@
	@printf "$(B)$(GRE)█$(D)"


all:		launch $(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"

launch:
	$(call progress_bar)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(NCFLAGS)
	
clean:
	@$(RM) $(OBJSPATH)

fclean:		clean
	@$(RM) $(NAME)
	@$(RM) null.d

re:			fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re launch

# **************************************************************************** #
