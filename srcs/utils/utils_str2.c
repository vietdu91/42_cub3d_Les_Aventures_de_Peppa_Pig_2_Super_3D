/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:28:57 by emtran            #+#    #+#             */
/*   Updated: 2022/05/13 11:03:23 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*n_str;

	i = 0;
	while (str[i])
		i++;
	n_str = malloc(sizeof(char) * (i + 1));
	if (!n_str)
		return (NULL);
	i = -1;
	while (str[++i])
		n_str[i] = str[i];
	n_str[i] = 0;
	return (n_str);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_substr(char *s, int start, int len)
{
	char		*str;
	size_t		i;

	str = 0;
	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (str == 0)
			return (0);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(&s[start]))
		str = malloc(sizeof(char) * ft_strlen(&s[start]) + 1);
	else
		str = malloc(sizeof(char) * len + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (s[start] != '\0' && len-- != 0)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
