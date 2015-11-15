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
#include "cut.h"
#include <stdio.h>
#include <stdlib.h>
void init(list *l) {
	l->head = l->tail = NULL;
}
/*print only column of character */
void printonly_column(int cut, FILE *fp) {
	char c;
	int i = 0;
	do {
		c = fgetc(fp);
		if(feof(fp)) 
			break;
		i++;
		if(c == '\n'){
			i = 0;
			continue;
		}
		if(i == cut)
			printf("%c\n",c);
	}while(1);
}
/* print upto a column of character  from starting */
void printupto_column(int cut, FILE *fp) {
	char c;
	int i = 0;
	do {
		c = fgetc(fp);
		if(feof(fp))
			break;
		i++;
		if( c == '\n') {
			i = 0;
			continue;
		}
		if(i <= cut)
			printf("%c",c);
		if(i == cut)
			printf("\n");
	}while(1);
}
/* print all characters */
void print_file(FILE *fp) {
	char c;
	do{
		c = fgetc(fp);
		if(feof(fp))
			break;
		printf("%c",c);
	}while(1);
}
/* print from a column of character to end of line */
void printfrom_column(int cut, FILE *fp) {
	char c;
	int i = 0;
	do {
		c = fgetc(fp);
		if(feof(fp))
			break;
		i++;
		if( c == '\n') {
			printf("\n");
			i = 0;
			continue;
		}
		if(i >= cut)
			printf("%c",c);
	}while(1);
}
/* print from a column to other column of characters */
void printfrom_a_to_b(list l, FILE *fp) {
	char c;
	int x,y;
	int i = 0;
	node *p = l.head;
	x = p->a;
	y = p->b;
	do {
		c = fgetc(fp);
		if(feof(fp))
			break;
		i++;
		if(c == '\n') {
			printf("\n");
			i = 0;
			p = l.head;
			x = p->a;
			y = p->b;
			continue;
		}
		if(i >= x && i <= y)
			printf("%c",c);
		
		if(i == y) {
			p = p->next;
			if(p) {
				x = p->a;
				y = p->b;
			}
			else
				continue;
		}
							
	}while(1);
}
/* print upto certain column or field from start */
void printupto_column_f(int cut, FILE *fp) {
	char c;
	int i = 0;
	int flag = 0;
	do {
		c = fgetc(fp);
		if(feof(fp)) 
			break;
		i++;
		if(c == '\t')
			flag++;
		if(c == '\n'){
			printf("\n");
			i = 0;
			flag = 0;
			continue;
		}
		if(flag < cut) 
			printf("%c",c);
	}while(1);
}
/* print only a column of words */
void printonly_column_f(int cut, FILE *fp) {
	char c;
	int flag = 0;
	int m = cut-1 ;
	do {
		c = fgetc(fp);
		if(feof(fp))
			break;
		if(c == '\t')
			flag++;
		if(c == '\n') {
			printf("\n");
			flag = 0;
			continue;
		}
		if((m <= flag) && (flag < cut)) {
			if(c != '\t')
				printf("%c",c);
		}
	}while(1);
}
/* print from a field to end of line */
void printfrom_column_f(int cut, FILE *fp) {
	char c;
	int flag = 0;
	int m = cut-1 ;
	do {
		c = fgetc(fp);
		if(feof(fp))
			break;
		if(c == '\t')
			flag++;
		if(c == '\n') {
			printf("\n");
			flag = 0;
			continue;
		}
		if(m <= flag)
			printf("%c",c);
		
	}while(1);
}
/* print from a certain field to other field */
void printfrom_a_to_b_f(list l,FILE *fp) {
	char c;
	int x,y;
	int flag = 0;
	node *p = l.head;
	x = p->a - 1;
	y = p->b ;
	do {
		c = fgetc(fp);
		if(feof(fp))
			break;
		if(c == '\t')
			flag++;
		if(c == '\n') {
			printf("\n");
			flag = 0;
			p = l.head;
			x = p->a - 1;
			y = p->b ;
			continue;
		}
		if((x <= flag) && (flag < y))
			printf("%c",c);
		
		if(flag == y) {
			if(p)
				p = p->next;
			if(p) {
				x = p->a - 1;
				y = p->b ;
			}
			else
				continue;
		}
							
	}while(1);
}	
