#include <stdlib.h>
#include <stdio.h>

void num_add(char *s1,char *s2,int index);
int getstringlength(char *s);

int main(){
	char str[2][101];
	for(int loopnum1 = 0;loopnum1 <= 1; loopnum1++){
		printf("�п�J�� %d �Ӽƭ�(�̦h�u���J100�Ӧr)",%d);
		scanf("%s",str[loopnum1]);
		if(str[10] != '\0'){
			printf("��ƪ��׿�J�L���A�Э��s��J\n");
			loopnum1--;
			continue;
		}
	}
}

void num_add(char *s1,char *s2,int index){
	int backnum1=index - getstringlength(s1) - 1;
	int backnum2=index - getstringlength(s2) - 1;
	int minnum;
	for(int loopnum2 = index-1;loopnum2 >= 0; loopnum2--){
		
	} 
}

int getstringlength(char *s){
	int num1 = 0;
	while(1){
		if(*(s+num1) == '\0')
			break;
		num1++;
	}
	return num1;
}
