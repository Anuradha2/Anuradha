#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp1,*fp2;
	char c,d,e;
	printf("opening file a.c\n");
	fp1= fopen("a.c","r");
	if(fp1==NULL){
		printf("cannot open file\n");
		exit(0);
	}
	fp2=fopen("b.c","w");
	if(fp2==NULL){
		printf("cannot open file\n");
		exit(0);
	}
	while((c=fgetc(fp1)) != EOF){
		if(c=='/'){
			if((d=fgetc(fp1))=='*'){
				while((d=fgetc(fp1))!=EOF){
					if(d=='*'){
						e=fgetc(fp1);
						if(e=='/')
						break;
					}
				}
			}
			else if(d=='/'){
				while((d=fgetc(fp1))!=EOF){
					if(d=='\n')
					break;
				}
				
			}
			else{
				fputc(c,fp2);
				fputc(d,fp2);
			}
		}
		else{
			fputc(c,fp2);
		}
	}
return 0;
}
