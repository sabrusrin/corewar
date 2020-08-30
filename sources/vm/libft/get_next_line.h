/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:21:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/22 13:38:33 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 3

typedef struct	s_gnl
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			rd;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
