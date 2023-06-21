# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 01:47:42 by jocaball          #+#    #+#              #
#    Updated: 2023/06/21 01:48:51 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
BLACK	  =	\033[0;30m
RED		  =	\033[1;91m
GREEN	  =	\033[1;92m
YELLOW	  = \033[0;93m
BLUE	  = \033[0;94m
MAGENTA	  = \033[0;95m
CYAN	  = \033[0;96m
GRAY	  = \033[0;90m
WHITE	  = \033[0;97m

SNAME = server
CNAME = client

SNAME_BONUS = server_bonus
CNAME_BONUS = client_bonus

SSRC = server.c ft_btoc.c
CSRC = client.c

SSRC_BONUS = server_bonus.c 
CSRC_BONUS = client_bonus.c

LIBFT = ./libft/libft.a

MAKE_LIBFT = @make -sC ./libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(SNAME) $(CNAME) 

$(NAME): 
	$(LIBFT) $(SNAME) $(CNAME)

$(LIBFT): 
	$(MAKE_LIBFT)

$(SNAME): $(LIBFT) $(SSRC)
	@$(CC) $(CFLAGS) $(SSRC) $(LIBFT) -o $(SNAME)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(SNAME)$(GREEN) has been created\n$(DEF_COLOR)"

$(CNAME): $(LIBFT) $(CSRC)
	@$(CC) $(CFLAGS) $(CSRC) $(LIBFT) -o $(CNAME)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(CNAME)$(GREEN) has been created\n$(DEF_COLOR)"

clean :
	$(MAKE_LIBFT) clean 

fclean : clean
	rm -f $(SNAME) $(CNAME) $(SNAME_BONUS) $(CNAME_BONUS)
	$(MAKE_LIBFT) fclean

re : fclean all
