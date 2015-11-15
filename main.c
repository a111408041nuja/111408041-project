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
#include <stdlib.h>
#include "cut.h"
int main(int argc, char *argv[]) {
	FILE *fp;
	int state;
	char charstate;
	list l;
	init(&l);
	int a = 0,b = 0;
	char arr[20];
	int cut = 0;
	int i = 0,j = 1;
	/* characterwise or fieldwise */
	if(argv[1][1] == 'c')
		charstate = 'c';
	if(argv[1][1] == 'f')
		charstate = 'f';
	if(argv[1][1] == 'b')
		charstate = 'c';

	while(argv[2][i]) {
		arr[i] = argv[2][i];
		i++;
	}
	arr[i] = '\0';
	/* to select the state */
	while(1) {
		if(arr[0] == '-' && arr[1] == '\0') {
			state = 3;
			break;
		}
		if(arr[0] == '-') {
			while(arr[j]) 
				cut = cut * 10 + arr[j++] - '0';
			state = 2;
			break;
		}
		j = 0;
		if(arr[i-1] == '-') {
			state = 4;
			while(j < (i-1)) 
				cut = cut * 10 + arr[j++] - '0';
			break;
		}
		else {
			while(1) {
				while(arr[j] != '-') { 
					if(arr[j] == '\0')
						break;
					a = (a * 10) + arr[j++] - '0';
				}
				if(arr[j] == '-') {
					j++;
					while(arr[j] != '\0' && arr[j] != ',') 
						b = b *10 + arr[j++] - '0';
				}
				if(a && b) {
					node *tmp = (node *)malloc(sizeof(node));
					tmp->a = a;
					tmp->b = b;
					tmp->next = NULL;
					if(l.head == NULL) {
						l.head = tmp;
						l.tail = tmp;	
					}
					else {
						l.tail->next = tmp;
						l.tail = tmp;
					}
				}
				if(arr[j] == ',') {
					j++;
					a = 0;
					b = 0;
					continue;
				}
				else
					break;
			}	
		
			if(l.head)
				state = 5;
			else{
				state = 1;
				cut = a;
			}
		}
		break;
	}

	fp = fopen(argv[3], "r");
	switch(charstate) {
		case 'c' :
			switch(state) {
				case 1 :
					printonly_column(cut, fp);
					break;
				case 2 :
					printupto_column(cut, fp);
					break;
				case 3 :
					print_file(fp);
					break;
				case 4 :
				        printfrom_column(cut, fp);
					break;
				case 5 :
					printfrom_a_to_b(l,fp);
					break;
				default :
					break;	
			}
			break;
		case 'f' :
			switch(state) {
				case 1 :
					printonly_column_f(cut, fp);
					break;
				case 2 :
					printupto_column_f(cut, fp);
					break;
				case 4 :
				        printfrom_column_f(cut, fp);
					break;
				case 5 :
					printfrom_a_to_b_f(l,fp);
					break;
				default :
					break;	
			}
			break;
	}

	fclose(fp);
	return 0;
}

