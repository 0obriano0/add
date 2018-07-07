#include <stdlib.h>
#include <stdio.h>

void num_add(char *s1,char *s2,int index);
int getstringlength(char *s);
bool check_string_all_for_num(char *s);
void show_num(int space,int index,char *s);

int main(){
	int longnum = 100;
	while(1){
		printf("----------------------------------------------------基本數字相加----------------------------------------------------\n");
		char str[2][longnum+1];
		str[0][longnum] = '\0';
		str[1][longnum] = '\0';
		for(int loopnum1 = 0;loopnum1 <= 1; loopnum1++){
			printf("請輸入第 %d 個數值(最多只能輸入%d個字):",loopnum1+1,longnum);
			scanf("%s",str[loopnum1]);
			if(str[loopnum1][longnum] != '\0'){
				printf("\n資料長度輸入過長，請重新輸入\n\n");
				loopnum1--;
				continue;
			}
			if(!check_string_all_for_num(str[loopnum1])){
				printf("\n資料輸入錯誤，請重新輸入(有非數字字元)\n\n");
				loopnum1--;
				continue;
			}
		}
		num_add(str[0],str[1],longnum);
		system("pause");
		system("cls");
	}	
}

void num_add(char *s1,char *s2,int index){
	char str[index+2];
	str[index+1] = '0';
	int backnum1=getstringlength(s1);
	int backnum2=getstringlength(s2);
	for(int loopnum2 = index-1;loopnum2 >= -2; loopnum2--){
		int checknum[2] = {loopnum2-(index-backnum1),loopnum2-(index-backnum2)};
		str[loopnum2+2] = (str[loopnum2+2]-'0')+((checknum[0] >= 0 ? *(s1+checknum[0]) : '0')-'0')+((checknum[1] >= 0 ? *(s2+checknum[1]) : '0')-'0');
		str[loopnum2+1] = (str[loopnum2+2]-10) > -1 ?'1':'0';
		str[loopnum2+2] = str[loopnum2+1] == '1' ? (str[loopnum2+2]-10 + '0') : (str[loopnum2+2] - 0 + '0');
	}
	printf("\n將兩數相加後\n--------------------------------------------------------------------------------------------------------------------\n\n\n");
	int maxnum = backnum1 > backnum2? backnum1 : backnum2;
	show_num(4+maxnum-backnum1,backnum1,s1);
	printf("+ )");
	show_num(1+maxnum-backnum2,backnum2,s2);
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("=");
	show_num(3,index+1,str+1);
	printf("\n\n");
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

bool check_string_all_for_num(char *s){
	int num1 = 0;
	bool num = true;
	while(1){
		if(*(s+num1) == '\0')
			break;
		if((*(s+num1)-'0') < 0 || (*(s+num1)-'0') > 9){
			num = false;
			break;
		}
		num1++;
	}
	return num;
}

void show_num(int space,int index,char *s){
	for(int loopnum4 = 1;loopnum4 <= space;loopnum4++){
		printf(" ");
	}
	int zeroOver = false;
	for(int loopnum5 = 0;loopnum5 <= index-1;loopnum5++){
		if(*(s+loopnum5)!='0' || zeroOver){
			zeroOver = true;
			printf("%c",*(s+loopnum5));
		}
	}
	printf("\n");
}
