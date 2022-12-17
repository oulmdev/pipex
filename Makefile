# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moulmoud <moulmoud@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 21:00:33 by moulmoud          #+#    #+#              #
#    Updated: 2022/12/16 19:24:52 by moulmoud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

COMPILER = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES = pipex.c ft_split_pro.c ft_split.c ft_strlen.c ft_strchr.c ft_strstr.c \
		ft_strjoin.c ft_substr.c

OFILES = pipex.o ft_split_pro.o ft_split.o ft_strlen.o ft_strchr.o ft_strstr.o \
		ft_strjoin.o ft_substr.o

RM = rm -rf

all : $(NAME)

$(NAME) : $(OFILES)
	@echo "\033[1;97m➤ Making pipex"
	$(COMPILER) $(CFLAGS) $(OFILES) -o $(NAME)
	@sleep 0.1
	@echo ""
	@sleep 0.2
	@for number in 1 2 3 4 ; do \
    	printf "\033[0;102m        \033[0m"; \
		sleep 0.2; \
	done
	@echo " 100%\n \033[1;32m\n✔ Done...\033[0m\n"
%.o:%.c pipex.h
	@echo "\033[1;92m✔  Compiling: \033[1;93m$<\033[0m"
	@sleep 0.1
	$(COMPILER) $(CFLAGS) -o $@ -c $<
	@echo ""
clean :
	@$(RM) $(OFILES)
	@echo "\033[1;97m➤  Remove Object files 🗑️\n"
	@sleep 0.2
	@for number in 1 2 3 4 ; do \
    	printf "\033[0;101m        \033[0m"; \
		sleep 0.1; \
	done
	@echo " 100%\n \033[1;32m\n✔ Done...\033[0m\n"
fclean :
	@$(RM) $(OFILES) $(NAME)
	@echo "\033[1;97m➤  Remove Object files && pipex 🗑️\n"
	@sleep 0.2
	@for number in 1 2 3 4 ; do \
    	printf "\033[0;101m        \033[0m"; \
		sleep 0.1; \
	done
	@echo " 100%\n \033[1;32m\n✔ Done...\033[0m\n"
re : fclean all
