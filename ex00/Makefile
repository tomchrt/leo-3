NAME     = bureaucrat
CXX      = c++
CFLAGS   = -Wall -Wextra -Werror -std=c++98 -g -MD -MP

SRCS     = main.cpp \
           Bureaucrat.cpp

OBJS     = $(SRCS:%.cpp=$(OBJ_D)%.o)

OBJ_D    = objects/

$(OBJ_D)%.o: %.cpp
	@mkdir -p $(OBJ_D)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile
	$(CXX) $(CFLAGS) $(OBJS) -o $@

DEPS = $(OBJS:.o=.d)

all: $(NAME)

-include $(DEPS)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re