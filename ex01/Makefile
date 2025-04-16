SR = ./srcs/
INC = ./includes/
TARGET = libft.a
CFILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OFILES = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
HFILE = $(addprefix $(INC), ft.h)
SRCS = $(addprefix $(SR), $(CFILES))
OBJS = $(addprefix $(SR), $(OFILES))
FLAG = -Wall -Wextra -Werror
.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $(TARGET) $(OBJS) 

$(OBJS): $(SRCS)
	gcc $(FLAG) -c $(SRCS)
	cp $(OFILES) $(SR)
	rm $(OFILES)

clean:
	rm $(OBJS)

fclean: clean
	rm $(TARGET)

re: fclean all
