/*works as a cut command in linux----- */
/*executing for characters ony*/
/*yet to work on other fields and bytes*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	FILE *fp;
	int state;
	int a = 0,b = 0;
	char c;
	char arr[20];
	int cut = 0;
	int i = 0,j = 1;
	while(argv[2][i]) {
		arr[i] = argv[2][i];
		i++;
	}
	arr[i] = '\0';
	if(arr[0] == '-' && arr[1] == '\0')
		state = 3;
	if(arr[0] == '-') {
		while(arr[j++])
			cut = cut * 10 + arr[j] - '0';
		state = 2;
	}
	j = 0;
	if(arr[i-1] == '-') {
		state = 4;
		while(j < (i-1)) 
			cut = cut * 10 + arr[j++] - '0';
	}
	else {
		while(arr[j] != '-') { 
			if(arr[j] == '\0')
				break;
			a = a * 10 + arr[j] - '0';
			j++;
		}
		if(arr[j] == '-') {
			j++;
			while(arr[j] != '\0') 
				b = b *10 + arr[j++] - '0';
		}
		if(b)
			state = 5;
		else{
			state = 1;
			cut = a;
		}
	}
	
	fp = fopen(argv[3], "r");
	i = 0;
	switch(state) {
		case 1 :
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
			break;
		case 2 :
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
			break;
		case 3 :
			do{
				c = fgetc(fp);
				if(feof(fp))
					break;
				printf("%c",c);
			}while(1);
			break;
		case 4 :
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
			break;
		case 5 :
			do {
				c = fgetc(fp);
				if(feof(fp))
					break;
				i++;
				if(c == '\n') {
					printf("\n");
					i = 0;
					continue;
				}
				if(i >= a && i <= b)
					printf("%c",c);					
			}while(1);
			break;
		default :
			break;	
	}
	fclose(fp);
	return 0;
}
