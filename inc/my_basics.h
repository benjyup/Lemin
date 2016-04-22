/*
** my_basics.h for basics.h in /home/mesqui_v/Basics
**
** Made by vincent mesquita
** Login   <mesqui_v@epitech.net>
**
** Started on  Mon Nov 30 12:27:07 2015 vincent mesquita
** Last update Fri Apr 22 20:27:41 2016 vincent mesquita
*/

#ifndef MY_BASICS_H_

# define MY_BASICS_H_
# define VALUE i + h + 1

void		my_putchar(char c);
void		my_putchar_error(char c);
int		my_put_nbr_error(int nbr);
int		my_puterror2(char *str, int line);
int		my_puterror_int(char *str,
				int line,
				int return_value);
void		*my_puterror_pnt(char *str);
int		my_putstr(char *str);
int		my_puterror(char *str);
int		my_strlen(char *str);
char		*my_strcpy(char *);
int		my_getnbr(char *str);
long		my_getnbr_long(char *str);
void		my_put_nbr(int nb);
void		my_put_nbrlong(long long nb);
void		my_put_nbrbase(unsigned long nb, char *base);
int		my_strcomp(char *str1, char *str2);
char		*my_strcat(char *str1, char *str2);
char		*my_strcat_char(char *str1, char c);
char		*my_strcat_env(char *str1, char *str2);
char		*my_strcat_char_env(char *str1, char c);
char		**my_str_to_wordtab(char *str, char separator);
unsigned int	my_wordtab_len(char **wordtab);
char		**my_add_to_wordtab(char **wordtab, char *str);
char		**my_delete_to_wordtab(char **wordtab, int idx);
int		my_show_wordtab(char **wordtab);
char		**my_wordtab_cpy(char **wordtab);
int		my_free_wordtab(char **wordtab);
char		*get_next_line(int fd);

#endif /* !MY_BASICS_H_ */
