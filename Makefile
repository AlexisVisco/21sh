#  ************************************************************************** #
#                                                           LE - /            #
#                                                               /             #
#    Makefile                                         .::    .:/ .      .::   #
#                                                  +:+:+   +:    +:  +:+:+    #
#    By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     #
#                                                  #+#   #+    #+    #+#      #
#    Created: 2018/02/12 12:37:15 by aviscogl     #+#   ##    ##    #+#       #
#    Updated: 2018/02/12 12:37:15 by aviscogl    ###    #+. /#+    ###.fr     #
#                                                          /                  #
#                                                         /                   #
#  ************************************************************************** #

NAME = 21sh
CC = gcc
CC_FLAGS = -g -Wall -Wextra -Werror

LFT_PATH = ./libft
SRC_PATH = ./src/
INC_PATH = -I ./includes -I $(LFT_PATH)/includes
OBJ_PATH = ./obj/
TOTAL_FILES := 137

SRC_NAME = \
shell.c \
shell_process.c\
\
lex/count_tokens.c \
lex/split.c \
lex/recognize.c \
lex/bad_format_sep.c \
\
messages/messages.c \
\
parser/block.c \
parser/analyze.c \
parser/extract_redir.c \
parser/slash.c \
parser/commentary.c \
parser/operator_error.c \
parser/parse_all.c \
parser/parse_and_or.c  \
\
init/init_shell.c \
init/set_env.c \
init/set_bin.c \
init/set_vars.c \
init/set_options.c \
init/set_builtins.c \
\
editor/deb_printer.c \
editor/editor.c \
editor/free_e_content.c \
editor/editor_insert.c \
editor/editor_insert_instant.c \
editor/readline.c \
editor/readline_raw.c \
editor/readline_notty.c \
editor/handle_keys.c \
editor/terminal_manager.c \
editor/history/origin.c \
editor/history/history.c \
editor/history/history_search.c \
editor/history/history_search_msg.c \
editor/history/history_file_managing.c \
editor/util/get_colums_len.c \
editor/util/get_cursor_pos.c \
editor/util/free_options.c \
editor/refresher/buf_append.c \
editor/refresher/refresh_line.c \
editor/refresher/set_colum.c \
editor/refresher/clean_and_go_up.c \
editor/refresher/clean_top_show_prompt.c \
editor/refresher/insert_new_line.c \
editor/refresher/move_cursor.c \
editor/refresher/clear_used_before.c \
editor/edit_fn/ef_clear_screen.c \
editor/edit_fn/ef_del_prev_word.c \
editor/edit_fn/ef_delete_curr_to_end.c \
editor/edit_fn/ef_delete_entire_line.c \
editor/edit_fn/ef_go_end.c \
editor/edit_fn/ef_go_home.c \
editor/edit_fn/ef_move_cursor_to.c \
editor/edit_fn/ef_move_up.c \
editor/edit_fn/ef_move_down.c \
editor/edit_fn/ef_move_word.c \
editor/edit_fn/ef_move_left.c \
editor/edit_fn/ef_move_right.c \
editor/edit_fn/ef_del_backspace.c \
editor/edit_fn/ef_del_simple.c \
editor/edit_fn/ef_swap_char.c \
editor/edit_fn/redirect_to_functions.c \
editor/completion/completion.c \
editor/completion/get_completions.c \
editor/completion/completion_printer.c \
editor/completion/get_completions_bin.c \
editor/completion/get_completions_env.c \
editor/completion/get_completions_path.c \
editor/completion/get_folder_from.c \
editor/completion/get_name_from.c \
editor/completion/set_word_info.c \
editor/completion/update_word.c \
editor/completion/word_is_env.c \
editor/completion/word_is_command.c \
editor/completion/word_is_path.c \
\
util/ft_levenshtein.c \
util/exit_shell.c \
util/ft_realloc.c \
util/free_tab.c \
util/ft_char_to_str.c \
util/env_to_array.c \
util/delete_first.c  \
util/ft_copy_str.c \
util/equal_char.c \
util/ft_tab_contain.c \
util/ask_line.c \
util/free_toks.c \
util/odd_quote.c \
util/multi_line.c \
util/replace_env_variables.c \
util/ft_repall.c \
util/remove_file.c \
util/ft_contain_any_seq.c \
util/util_command.c \
util/vint.c \
\
exec/signal.c \
exec/analyze_next_and_or.c  \
exec/core_exec.c \
exec/return_executable.c \
exec/redistribute_pipe_redir.c \
exec/exec_pipe.c  \
exec/open_file.c \
exec/heredoc.c \
exec/agregator.c \
exec/agregator_to_file.c \
exec/delete_redir.c \
\
builtins/b_env.c \
builtins/b_search_binary.c \
builtins/b_env_unset.c \
builtins/b_env_set.c \
builtins/b_pwd.c \
builtins/b_clear.c \
builtins/b_expr_eval.c \
builtins/b_cd.c \
builtins/history/b_history.c \
builtins/history/b_history_cmd.c \
builtins/history/b_history_func.c \
builtins/history/bh_append_history.c \
builtins/history/bh_clear_history.c \
builtins/history/bh_del_history_at.c \
builtins/history/bh_history_exec.c \
builtins/history/bh_history_help.c \
builtins/history/bh_history_non_read.c \
builtins/history/bh_history_read.c \
builtins/history/bh_show_history.c \
builtins/history/bh_write_history.c \
builtins/variables/b_export.c \
builtins/variables/b_typeof.c \
builtins/variables/b_unset.c \
builtins/variables/b_variables.c \
builtins/variables/core_variable.c \
builtins/variables/free_variable.c \
builtins/b_echo.c \
builtins/b_exit.c \
builtins/is_builtins.c \
\
expr/expr.c \
expr/custom_fun.c \
\


EDITOR_FOLDERS = editor editor/util editor/refresher editor/completion editor/keys_functions editor/edit_fn editor/history
OBJ_FOLDERS = $(EDITOR_FOLDERS) expr init builtins builtins/history builtins/variables exec lex messages parser util
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ_FOLDERS_BIS = $(addprefix $(OBJ_PATH),$(OBJ_FOLDERS))

COUNT := 0

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -L$(LFT_PATH) -lft
	@printf "\nDone.\n"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) $(OBJ_FOLDERS_BIS)
	@$(CC) $(CC_FLAGS) $(INC_PATH) -o $@ -c $^
	@printf "\r\e[0m\x1B[36m\e[21mCompiling C files \e[0m\e[32m["
	@printf " %.0s" {0..$(shell printf "%.0f" $(shell echo "scale=3; (${COUNT}/${TOTAL_FILES} * 100)" | bc))}
	@printf "ᗧ"
	@printf "•%.0s" {0..$(shell printf "%.0f" $(shell echo "scale=3; 100 - ((${COUNT}/${TOTAL_FILES} * 100))" | bc))}
	@printf "] %s" $(shell printf "%.0f" $(shell echo "scale=3; (${COUNT}/${TOTAL_FILES} * 100)" | bc))
	@printf " %%  \e[0m"
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))


clean:
	@printf "\x1B[36mCleaning files\n"
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

download_libft:
	@git clone https://github.com/AlexisVisco/libft/
	@cd libft && rm -rf .git

update_libft:
	@rm -rf ./libft
	@git clone https://github.com/AlexisVisco/libft/
	@cd libft && rm -rf .git

git_add:
	@git add includes/*.h
	@git add src/*
	@git add libft/src/*
	@git add libft/includes/*.h
	@git add libft/Makefile
	@git add Makefile
	@git add auteur
	@git add readme.md
	@git add CMakeLists.txt

norme:
	norminette $(SRC)
	norminette ./includes $(LFT_PATH)/includes

launch: $(NAME)
	@./$(NAME)

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re, download_libft, update_libft, git_add, norme
