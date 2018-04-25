/*
** EPITECH PROJECT, 2018
** my_put_float.c
** File description:
** Function that prints a float
*/

int my_float_len(float nb)
{
	int cmp = nb;
	int len = 0;

	if (nb == cmp)
		return (0);
	while (nb != (int)nb) {
		nb = nb * 10;
		len = len + 1;
	}
	return (len);
}

int my_put_float(float nb)
{
	float cpy = nb - (int)nb;
	int entire = (int)nb;
	int i = 0;

	my_put_nbr(entire);
	if (my_float_len(nb) != 0) {
		write(1, ".", 1);
		while (i < my_float_len(nb)) {
			cpy = cpy * 10;
			i = i + 1;
		}
		my_put_nbr((int)cpy);
	}
	return (0);
}
