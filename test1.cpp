#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Textcount(char * file);
int ccount = 0;			//�����ַ�����
int wcount = 0;			//���ڵ��ʼ���

int main(int argc, char* argv[]){
	FILE *fp;
	Textcount(argv[2]);
	if(strcmp(argv[1],"-c") == 0){           //argv[1]����-c��-wָ�argv[2]�����ļ�����·��
			printf("�ļ�%s�ַ���Ϊ:%d\n",argv[2],ccount);	//��ʾͳ������
		}
		else if(strcmp(argv[1],"-w") == 0){
			printf("�ļ�%s������Ϊ:%d\n",argv[2],wcount);
		}
	return 0;
}

void Textcount(char * file){
	FILE *fp;
	char a;
	if((fp = fopen(file,"r")) == NULL){
		printf("�ļ������ڣ�\n");
		exit(-1);
	}
	while(!feof(fp)){
		a = fgetc(fp);		//��ȡ���ַ����ַ�������ccount+1
		ccount++;
		if(a==' '||a=='\n'||a==','){		//��ȡ���ո񡢻��з������ţ����ʼ�����wcount+1
			wcount++;
		}
	}
	wcount++;		//���������һ������û�м��������
	ccount--;		//�ļ���β�ַ�����+1
	fclose(fp);
}
