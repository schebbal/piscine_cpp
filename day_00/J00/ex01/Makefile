# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/01 15:15:23 by schebbal     #+#   ##    ##    #+#        #
#    Updated: 2019/04/02 14:32:11 by schebbal    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

EXEC	= phonebook
SRCC	= Phonebook.class.cpp \
		  main.cpp
SRCO 	= $(SRCC:%.cpp=%.o)

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(EXEC)

%.o: %.cpp %.hpp

$(EXEC): $(SRCO)
		clang++ $(CFLAG) $^ -o $(EXEC)
		printf '\033[32m[ ✔ ] %s\n\033[0m' "Created phonebook"

clean:
		/bin/rm -rf $(SRCO)
		printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned phonebook"

fclean: clean
		/bin/rm -f $(EXEC)
		printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned phonebook"

re: fclean all

.PHONY: clean fclean re all
