#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Textcount(char * file);
int ccount = 0;			//用于字符计数
int wcount = 0;			//用于单词计数

int main(int argc, char* argv[]){
	FILE *fp;
	Textcount(argv[2]);
	if(strcmp(argv[1],"-c") == 0){           //argv[1]保存-c、-w指令，argv[2]保存文件名及路径
			printf("文件%s字符数为:%d\n",argv[2],ccount);	//显示统计数据
		}
		else if(strcmp(argv[1],"-w") == 0){
			printf("文件%s单词数为:%d\n",argv[2],wcount);
		}
	return 0;
}

void Textcount(char * file){
	FILE *fp;
	char a;
	if((fp = fopen(file,"r")) == NULL){
		printf("文件不存在！\n");
		exit(-1);
	}
	while(!feof(fp)){
		a = fgetc(fp);		//读取到字符，字符计数器ccount+1
		ccount++;
		if(a==' '||a=='\n'||a==','){		//读取到空格、换行符、逗号，单词计数器wcount+1
			wcount++;
		}
	}
	wcount++;		//理论上最后一个单词没有计入计数器
	ccount--;		//文件结尾字符数会+1
	fclose(fp);
}
