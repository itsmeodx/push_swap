/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:27:36 by oouaadic          #+#    #+#             */
/*   Updated: 2024/05/15 16:41:19 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MAX_FD 1024
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/***************************************************************/
char	*get_next_line(int fd);
char	*ft_strnew(size_t size);
char	*ft_alt_strjoin(char *s1, char *s2);
char	*ft_alt_strchr(const char *s, int c);
char	*ft_alt_strsub(char const *s, unsigned int start, size_t len, int flag);
size_t	ft_alt_strlen(const char *s);

#endif /* GET_NEXT_LINE_BONUS_H */
