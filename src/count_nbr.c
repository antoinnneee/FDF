#include "../fdf.h"


void	get_next_number(char *line, int ***nbr)
{
	int	i;
	int	j;
	int	num;
	int count;

	i = 0;
	count = 0;
	while(line[i] != 0)
	{
		if (!ft_isdigit(line[i]) && i > 0)
		{
			if (count == 0)
				*nbr = (int*)ft_memalloc(count+1);
			
			*nbr[count] = ft_atoi(ft_strsub(line, j, i - j));
			count++;
			
		}
		else if(ft_isdigit(line[i]))
		{
			i++;
			j = i;
		}
		else
			i++;
	}
}

t_init	count_nbr(int fd)
{
	t_init	s_size;
	int		**tabnumber;
	int		*indexline;
	int		*col;
	char	*line;
	int		**number;

	indexline = 0;
	tabnumber = (int**)malloc(sizeof(int*) * *indexline + 1);
	col = 0;
	indexline = 0;
	while (get_next_line(fd, &line) == 1)
	{
	get_next_number(line, &tabnumber);
		indexline++;
	}
	return (s_size);
}
