# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/01 08:54:14 by schebbal     #+#   ##    ##    #+#        #
#    Updated: 2019/04/02 14:13:38 by schebbal    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

EXEC	= megaphone
SRCC	= megaphone.cpp
SRCO 	= $(SRCC:%.cpp=%.o)
CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(EXEC)

%.o: %.cpp %.hpp
	    clang++ $(CFLAG) -o $@ -c $<

$(EXEC): $(SRCO)
		clang++ $(CFLAG) $^ -o $(EXEC)
			printf '\033[32m[ ✔ ] %s\n\033[0m' "Created megaphone"

clean:
		/bin/rm -rf $(SRCO)
			printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned megaphone"

fclean: clean
		/bin/rm -f $(EXEC)
		printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned megpahone"

re: fclean all

.PHONY: clean fclean re all
