##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

# Compilation flags
_TEST_FLAGS1_ = -I ./include/ -I ./lib/my/include/
_TEST_FLAGS2_ = -L ./.obj -lmy --coverage -lcriterion

# Directories
_DIRS1_ = ./src/*.c ./src/algorithm/*.c
_DIRS2_ = ./src/parsing/*.c ./lib/my/*.c

# Colours
_GREEN_ = \033[1;32m
_CYAN_ = \033[1;36m
_BLUE_ = \033[94m
_DEFAULT_ = \033[0m

SRC =	src/main.c \
		src/parsing/my_print_utils.c \
		src/parsing/init_struct.c \
		src/parsing/do_parsing.c \
		src/parsing/write_instruction.c \
		src/algorithm/do_algorithm.c \
		src/algorithm/car_wheels.c
# Directories
_DIRS1_ = ./src/*.c ./src/algorithm/*.c
_DIRS2_ = ./src/parsing/*.c ./lib/my/*.c

# Colours
_GREEN_ = \033[1;32m
_CYAN_ = \033[1;36m
_BLUE_ = \033[94m
_DEFAULT_ = \033[0m

SRC =	src/main.c \
		src/parsing/my_print_utils.c \
		src/parsing/init_struct.c \
		src/parsing/do_parsing.c \
		src/parsing/write_instruction.c \
		src/algorithm/do_algorithm.c \
		src/algorithm/car_wheels.c

NAME	=	ai

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./lib/my/include/ -I./include -g

all:		$(NAME)

$(NAME):	$(OBJ)
	make all -C lib/my/
	gcc -g3 -o $(NAME) $(OBJ) -L./lib/my -lmy $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)
	make fclean -C lib/my/
	rm -f unit_test-n4s_tests.gcno
	rm -f unit_test-n4s_tests.gcda
	rm -rf ./.obj
	rm -rf ./unit_test
	rm -rf ./coding-style-reports.log

re:			fclean all

tests_run: build_objects
	@rm -rf ./.obj/*.o
	@gcc -o unit_test tests/n4s_tests.c $(_TEST_FLAGS1_) $(_TEST_FLAGS2_)
	@echo "$(_GREEN_)Unit Tests:$(_DEFAULT_)"
	@./unit_test
	@gcovr --exclude ./tests

build_objects:
	@echo "$(_BLUE_)Building objects...$(_DEFAULT_)"
	@mkdir -p .obj
	@rm -rf ./.obj/*
	@gcc -c $(_TEST_FLAGS1_) $(_DIRS1_) $(_DIRS2_)
	@mv ./*.o ./.obj
	@rm ./.obj/main.o
	@ar rc ./.obj/libmy.a .obj/*.o
	@echo "$(_CYAN_)Sucess\n$(_DEFAULT_)"
