# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 01:47:42 by jocaball          #+#    #+#              #
#    Updated: 2023/06/21 21:41:39 by jocaball         ###   ########.fr        #
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

SSRC = server.c
CSRC = client.c
INC  = minitalk.h

SSRC_BONUS = server_bonus.c 
CSRC_BONUS = client_bonus.c
INC_BONUS  = minitalk_bonus.h

LIBFT = ./libft/libft.a

MAKE_LIBFT = @make -sC ./libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(SNAME) $(CNAME) 

$(NAME): 
	$(LIBFT) $(SNAME) $(CNAME)

$(LIBFT): 
	$(MAKE_LIBFT)

$(SNAME): $(LIBFT) $(SSRC) $(INC)
	@$(CC) $(CFLAGS) $(SSRC) $(LIBFT) -o $(SNAME)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(SNAME)$(GREEN) has been created\n$(DEF_COLOR)"

$(CNAME): $(LIBFT) $(CSRC) $(INC)
	@$(CC) $(CFLAGS) $(CSRC) $(LIBFT) -o $(CNAME)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(CNAME)$(GREEN) has been created\n$(DEF_COLOR)"

bonus: $(SNAME_BONUS) $(CNAME_BONUS)

$(SNAME_BONUS): $(LIBFT) $(SSRC_BONUS) $(INC_BONUS)
	@$(CC) $(CFLAGS) $(SSRC_BONUS) $(LIBFT) -o $(SNAME_BONUS)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(SNAME_BONUS)$(GREEN) has been created\n$(DEF_COLOR)"

$(CNAME_BONUS): $(LIBFT) $(CSRC_BONUS) $(INC_BONUS)
	@$(CC) $(CFLAGS) $(CSRC_BONUS) $(LIBFT) -o $(CNAME_BONUS)
	@echo "$(GREEN)\n-------> Program $(YELLOW)$(CNAME_BONUS)$(GREEN) has been created\n$(DEF_COLOR)"

	
clean :
	$(MAKE_LIBFT) clean 

fclean : clean
	rm -f $(SNAME) $(CNAME) $(SNAME_BONUS) $(CNAME_BONUS)
	$(MAKE_LIBFT) fclean

re : fclean all
