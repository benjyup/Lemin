/*
** my_check_dash.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Apr 25 11:04:20 2016 vincent mesquita
** Last update Mon Apr 25 11:10:23 2016 vincent mesquita
*/

int		my_check_dash(char *str)
{
  unsigned int	i;
  unsigned int	count;

  i = 0;
  count = 0;
  if (!str)
    return (-1);
  while (str[i])
    {
      if (str[i] == '-')
	count += 1;
      i += 1;
    }
  return (((count <= 1) ? (0) : (-1)));
}
