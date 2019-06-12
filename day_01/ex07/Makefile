# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/03 18:56:53 by schebbal     #+#   ##    ##    #+#        #
#    Updated: 2019/04/03 19:02:53 by schebbal    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= replace
SRC		= main.cpp
CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME):
		clang++ $(CFLAG) $(SRC) -I . -o $(NAME)
		printf '\033[32m[ ✔ ] %s\n\033[0m' "Created replace"

clean:
		/bin/rm -f *.o
		printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned replace"

fclean: clean
		/bin/rm -f $(NAME)
		printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned replace"

re: fclean all
