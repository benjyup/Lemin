/*
** my_nan.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 03:17:28 2016 vincent mesquita
** Last update Sun Apr 17 03:18:56 2016 vincent mesquita
*/

int		my_nan(char *str)
{
  int		i;

  if (!str)
    return (1);
  i = -1;
  while (str[++i])
    if (str[i] < '0' || str[i] > '9')
      return (1);
  return (0);
}
