CXX := c++
CFLAGS := -std=c++98 -Wall -Wextra -Werror

SRCDIR := .
SRCS += $(SRCDIR)/main.cpp
SRCS += $(SRCDIR)/Base.cpp
SRCS += $(SRCDIR)/A.cpp
SRCS += $(SRCDIR)/B.cpp
SRCS += $(SRCDIR)/C.cpp
SRCS += $(SRCDIR)/func.cpp

OBJDIR := objs
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

NAME = a.out

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
