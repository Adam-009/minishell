SRC = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./ft_strcmp.c ./ft_atoll.c ./ft_atol.c ./ft_printf/ft_printf.c ./ft_printf/c.c ./ft_printf/i.c ./ft_printf/s.c ./ft_printf/p.c ./ft_printf/u.c ./ft_printf/x.c ./ft_isalnum.c ./ft_split.c ./ft_strtrim.c ./ft_memmove.c ./ft_substr.c  ./ft_strmapi.c ./ft_itoa.c ./ft_striteri.c ./ft_strjoin.c  ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_calloc.c ./ft_strlcpy.c ./ft_putchar_fd.c ./ft_isdigit.c ./ft_strlcat.c ./ft_strlen.c ./ft_strdup.c ./ft_strrchr.c ./ft_atoi.c ./ft_isalpha.c ./ft_isprint.c ./ft_memset.c ./ft_strncmp.c ./ft_tolower.c ./ft_bzero.c ./ft_isascii.c ./ft_memchr.c ./ft_strchr.c ./ft_strnstr.c ./ft_toupper.c ./ft_memcmp.c ./ft_memcpy.c
HEADER = ./libft.h
NAME = libft.a
OBJS = $(SRC:.c=.o)
CC = cc -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
