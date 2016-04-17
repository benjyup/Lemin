/*
** my_epure_str.c for  in /home/mesqui_v/rendu/Tek1/S2/CPE/LemIn/CPE_2015_Lemin
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Sun Apr 17 13:06:52 2016 vincent mesquita
** Last update Sun Apr 17 13:07:54 2016 vincent mesquita
*/

void		my_epure_str(char *str)
{
  int		i;

  if (!str)
    return ;
  i = -1;
  while (str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
}
