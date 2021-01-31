int		ft_foreach(char *str, int(*f)(int))
{
	while (*str != 0)
	{
		if ((*f)(*str))
			str++;
		else
			return (0);
	}
	return (1);
}
