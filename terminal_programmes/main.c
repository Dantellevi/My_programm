#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <malloc.h> 

/* 
Ведомость абитуриентов, сдавших вступительные экзамены 
в университет, содержит ФИО абитуриента, оценки. 
Определить средний балл по университету и вывести список 
абитуриентов, средний балл которых выше среднего балла по университету. 
Первыми в списке должны идти студенты, сдавшие все экзамены на 10.(без использования указателей) 
-В радиоателье хранятся квитанции о сданной в ремонт радиоаппаратуре. 
Каждая квитанция содержит следующую информацию: 
наименование группы изделий (телевизоры, радиоприемники и т. п.), 
марку изделия, дату приемки в ремонт, 
состояние готовности заказа (выполнен, не выполнен). 
Вывести информацию о состоянии заказов на текущие сутки 
для заданной группы изделий.(использовать указатели и динамическое выделение памяти под структуры). 


*/ 





typedef struct 
{ 
	char SerName[50]; 
	char Name[50]; 
	char SecondName[50]; 
	int make[5]; 

}STUDENTdef; 


/*----------------------Функция заполнения листа со студентами------------------*/ 
void Fill_StudentsList(STUDENTdef *students,int *N); 
/*---------------------Функция вывода данных студентов----------------*/ 
void PrintArray(STUDENTdef *students,int *N); 
/*------------------------Функция нахождения среднего балла по университету------------*/ 
double MidleMake(STUDENTdef *students,int *N); 
/*--------------------------------Функция нахождения студентов у которых средний бал выше среднего бала по университету--------------*/ 
void Serch_Students(STUDENTdef *students,int *N,double *mUn); 
/*--------------------------------Функция нахождения студентов у которых за все экзамены 10--------------*/ 
void Serch_10STUDENTS(STUDENTdef *students,int *N,STUDENTdef *students_10); 
/*--------------------------------Функция вывода таблицы со студентами--------------*/ 
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

/*----------------------Функция заполнения листа со студентами------------------*/ 
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


/*---------------------Функция вывода данных студентов----------------*/ 
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


/*------------------------Функция нахождения среднего балла по университету------------*/ 
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

/*--------------------------------Функция нахождения студентов у которых средний бал выше среднего бала по университету--------------*/ 
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




//определяем кол. студентов с необходимым баллом
//создаем массив со структурой с найден.колличеством студентов
//записываем данные из одной структуры в другую при соответствии средних баллов
//сортируем новую структуру по среднему баллу
//выводим в консоль

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
	//Функция вывода элементов нового массива структур
	//PrintArray(students_n,&count_st);


}

/*--------------------------------Функция вывода таблицы со студентами--------------*/ 
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




