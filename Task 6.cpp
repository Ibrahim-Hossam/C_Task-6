# include <stdio.h>
# include <stdlib.h>
void read(FILE* fi, char line[72]={0}){ //searched google and found that one line in word takes 72 characters
	fi = fopen("Task.txt", "r"); 
	while(!feof(fi)){
		fgets(line,72,fi);
	};
	fclose(fi);
}
void reverse(FILE* fi,char arr[72]){
	int i = 72;
	char *ptr1, *ptr2;
	char exch; //exch shortcut for exchange
	fi = fopen("Task.txt", "r");
	read(fi,arr);
	ptr1 = &arr[i];
	ptr2 = &arr[72-i];
	printf("%d ",i);
	while(i > 0){
		exch = *ptr2;
		*ptr2 = *ptr1;
		*ptr1 = exch;
		ptr1--;
		ptr2++;
		i--;
	}
	fclose(fi);
 }



void write(char line[72]){
	FILE *f = fopen("Task.txt", "a");
	fprintf(f,"%s", line);
	fclose(f);
}
int main(){
	char line[72]={0};
	FILE* f = fopen("Task.txt", "w");
	fprintf(f, "Hello dear facilitator\n");
	fclose(f);
	read(f, line);
	fclose(f);
	reverse(f, line);
	printf("%s", line);
	write(line);
	fclose(f);
	return 0;
}
