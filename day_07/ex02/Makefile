# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/10 13:46:11 by schebbal     #+#   ##    ##    #+#        #
#    Updated: 2019/04/10 17:06:33 by schebbal    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

EXEC	= array
SRCC	= main.cpp 
SRCO 	= $(SRCC:%.cpp=%.o)

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(EXEC)

%.o: %.cpp %.hpp

$(EXEC): $(SRCO)
		clang++ $(CFLAG) $^ -o $(EXEC)
		printf '\033[32m[ ✔ ] %s\n\033[0m' "Created array"

clean:
		/bin/rm -rf $(SRCO)
		printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned array"

fclean: clean
		/bin/rm -f $(EXEC)
		printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned array"

re: fclean all

.PHONY: clean fclean re all