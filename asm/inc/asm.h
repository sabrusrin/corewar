/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:20:09 by chermist          #+#    #+#             */
/*   Updated: 2020/06/14 17:39:53 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "libft.h"

# include "op.h"

void assemble(char *filename);

#endif
