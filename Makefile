########################################
# LIGHTNING COMMAND LINE TOOL MAKEFILE #
# Created by abclive                   #
# Creation under MIT License           #
# Have fun                             #
########################################

NAME	=	lightning
VERSION =	0.1

#Colors utilities
COLOR_BLUE	 = \033[33;34m
COLOR_YELLOW = \033[33;33m
COLOR_GREEN  = \033[33;32m
COLOR_RED	 = \033[33;31m
COLOR_CLEAN  = \033[33;0m

SRC		=	BundleGeneration \
			Command			 \
			Utils			 \
			main			 \

# Compiler options
CXX			=	clang++
CFLAGS		=	-Wall -Wextra -Werror
CXXFLAGS	=	-std=c++11 -Weffc++

.PHONY: all clean fclean re
.IMPLICITS:

all: $(NAME)

$(NAME): $(addsuffix .o, $(SRC))
	@echo "$(COLOR_BLUE)Lightning Builder $(COLOR_YELLOW)v$(VERSION)"
	@echo "$(COLOR_CLEAN)-- Compiling files ..."
	@$(CXX) -o $(NAME) $(addsuffix .cpp, $(SRC))
	@echo "$(COLOR_GREEN)== DONE ==$(COLOR_CLEAN)"

%.o: %.cpp
	@$(CXX) $(CFLAGS) $(CXXFLAGS) -c $<

clean:
	@echo "$(COLOR_RED)-- Cleaning $(NAME)$(COLOR_CLEAN)"
	@rm -rf $(addsuffix .o, $(SRC))

fclean: clean
	@echo "$(COLOR_RED)-- Deleting $(NAME)$(COLOR_CLEAN)"
	@rm -f $(NAME)

re: fclean all
