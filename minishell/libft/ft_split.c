/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:23:45 by asaadi--          #+#    #+#             */
/*   Updated: 2025/01/21 17:20:59 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compteur(char const *s, char c, int mat, int value);
static void	create_string(char const *s, char c, char **arr);

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((compteur(s, c, 0, 2) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	create_string(s, c, arr);
	return (arr);
}

static void	create_string(char const *s, char c, char **arr)
{
	int	i;
	int	si;
	int	j;

	i = 0;
	j = 0;
	si = 0;
	while (i < compteur(s, c, 0, 2))
	{
		arr[i] = malloc(sizeof(char) * (compteur(s, c, i, 1) + 1));
		if (arr[i] == NULL)
		{
			while (i != 0)
				free(arr[i--]);
			free(arr);
		}
		while (s[si] == c && s[si] != '\0')
			si++;
		while (j < compteur(s, c, i, 1))
			arr[i][j++] = s[si++];
		arr[i][j] = '\0';
		j = 0;
		i++;
	}
	arr[i] = NULL;
}

static int	compteur(char const *s, char c, int mat, int value)
{
	int	i;
	int	wc;
	int	cc;

	i = 0;
	wc = 0;
	cc = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			wc++;
		if (wc - 1 == mat && s[i] != c)
			cc++;
		i++;
	}
	if (value == 1)
		return (cc);
	else if (value == 2)
		return (wc);
	return (1);
}
// #include <stdio.h>
//  int	main(void)
// {
// 	char	text[] = "lorem ipsum dolor sit amet";
// 	char	**result = ft_split(text, ' ');
//  	for (size_t i = 0; i < 7; i++)
// 		printf("%s\n", result[i]);
// 	free_map(result);
// 	return (0);
// }
