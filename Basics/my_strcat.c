/*
** my_strcat.c for my_strcat.c in /home/mesqui_v/rendu/Minishell1/PSU_2015_minishell1
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Fri Jan  8 15:55:23 2016 vincent mesquita
** Last update Sun Apr 17 01:30:58 2016 vincent mesquita
*/

#include <stdlib.h>

char		*my_strcat(char *str1, char *str2)
{
  char		*cpy;
  int		i;
  int		h;

  i = 0;
  h = 0;
  while (str1 != NULL && str1[i])
    i = i + 1;
  while (str2!= NULL && str2[h])
    h = h + 1;
  if ((cpy = malloc((VALUE) * sizeof(char))) == NULL || str2 == NULL)
    return (NULL);
  i = 0;
  while (str1 != NULL && str1[i])
    {
      cpy[i] = str1[i];
      i = i + 1;
    }
  h = 0;
  while (str2[h])
    cpy[i++] = str2[h++];
  if (str1 != NULL)
    free(str1);
  cpy[i] = '\0';
  return (cpy);
}

char		*my_strcat_env(char *str1, char *str2)
{
  char		*cpy;
  int		i;
  int		h;

  i = 0;
  h = 0;
  while (str1 != NULL && str1[i])
    i = i + 1;
  while (str2!= NULL && str2[h])
    h = h + 1;
  if ((cpy = malloc((VALUE) * sizeof(char))) == NULL || str2 == NULL)
    return (NULL);
  i = 0;
  while (str1 != NULL && str1[i])
    {
      cpy[i] = str1[i];
      i = i + 1;
    }
  h = 0;
  while (str2[h])
    cpy[i++] = str2[h++];
  cpy[i] = '\0';
  return (cpy);
}
