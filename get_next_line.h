/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:20:34 by alexigar          #+#    #+#             */
/*   Updated: 2024/02/08 12:09:58 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*fill_line(char *stash);
char	*read_line(int fd, char *buffer, char *stash);
char	*fail_or_return(int reading, char *stash, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlen(char *str);
char	*ft_calloc(int count, int size);
void	free_stuff(char *stash, char *buffer);

#endif
