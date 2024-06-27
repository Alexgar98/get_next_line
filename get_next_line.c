/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:49:23 by alexigar          #+#    #+#             */
/*   Updated: 2024/02/08 12:21:19 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*fail_or_return(int reading, char *stash, char *buffer)
{
	if (reading < 0)
		free_stuff(stash, buffer);
	else
	{
		if (ft_strlen(stash) > 0)
			return (stash);
		else
			free_stuff(stash, buffer);
	}
	return (NULL);
}

char	*read_line(int fd, char *buffer, char *stash)
{
	int		reading;
	char	*new_stash;

	reading = 1;
	while (reading > 0)
	{
		if (ft_strchr(stash, '\n'))
			return (stash);
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading <= 0)
			stash = fail_or_return(reading, stash, buffer);
		else
		{
			buffer[reading] = '\0';
			new_stash = ft_strjoin(stash, buffer);
			if (!new_stash)
			{
				free(buffer);
				return (NULL);
			}
			free(stash);
			stash = new_stash;
		}
	}
	return (stash);
}

char	*fill_line(char *stash)
{
	int		jump_index;
	char	*line;

	jump_index = 0;
	while (stash[jump_index] != '\n' && stash[jump_index] != '\0')
		jump_index++;
	jump_index++;
	line = malloc(jump_index + 1);
	if (!line)
	{
		free_stuff(stash, NULL);
		return (NULL);
	}
	ft_strlcpy(line, stash, jump_index + 1);
	return (line);
}

void	free_stuff(char *stash, char *buffer)
{
	if (stash)
	{
		free(stash);
		stash = NULL;
	}
	if (buffer)
		buffer = NULL;
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;
	char		*new_stash;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
			free(stash);
		return (stash = NULL);
	}
	if (!stash)
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = malloc(BUFFER_SIZE + 1);
	stash = read_line(fd, buffer, stash);
	free(buffer);
	if (!stash)
		return (NULL);
	line = fill_line(stash);
	new_stash = malloc(BUFFER_SIZE + 1);
	ft_strlcpy(new_stash, stash + ft_strlen(line), BUFFER_SIZE + 1);
	free(stash);
	stash = new_stash;
	return (line);
}
/*
int main(void)
{
	char *archivo = "archivo de prueba";
	int abrir = open(archivo, O_RDONLY);
	if (abrir == -1)
	{
		printf("Ejto ha fallao' (?)\n");
		return (1);
	}
	char *to_print = get_next_line(abrir);
	int i = 1;
	while (i <= 2 && to_print && *to_print != '\0')
	{
		printf("%d%s", i, to_print);
		i++;
		to_print = get_next_line(abrir);
	}
	close(abrir);
	to_print = get_next_line(abrir);
	printf("%s", to_print);
	abrir = open(archivo, O_RDONLY);
	to_print = get_next_line(abrir);
	while (to_print && *to_print != '\0')
	{
		printf("%d%s", i, to_print);
		i++;
		to_print = get_next_line(abrir);
	}
	free(to_print);
	return (0);
}*/
