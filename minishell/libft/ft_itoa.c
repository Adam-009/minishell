/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi-- <asaadi--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:12:35 by asaadi--          #+#    #+#             */
/*   Updated: 2024/11/26 13:31:28 by asaadi--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(int n);
static void	ft_result(int n, char *result, int size);

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = find_size(n);
	result = malloc((sizeof(char) * size) + 1);
	if (result == NULL)
		return (NULL);
	result[size] = '\0';
	ft_result(n, result, size);
	return (result);
}

static void	ft_result(int n, char *result, int size)
{
	int	negatif;

	negatif = 0;
	if (n < 0)
	{
		negatif = 1;
		n = n * -1;
	}
	if (n == 0)
	{
		result[0] = '0';
		return ;
	}
	while (size--)
	{
		result[size] = (n % 10) + '0';
		n = n / 10;
		if (negatif && size == 1)
		{
			result[0] = '-';
			break ;
		}
	}
}

static int	find_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

// int main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// }
