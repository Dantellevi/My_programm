#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <malloc.h> 

/* 
��������� ������������, ������� ������������� �������� 
� �����������, �������� ��� �����������, ������. 
���������� ������� ���� �� ������������ � ������� ������ 
������������, ������� ���� ������� ���� �������� ����� �� ������������. 
������� � ������ ������ ���� ��������, ������� ��� �������� �� 10.(��� ������������� ����������) 
-� ����������� �������� ��������� � ������� � ������ ���������������. 
������ ��������� �������� ��������� ����������: 
������������ ������ ������� (����������, �������������� � �. �.), 
����� �������, ���� ������� � ������, 
��������� ���������� ������ (��������, �� ��������). 
������� ���������� � ��������� ������� �� ������� ����� 
��� �������� ������ �������.(������������ ��������� � ������������ ��������� ������ ��� ���������). 


*/ 





typedef struct 
{ 
	char SerName[50]; 
	char Name[50]; 
	char SecondName[50]; 
	int make[5]; 

}STUDENTdef; 


/*----------------------������� ���������� ����� �� ����������------------------*/ 
void Fill_StudentsList(STUDENTdef *students,int *N); 
/*---------------------������� ������ ������ ���������----------------*/ 
void PrintArray(STUDENTdef *students,int *N); 
/*------------------------������� ���������� �������� ����� �� ������������------------*/ 
double MidleMake(STUDENTdef *students,int *N); 
/*--------------------------------������� ���������� ��������� � ������� ������� ��� ���� �������� ���� �� ������������--------------*/ 
void Serch_Students(STUDENTdef *students,int *N,double *mUn); 
/*--------------------------------������� ���������� ��������� � ������� �� ��� �������� 10--------------*/ 
void Serch_10STUDENTS(STUDENTdef *students,int *N,STUDENTdef *students_10); 
/*--------------------------------������� ������ ������� �� ����������--------------*/ 
void Print_TableStudents(STUDENTdef *students,int *N,double *mUn);




int main(int argc, char *argv[]) 
{ 
int N; 
printf("Input count students: "); 
scanf("%d",&N); 
printf("==========================\n "); 
STUDENTdef *students=(STUDENTdef*)malloc(N*sizeof(STUDENTdef)); 
Fill_StudentsList(students,&N); 
PrintArray(students,&N); 
printf("==========================\n "); 
double midleMake=MidleMake(students,&N); 
printf("Middle Make University: %lf\n",midleMake); 
printf("==========================\n "); 
Serch_Students(students,&N,&midleMake); 
return 0; 
} 

/*----------------------������� ���������� ����� �� ����������------------------*/ 
void Fill_StudentsList(STUDENTdef *students,int *N) 
{ 
for(int i=0;i<*N;i++) 
{ 
printf("Input Name:"); 
scanf("%s",&((students+i)->Name)); 

printf("Input SerName:"); 
scanf("%s",&((students+i)->SerName)); 

printf("Input SecondName:"); 
scanf("%s",&((students+i)->SecondName)); 

printf("Input Make: \n"); 
for(int j=0;j<5;j++) 
{ 
printf(" Make: \n"); 
scanf("%d",&(students[i].make[j])); 
} 
printf("-------------------------------------\n "); 


} 
} 


/*---------------------������� ������ ������ ���������----------------*/ 
void PrintArray(STUDENTdef *students,int *N) 
{ 
for(int i=0;i<*N;i++) 
{ 
printf(" Name: "); 
puts((students+i)->Name); 
printf("\n"); 
printf(" SerName: "); 
puts((students+i)->SerName); 
printf("\n"); 
printf("SecondName: "); 
puts((students+i)->SecondName); 
printf("\n"); 
printf("Make:\n "); 
for(int j=0;j<5;j++) 
{ 

printf("%d\n",students[i].make[j]); 
} 
printf("-------------------------------------\n "); 

} 
} 


/*------------------------������� ���������� �������� ����� �� ������������------------*/ 
double MidleMake(STUDENTdef *students,int *N) 
{ 
int count_del=*N*5; 
int sum=0; 
for(int i=0;i<*N;i++) 
{ 
for(int j=0;j<5;j++) 
{ 
sum+=students[i].make[j]; 
} 
} 

return ((double)sum/(double)count_del); 

} 

/*--------------------------------������� ���������� ��������� � ������� ������� ��� ���� �������� ���� �� ������������--------------*/ 
void Serch_Students(STUDENTdef *students,int *N,double *mUn) 
{ 
double mass_middleMake[*N]; 
for(int i=0;i<*N;i++) 
{ 
mass_middleMake[i]=0; 
} 
for(int i=0;i<*N;i++) 
{
	for(int j=0;j<5;j++) 
{ 
mass_middleMake[i]+=students[i].make[j]; 
} 
mass_middleMake[i]/=5; 
} 

for(int i=0;i<*N;i++) 
{ 
printf("mid_St[%d]=%lf\n",i,mass_middleMake[i]); 
} 




//���������� ���. ��������� � ����������� ������
//������� ������ �� ���������� � ������.������������ ���������
//���������� ������ �� ����� ��������� � ������ ��� ������������ ������� ������
//��������� ����� ��������� �� �������� �����
//������� � �������

 int count_st=0;
for(int i=0;i<*N;i++) 
{ 
 if(mass_middleMake[i]>=*mUn)
		{
			count_st++;
		}
}

STUDENTdef *students_n=(STUDENTdef*)malloc(count_st*sizeof(STUDENTdef));
	int index_nStruct=0;
	for(int i=0;i<*N;i++)
	{
		if(mass_middleMake[i]>=*mUn)
		{
			students_n[index_nStruct]=students[i];
			index_nStruct++;
		}
	}

	printf("-------------------------TEST-------------------------\n");
	Print_TableStudents(students_n,&count_st,mUn);
	//������� ������ ��������� ������ ������� ��������
	//PrintArray(students_n,&count_st);


}

/*--------------------------------������� ������ ������� �� ����������--------------*/ 
void Print_TableStudents(STUDENTdef *students,int *N,double *mUn)
{
	double mid[*N];
	for(int i=0;i<*N;i++)
	{
		for(int j=0;j<5;j++)
		{
			mid[i]+=students[i].make[j];
		}
		mid[i]/=5;
	}
	printf("=======List student with make >middle make for University=========\n"); 
			printf(" SerName         | Name       | SecondName        | Make         |\n ");
	for(int i=0;i<*N;i++)
	{
		if(mid[i]>=10)
		{
			printf("%s               %s    	    %s                  %lf   \n",students[i].SerName,students[i].Name,students[i].SecondName,mid[i]);
		}
	}
	for(int i=0;i<*N;i++)
	{
		if(mid[i]>=*mUn && mid[i]<10)
		{
			printf("%s               %s    	    %s                  %lf   \n",students[i].SerName,students[i].Name,students[i].SecondName,mid[i]);
		}
	}



	
} 




