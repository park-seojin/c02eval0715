/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojung <yojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:48:01 by yojung            #+#    #+#             */
/*   Updated: 2020/07/15 10:58:41 by yojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	dex_to_hex(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n + 87);
}

void			ptr_addr(void *addr)
{
	unsigned char	adr[17];
	int				i;
	long			tp;

	i = 15;
	adr[16] = ':';
	tp = (long)addr;
	while (i >= 0)
	{
		adr[i] = dex_to_hex(tp % 16);
		tp /= 16;
		i--;
	}
	write(1, adr, 17);
}

void			handle_exception(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	temp;

	i = 0;
	write(1, " ", 1);
	while (i < size)
	{
		temp = *((unsigned char *)addr + i);
		if (temp >= 32 && temp <= 126)
			write(1, &temp, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void			ptr_value(void *addr, unsigned int size)
{
	unsigned char	tp_arr[3];
	unsigned char	tp;
	unsigned int	i;

	i = 0;
	tp_arr[0] = ' ';
	while (i < 16)
	{
		if (i < size)
		{
			tp = *((unsigned char *)addr + i);
			tp_arr[1] = dex_to_hex(tp / 16 % 16);
			tp_arr[2] = dex_to_hex(tp % 16);
		}
		else
		{
			tp_arr[1] = ' ';
			tp_arr[2] = ' ';
		}
		if (++i % 2 == 1)
			write(1, &tp_arr, 3);
		else
			write(1, &tp_arr[1], 2);
	}
	handle_exception(addr, size);
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int tp;
	unsigned int i;

	tp = size / 16;
	i = 0;
	while (i < tp)
	{
		ptr_addr((unsigned char *)addr + (16 * i));
		ptr_value((unsigned char *)addr + (16 * i), 16);
		i++;
	}
	tp = size % 16;
	ptr_addr((unsigned char *)addr + size - tp);
	ptr_value((unsigned char *)addr + size - tp, tp);
	return (addr);
}
