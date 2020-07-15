/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojung <yojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:36:05 by yojung            #+#    #+#             */
/*   Updated: 2020/07/15 10:45:22 by yojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	dec_to_hex(int n)
{
	if (n < 10)
	{
		return (n + 48);
	}
	else
	{
		return (n + 87);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != 0)
	{
		if (32 <= str[i] && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, "\\", 1);
			c = dec_to_hex(str[i] / 16 % 16);
			write(1, &c, 1);
			c = dec_to_hex(str[i] % 16);
			write(1, &c, 1);
		}
		i++;
	}
}
