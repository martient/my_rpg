##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make libmy.a
##

SRC_DIR=	$(realpath .)

NAME_BIN =	libmy.a

SRC=		$(SRC_DIR)/*.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-I./include -Wall -W -pedantic

all:		$(NAME_BIN)

$(NAME_BIN):	$(SRC)
		gcc -c $(CFLAGS) $(SRC)
		ar rc $(NAME_BIN) $(OBJ)

clean:
		rm -rf $(SRC_DIR)/*.*o*

fclean:		clean
		rm -f $(NAME_BIN)

re:		fclean all
