NAME = minishell

# Directories
SRC_DIR = ./src
TOKENIZER_DIR = $(SRC_DIR)/tokenizer
CHECK_COMM_DIR = $(SRC_DIR)/check_comm
OPENFILE_DIR = $(SRC_DIR)/openfile
EXEC_DIR = $(SRC_DIR)/pipex/exec
COMMANDS_DIR = $(EXEC_DIR)/commands
PARSING_DIR = $(SRC_DIR)/parsing
LIBFT_PATH = ./libft
PIPEX_DIR = $(SRC_DIR)/pipex
MINI_ENV = $(SRC_DIR)/mini_env


# Source files
SRCS = \
	$(SRC_DIR)/minishell.c \
	$(MINI_ENV)/mini_env_list.c \
	$(MINI_ENV)/mini_env_utils.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/history.c \
	$(TOKENIZER_DIR)/tokenizer_1.c \
	$(TOKENIZER_DIR)/tokenizer_2.c \
	$(TOKENIZER_DIR)/command_list.c \
	$(TOKENIZER_DIR)/tokenizer_utils.c \
	$(CHECK_COMM_DIR)/check_comm.c \
	$(CHECK_COMM_DIR)/check_comm_utils.c \
	$(OPENFILE_DIR)/openfile.c \
	$(OPENFILE_DIR)/openfile_utils.c \
	$(COMMANDS_DIR)/pwd.c \
	$(COMMANDS_DIR)/env.c \
	$(COMMANDS_DIR)/echo.c \
	$(COMMANDS_DIR)/cd.c \
	$(COMMANDS_DIR)/exit.c \
	$(COMMANDS_DIR)/export.c \
	$(COMMANDS_DIR)/unset.c \
	$(EXEC_DIR)/exec.c \
	$(PARSING_DIR)/parsing.c \
	$(PARSING_DIR)/quote.c \
	$(PARSING_DIR)/redirection.c \
	$(PIPEX_DIR)/pipex.c \
	$(PIPEX_DIR)/pipex_utils.c \
	$(PIPEX_DIR)/pipex_utils2.c \
	$(PIPEX_DIR)/pipex_list.c \
	$(PIPEX_DIR)/token_check.c \
	$(PIPEX_DIR)/process.c \
	$(PIPEX_DIR)/pipe_handle.c \
	$(PIPEX_DIR)/redir_handle.c \
	$(PIPEX_DIR)/heredoc_handle.c \

	

# Define path for all sources
vpath %.c $(SRC_DIR) $(TOKENIZER_DIR) $(CHECK_COMM_DIR) $(OPENFILE_DIR) $(COMMANDS_DIR) $(PARSING_DIR) $(PIPEX_DIR) $(EXEC_DIR) $(MINI_ENV)

ODIR = obj

# allow to compile .o files in obj directory
OBJS = $(patsubst %.c,$(ODIR)/%.o,$(notdir $(SRCS)))

RM = rm -rf

# Libft
LIBFT = $(LIBFT_PATH)/libft.a

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

# Build rules
all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -lreadline

$(ODIR)/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	$(RM) obj
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
