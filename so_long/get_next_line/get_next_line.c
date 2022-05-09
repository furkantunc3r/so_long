/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:18:10 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/18 16:44:20 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*res_str_line(char *arr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	if (!arr[i])
	{
		free(arr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(arr) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (arr[i])
		str[j++] = arr[i++];
	str[j] = '\0';
	free(arr);
	return (str);
}

char	*res_line(char *arr)
{
	char	*dbl;
	int		i;

	i = 0;
	if (!arr[i])
		return (NULL);
	while (arr[i] != '\n' && arr[i])
		i++;
	dbl = (char *)malloc((i + 2) * sizeof(char));
	if (!dbl)
		return (NULL);
	i = 0;
	while (arr[i] != '\n' && arr[i])
	{
		dbl[i] = arr[i];
		i++;
	}
	if (arr[i] == '\n')
	{
		dbl[i] = arr[i];
		i++;
	}
	dbl[i] = '\0';
	return (dbl);
}

char	*read_fd(int fd, char *arr)
{
	char	*temp;
	int		b;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	b = 1;
	while (!ft_strchr(arr, '\n') && b != 0)
	{
		b = read(fd, temp, BUFFER_SIZE);
		if (b == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[b] = '\0';
		arr = ft_strjoin(arr, temp);
	}
	free(temp);
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*arr;
	char		*arr2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	arr = read_fd(fd, arr);
	if (!arr)
		return (NULL);
	arr2 = res_line(arr);
	arr = res_str_line(arr);
	return (arr2);
}
