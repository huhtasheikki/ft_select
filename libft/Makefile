#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 11:39:33 by hhuhtane          #+#    #+#              #
#    Updated: 2021/03/03 20:21:36 by hhuhtane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)

SRC_DIR = ./srcs/

SRCS = $(LIBFT_SRCS) $(PRINTF_SRCS)
LIBFT_SRCS = $(addprefix $(SRC_DIR), $(SRC))
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(PRINTF_SRC)

SRC =	ft_putchar.c \
		ft_memset.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isalpha.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memalloc.c \
		ft_atoi.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_strsplit.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		ft_array_len.c \
		ft_atoi_base.c \
		ft_abs.c \
		get_nbr.c \
		ft_itoa_base.c \
		ft_itoa_base_prefix.c \
		ft_uitoa_base.c \
		ft_intlen_base.c \
		ft_uintlen_base.c \
		ft_uintmaxlen_base.c \
		ft_uintmaxtoa_base.c \
		ft_ltoa_base.c \
		ft_ltoa_base_prefix.c \
		ft_ftoa.c \
		ft_longlonglen_base.c \
		ft_strtoupper.c \
		ft_lstappend.c \
		ft_pow.c \
		ft_log10.c \
		ft_logbase2.c \
		ft_frexp.c \
		ft_bitmask.c \
		ft_vlqnew.c \
		ft_lstrev.c \
		ft_isspace.c \
		ft_strarrdel.c \
		ft_strarrlen.c \
		ft_lstprint.c \
		ft_lstfree.c \
		ft_lstlen.c \
		ft_isoption.c \
		ft_iscntrl.c

PRINTF_SRC = ft_printf.c \
		ft_dprintf.c \
		ft_initialize.c \
		ft_parse.c \
		get_variable_info.c \
		get_format_id.c \
		get_variable.c \
		ft_reset.c \
		ft_arg_convert.c \
		ft_do_flags.c \
		ft_flags_fun.c \
		ft_field_width.c \
		convert_di.c \
		ft_tools.c \
		ft_str_to_lst.c \
		ft_precision.c \
		ft_percent.c \
		ft_char.c \
		ft_str.c \
		ft_ptr.c \
		ft_asterisk.c \
		ft_padding.c \
		ft_ftoa_bit.c \
		ft_printf_fd.c

PRINTF_DIR = ft_printf/

OBJ_DIR = obj/
OBJ_DIR_PRINTF = $(OBJ_DIR)ft_printf/
OBJ = $(SRC:.c=.o) $(addprefix $(PRINTF_DIR), $(PRINTF_OBJ))
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)
OBJS = $(patsubst %, $(OBJ_DIR)%, $(OBJ))
PRINTF_OBJS = $(addprefix $(OBJ_DIR_PRINTF), $(PRINTF_OBJ))

INC_DIR = ./includes/
INC = libft.h ft_printf.h
INCS = $(addprefix $(INC_DIR), $(INC))

COLOR_G = \033[0;32m
COLOR_R = \033[0;31m
COLOR_RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "LIBFT \t\t[$(COLOR_G)Creating $@$(COLOR_RESET)]"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIBFT \t\t[ $(COLOR_G)READY$(COLOR_RESET) ]"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "LIBFT:\
		\t[$(COLOR_G)$(OBJ_DIR) created$(COLOR_RESET)]"
	@mkdir -p $(OBJ_DIR_PRINTF)
	@echo "FT_PRINTF:\
		[$(COLOR_G)$(OBJ_DIR)$(PRINTF_DIR) created$(COLOR_RESET)]"

clean:
	@rm -f $(OBJS)
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete
	@find . -type f -name '.DS_Store' -print -delete
	@echo "LIBFT objects \t[$(COLOR_G)cleaned$(COLOR_RESET)]"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "LIBFT all \t[$(COLOR_G)cleaned$(COLOR_RESET)]"

re: fclean all
