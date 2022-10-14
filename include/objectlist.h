/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktashbae <ktashbae@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:59:21 by ktashbae          #+#    #+#             */
/*   Updated: 2022/10/11 15:11:20 by ktashbae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "object.h"
#include "vector.h"

typedef struct s_objectlist {
    t_object	base;
    t_vector*	objects;
} t_objectlist;

t_objectlist* ft_listnew(void);
void ft_listfree(t_objectlist* objlist);
void ft_list_pushback(t_objectlist* objlist, t_object* object);
void ft_listclear(t_objectlist* objlist);

#endif
