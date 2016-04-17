/*
** there_is_dash.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 02:34:45 2016 vincent mesquita
** Last update Sun Apr 17 02:36:10 2016 vincent mesquita
*/

int		there_is_dash(char *str)
{
  int		i;

  if (!str)
    return (0);
  i = -1;
  while (str[++i])
    if (str[i] == '-')
      return (1);
  return (0);
}
