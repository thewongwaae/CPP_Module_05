NAME	= Form
CPP		= c++
FLAGS	= -Wall -Wextra -Werror -I -std=c++98
RM		= rm -rf

SRC		= Bureaucrat.cpp Form.cpp main.cpp
INC		= Bureaucrat.hpp Form.hpp

OBJ		= $(SRC:%.cpp=%.o)

all : $(NAME)

%.o : %.cpp $(INC)
	@printf "\033[0;33mCompiling $<\033[0m\n"
	@$(CPP) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "\n\033[0;32mSign those forms\033[0m"
	@$(CPP) $(FLAGS) $^ -o $@

clean:
	@echo "\033[0;31mRemoving objects...\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@echo "\033[0;31mInto the fireplace\033[0m"
	@$(RM) $(NAME)

re : fclean all