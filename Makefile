##
## EPITECH PROJECT, 2020
## matchstick
## File description:
## Makefile
##

SRC	=	src/main.c															\
		src/matchstick.c													\
		src/map/init_map.c													\
		src/map/print_map.c													\
		src/map/remove_matches.c											\
		src/free_tab.c														\
		src/game/game_loop.c												\
		src/game/check_finish/check_defeat.c								\
		src/game/check_finish/check_win.c									\
		src/game/player/line_input.c										\
		src/game/player/matches_input.c										\
		src/game/player/player_turn.c										\
		src/game/ai/ai_turn.c

OBJ =	$(SRC:.c=.o)

NAME	=	matchstick

CPPFLAGS = -I	./include/	-I	../include/

all:	$(NAME)

lib:
		$(MAKE)	-C	lib/

$(NAME):	lib	$(OBJ)
	gcc -o $(NAME)	$(OBJ)	$(CPPFLAGS)	-L./lib	-lmy

clean:
	rm -f $(OBJ)
	$(MAKE)	clean	-C	lib/

fclean:	clean
	rm -f $(NAME)
	$(MAKE)	fclean	-C	lib/

re:	fclean	all
	$(MAKE)	re	-C	lib/

.PHONY:	all	lib	clean	fclean	re