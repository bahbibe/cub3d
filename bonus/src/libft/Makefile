CFLAGS = -Wall -Werror -Wextra
SRCS = ft_atoi.c ft_putchar_fd.c  ft_strlen.c ft_bx.c ft_bzero.c ft_putendl_fd.c ft_strmapi.c ft_calloc.c ft_putnbr_fd.c ft_strncmp.c ft_isalnum.c\
		ft_putstr_fd.c ft_strnstr.c ft_isalpha.c ft_split.c ft_strrchr.c ft_isascii.c ft_strchr.c ft_strtrim.c ft_isdigit.c ft_memchr.c\
		ft_strdup.c ft_substr.c ft_isprint.c ft_memcmp.c ft_striteri.c ft_tolower.c ft_itoa.c ft_memcpy.c ft_strjoin.c ft_toupper.c\
		ft_memmove.c ft_strlcat.c ft_memset.c ft_strlcpy.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c
SRCS_OBG = $(SRCS:.c=.o)
BONUS_SRCS = ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c ft_lstiter_bonus.c ft_lstsize_bonus.c\
			ft_lstclear_bonus.c  ft_lstlast_bonus.c ft_lstmap_bonus.c
BONUS_OBG = $(BONUS_SRCS:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME): $(SRCS_OBG)
	ar rc $(NAME) $(SRCS_OBG)

bonus: $(BONUS_OBG)
	ar rc $(NAME) $(BONUS_OBG)

clean:
	rm -f $(SRCS_OBG) $(BONUS_OBG)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re