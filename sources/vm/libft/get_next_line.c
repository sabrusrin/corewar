/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:13:48 by adavis            #+#    #+#             */
/*   Updated: 2019/09/06 20:18:15 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		retrail(char **line, char **trail)
{
	char		*trail_tmp;

	*line = ft_strnew(ft_strwrdlen(*trail, '\n'));
	ft_strncpy(*line, *trail, ft_strwrdlen(*trail, '\n'));
	trail_tmp = ft_strdup(ft_strchr(*trail, '\n') + 1);
	free(*trail);
	*trail = ft_strdup(trail_tmp);
	free(trail_tmp);
	trail_tmp = NULL;
	return (1);
}

int		flush(char **tmp, char **trail, char **line)
{
	if (*tmp)
	{
		*line = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
		return (1);
	}
	if (*trail && **trail)
	{
		*line = ft_strdup(*trail);
		free(*trail);
		*trail = NULL;
		return (1);
	}
	ft_strdel(trail);
	return (0);
}

void	update_tmp(char **tmp, char *buf, int rd)
{
	char	*tmptmp;

	if (*tmp)
	{
		tmptmp = ft_strdup(*tmp);
		free(*tmp);
		*tmp = ft_strnew(ft_strlen(tmptmp) + rd);
		ft_strcpy(*tmp, tmptmp);
		free(tmptmp);
		ft_strncat(*tmp, buf, rd);
	}
	else
	{
		*tmp = ft_strnew(rd);
		ft_strncpy(*tmp, buf, rd);
	}
}

int		ret_line(t_gnl *util, char **trail, char **line)
{
	if (util->tmp)
	{
		*line = ft_strnew(ft_strlen(util->tmp) + ft_strwrdlen(util->buf, '\n'));
		ft_strcpy(*line, util->tmp);
		ft_strncat(*line, util->buf, ft_strwrdlen(util->buf, '\n'));
		free(util->tmp);
		util->tmp = NULL;
	}
	else
	{
		*line = ft_strnew(ft_strwrdlen(util->buf, '\n'));
		ft_strncpy(*line, util->buf, ft_strwrdlen(util->buf, '\n'));
	}
	if (util->rd > (int)ft_strwrdlen(util->buf, '\n'))
	{
		*trail = ft_strnew(util->rd - ft_strwrdlen(util->buf, '\n') - 1);
		ft_strncpy(*trail, ft_strchr(util->buf, '\n') + 1, util->rd -
											ft_strwrdlen(util->buf, '\n') - 1);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*trail;
	t_gnl		util;

	if (fd < 0)
		return (-1);
	util.tmp = NULL;
	if (trail && ft_strchr(trail, '\n'))
		return (retrail(line, &trail));
	while ((util.rd = read(fd, util.buf, BUFF_SIZE)) && BUFF_SIZE > 0)
	{
		if (util.rd < 0)
			return (-1);
		if (trail)
		{
			util.tmp = ft_strdup(trail);
			free(trail);
			trail = NULL;
		}
		if (ft_strchr(util.buf, '\n'))
			return (ret_line(&util, &trail, line));
		else
			update_tmp(&util.tmp, util.buf, util.rd);
	}
	return (flush(&util.tmp, &trail, line) ? 1 : 0);
}
