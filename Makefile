# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalena <msalena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 13:14:56 by msalena           #+#    #+#              #
#    Updated: 2022/01/15 12:14:10 by msalena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBDIR		= 	libft

SRCS_PH		= 	 philo.c utils.c doing_statuses.c

OBJS_PH		= 	${SRCS_PH:.c=.o}

HDRS_PH		= 	philo.h

NAME_LIB	= 	$(LIBDIR)/libft.a

NAME_PH		= 	philo

GCC			= 	gcc -g #-Wall -Wextra -Werror -g

all:			c_for_libft $(NAME_PH)

%.o:			%.c $(HDRS_PH)
				$(GCC) -c $< -o $@

$(NAME_PH): 	$(OBJS_PH) $(NAME_LIB) Makefile
				$(GCC) $(NAME_LIB) $(OBJS_PH) -o ${NAME_PH}

c_for_libft:
				$(MAKE) -C $(LIBDIR)

clean:
				rm -f $(OBJS_PH)
				$(MAKE) clean -C $(LIBDIR)

fclean:			clean
				rm -f $(NAME_PH)
				$(MAKE) fclean -C $(LIBDIR)

re:				fclean all

.PHONY:			all c_for_libft clean fclean re
