# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jmonneri <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/04 12:19:28 by jmonneri     #+#   ##    ##    #+#        #
#    Updated: 2019/04/06 18:36:44 by schebbal    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re coffee test

# **************************************************************************** #
#                                    GENERAL                                   #
# **************************************************************************** #

NAME = ft_retro

CXX = clang++
CXXFLAGS += -Wall -Wextra -Werror

SRCDIR = ./sources/
OBJDIR = ./objects/
INCDIR = ./includes/

FILES = $(shell ls $(SRCDIR) | grep '\.cpp' | cut -d "." -f 1)
SRCS = $(addprefix $(SRCDIR), $(addsuffix .cpp, $(FILES)))
OBJS = $(addprefix $(OBJDIR), $(addsuffix .o, $(FILES)))
HEADS = $(shell ls $(INCDIR) | grep '\.hpp') 
HEADERS = $(addprefix $(INCDIR), $(HEADS))

# **************************************************************************** #
#                                    COLORS                                    #
# **************************************************************************** #

BBLACK = \033[40m
BRED = \033[41m
BGREEN = \033[42m
BYELLOW = \033[43m
BBLUE = \033[44m
BMAGENTA = \033[45m
BCYAN = \033[46m
BWHITE = \033[47m

TBLACK = \033[30m
TRED = \033[31m
TGREEN = \033[32m
TYELLOW = \033[33m
TBLUE = \033[34m
TMAGENTA = \033[35m
TCYAN = \033[36m
TWHITE = \033[37m

NORMAL = \033[0m
BOLD = \033[1m
UNBOLD = \033[21m
UNDERLINE = \033[4m
UNUNDERLINE = \033[24m
BLINK = \033[5m
UNBLINK = \033[25m
INVERT = \033[7m
UNINVERT = \033[27m

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(CXX) $(CXXFLAGS) -lncurses -o $(NAME) $(OBJS) 

$(OBJDIR):
	@mkdir $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(HEADERS)
	@printf %b "0️⃣  $(NAME): Compiling $@ from $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCDIR)
	@printf "\r" && printf "                                                                                                \r"

clean:
	@printf "$(TRED)[X]$(NORMAL) $(NAME): Deleting objects and temporary files... "
	@rm -rf $(OBJDIR)
	@printf "$(TGREEN)[V]$(NORMAL)\n"

fclean: clean
	@printf "$(TRED)[X]$(NORMAL) $(NAME): Deleting $(NAME)... "
	@rm -f $(NAME)
	@printf "$(TGREEN)[V]$(NORMAL)\n"

re: fclean all

test: all
	@./$(NAME)

coffee:
	@echo "                       ."
	@echo "                        \`:."
	@echo "                          \`:."
	@echo "                  .:'     ,::"
	@echo "                 .:'      ;:'"
	@echo "                 ::      ;:'"
	@echo "                  :    .:'"
	@echo "                   \`.  :."
	@echo "          _________________________"
	@echo "         : _ _ _ _ _ _ _ _ _ _ _ _ :"
	@echo "     ,---:\".\".\".\".\".\".\".\".\".\".\".\".\":"
	@echo "    : ,'\"\`::.:.:.:.:.:.:.:.:.:.:.::'"
	@echo "    \`.\`.  \`:-===-===-===-===-===-:'"
	@echo "      \`.\`-._:                   :"
	@echo "       \`-.__\`.               ,'"
	@echo "    ,--------\`\"\`-------------'--------."
	@echo "     \`\"--.__                   __.--\"'"
	@echo "             \`\"\"-------------\"\"'"
