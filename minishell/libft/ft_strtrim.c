/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:51:12 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/25 14:28:53 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_last_caratere(char const *s1, char const *set);
static int	find_first_caratere(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	int		i;
	char	*result;

	start = find_first_caratere(s1, set);
	end = find_last_caratere(s1, set);
	i = 0;
	if (start > end)
		len = 0;
	else
		len = end - start + 1;
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	find_first_caratere(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			break ;
		i++;
	}
	return (i);
}

static int	find_last_caratere(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
			break ;
		i--;
	}
	return (i);
}

// int main(void)
// {
//     char find[] = "l o";
//     printf("%s\n", ft_strtrim("  lotest test  ", find));
// }