/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchizhov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:08:25 by vchizhov          #+#    #+#             */
/*   Updated: 2023/04/30 18:37:35 by vchizhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../checker_bonus/get_next_line/get_next_line.h"

typedef struct s_list
{
	int				content;
	int				result;
	int				count_rr;
	int				count_rrr;
	int				count_ra;
	int				count_rb;
	int				count_rra;
	int				count_rrb;
	int				rb;
	int				rrb;
	int				ra;
	int				rra;
	int				start;
	int				count;
	struct s_list	*next;
}	t_list;

// ================== LIST FUNCTION AND VALIDATION ====================

void	read_list(t_list **a);
t_list	*ft_lstnew(int content);
void	del(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
int		check_min_max_int(unsigned int res, int sign, t_list **stack);
int		ft_atoi(const char *str, t_list **stack);
int		validation(char *str);
t_list	*add_to_list(char **av);
int		check_dublicate(t_list *a);
int		check_for_unsorted(t_list *a);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
char	**parse_arguments(char **av, int ac);
void	check_space(char **av);

// ===================== INSTRUCTION ==============================

void	sa(t_list **head, int i);
void	sb(t_list **head, int i);
void	ss(t_list **head_a, t_list **head_b, int i);
void	pa(t_list **dest_ref, t_list **source_ref, int i);
void	pb(t_list **dest_ref, t_list **source_ref, int i);
void	ra(t_list **head, int i);
void	rb(t_list **head, int i);
void	rr(t_list **head_a, t_list **head_b, int i);
void	rra(t_list **head, int i);
void	rrb(t_list **head, int i);
void	rrr(t_list **head_a, t_list **head_b, int i);

// ==================== SMALL SORTING ==============================

void	sort_list(t_list **a);
void	push_in_b(t_list **a, t_list **b);
void	sorting_5(t_list **a, t_list **b);
void	start_sorting_5(t_list **a, t_list **b);
int		find_position_number(t_list **a, t_list **b);
int		find_position_min_a(t_list **a);
int		return_max_a(t_list **a, int max_a_position);
int		find_position_max_a(t_list **a);
void	sorting_3(t_list **a);

// ==================== FULL SORTING ========================================

void	full_sorting(t_list **a, t_list **b);
void	next_full_sorting(t_list **a, t_list **b);
void	position_analysis(t_list **a, t_list **b, int ra_case, int rb_case);
t_list	*get_node(t_list *b, int index);
int		max_count(int a, int b);
int		check_count_of_sorted_elements(t_list **a);
int		compare(int a, int b);
void	free_result(t_list **b);
void	sort_a(t_list **a, int ra_case, int rra_case);
void	sort_b(t_list **b, int rb_case, int rrb_case);
void	sort_a_b(t_list **a, t_list **b, int rr_case, int rrr_case);
void	count_of_rotation_for_position(t_list **a, t_list **b, int i);
void	count_up_rotation(t_list **b);
void	count_down_rotation(t_list **b);

// ==================== LIBFT ===============================================

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
