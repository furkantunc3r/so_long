/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuncer <ftuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:56:06 by ftuncer           #+#    #+#             */
/*   Updated: 2022/04/25 13:31:50 by ftuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	u1;
	unsigned char	u2;

	while (n-- > 0)
	{
		u1 = *(unsigned char *)s1++;
		u2 = *(unsigned char *)s2++;
		if (u1 != u2)
			return (u1 - u2);
		if (u1 == '\0')
			return (0);
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

int	ft_check_arg(char *argv)
{
	void	*a;
	char	*b;
	int		fd;

	b = ".ber";
	fd = open(argv, O_RDONLY);
	a = ft_strrchr(argv, '.');
	if (a == NULL || ft_strncmp(a, b, 4) != 0 || fd == -1)
	{
		ft_printf("Invalid argument entry!\n");
		exit (0);
	}
	close (fd);
	return (1);
}
