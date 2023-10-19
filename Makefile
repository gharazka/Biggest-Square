NAME = BSQ

CC = cc

SOURCES = ft_putnbr.c read_file.c main.c check_file_errors.c check_map_errors.c biggest_square.c read_two.c 

MAP = python3 create_map.py

FLAGS = -Wall -Wextra -Werror -c

OBJ = *.o

HEAD = ft_func.h

RM = rm -f

all: ${NAME}

$(NAME):
	@$(CC) $(FLAGS) $(SOURCES) $(HEAD)
	@$(CC) $(OBJ) -o $(NAME)

noflags:
	cc $(SOURCES) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) map1

out: BSQ
	${MAP}
	./BSQ map1
