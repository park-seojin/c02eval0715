/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojung <yojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:02:47 by yojung            #+#    #+#             */
/*   Updated: 2020/07/15 10:38:25 by yojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	for_fist_letter(char *str)
{
	if ('a' <= str[0] && str[0] <= 'z')
	{
		str[0] -= 32;
	}
}

int		is_alphabet_num(char c)
{
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	else if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	else if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	for_fist_letter(str);
	i = 1;
	while (str[i] != 0 && str[0] != 0)
	{
		if (!is_alphabet_num(str[i - 1]))
		{
			if ('a' <= str[i] && str[i] <= 'z')
			{
				str[i] -= 32;
			}
			else if ('A' <= str[i] && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		i++;
	}
	return (str);
}
