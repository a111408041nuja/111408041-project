/*****************************************************************************
 * Copyright (C) Anuja Sunil Padmawar  padmawaras14.it@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include <stdio.h>
typedef struct node {
	int a,b;
	struct node *next;
}node;
typedef struct list {
	node *head,*tail;
}list;
void init(list *l);
void printonly_column(int cut, FILE *fp);
void print_file(FILE *fp);
void printupto_column(int cut, FILE *fp);
void printfrom_column(int cut, FILE *fp);
void printfrom_a_to_b(list l, FILE *fp);
void printonly_column_f(int cut, FILE *fp);
void printupto_column_f(int cut, FILE *fp);
void printfrom_column_f(int cut, FILE *fp);
void printfrom_a_to_b_f(list l,FILE *fp);
