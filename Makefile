NAME	= push_swap
PS_MAIN	= srcs/push_swap.c
SRCS	= srcs/operation/opr_push.c \
			srcs/operation/opr_reverse.c \
			srcs/operation/opr_rotate.c \
			srcs/operation/opr_swap.c \
			srcs/sorting/sorting_large.c \
			srcs/sorting/sorting_small.c \
			srcs/sorting/sorting_tiny.c \
			srcs/sorting/sorting.c \
			srcs/sorting/sorting_finding.c \
			srcs/utils/create_tab.c \
			srcs/utils/manage_input.c \
			srcs/utils/valid_checker_1.c \
			srcs/utils/valid_checker_2.c \
			srcs/error/error_msg.c \
			srcs/error/free.c
OBJS	= $(SRCS:.c=.o)

CHECKER_NAME	= checker
CHECKER_MAIN	= srcs/checker/checker.c
CHECKER_SRCS	= srcs/checker/checker_utils.c
CHECKER_OBJS	= $(CHECKER_SRCS:.c=.o)
INCS	= includes/
CFLAGS	= gcc -Wall -Werror -Wextra -g

all: $(NAME) $(CHECKER_NAME)

bonus: $(CHECKER_NAME)

$(NAME):
	@$(CFLAGS) -I $(INCS) $(PS_MAIN) $(SRCS) -o $(NAME)
	@echo "/// ----- pop_swoosh is ready to ... ------ ///"

$(CHECKER_NAME):
	@$(CFLAGS) -I $(INCS) $(CHECKER_MAIN) $(SRCS) $(CHECKER_SRCS) -o $(CHECKER_NAME)
	@echo "/// ----- checker is ready too ... ------ ///"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(CHECKER_OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(CHECKER_NAME)
	@rm -rf $(NAME).dSYM
	@rm -rf $(CHECKER_NAME).dSYM

re: fclean all

.PHONY: all clean fclean re
