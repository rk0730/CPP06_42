CXX := c++
CFLAGS := -std=c++98 -Wall -Wextra -Werror

SRCDIR := .
SRCS += $(SRCDIR)/main.cpp
SRCS += $(SRCDIR)/ScalarConverter.cpp

OBJDIR := objs
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

NAME = convert

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CFLAGS) -c -MMD -MP $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
