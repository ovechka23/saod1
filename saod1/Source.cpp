#include<iostream>
#include<stdio.h>

struct student
{
	char name[50];
	char surname[50];
	char patronymic[50];
	double zachetka, sub1, sub2, sub3, sub4, sub5;
};
void read_from_file(student* s, int& count_stud)
{
	FILE* f;
	if (fopen_s(&f, "students.txt", "r") != 0)
	{
		printf("Не удалось открыть файл\n");
		exit(1);
	}
	fscanf_s(f, "%i", &count_stud);
	for (int i = 0; i < count_stud; i++)
	{
		fscanf_s(f, "%s", &s[i].surname, 50);
		fscanf_s(f, "%s", &s[i].name, 50);
		fscanf_s(f, "%s", &s[i].patronymic, 50);
		fscanf_s(f, "%lf", &s[i].zachetka);
		fscanf_s(f, "%lf", &s[i].sub1);
		fscanf_s(f, "%lf", &s[i].sub2);
		fscanf_s(f, "%lf", &s[i].sub3);
		fscanf_s(f, "%lf", &s[i].sub4);
		fscanf_s(f, "%lf", &s[i].sub5);
	}
	fclose(f);
	printf("	Фамилия	  	    Имя	       Отчество № зач.кн.  Инф.  Алг. Геом. Прогр. Физ.\n");
	for (int i = 0; i < count_stud; i++)
	{
		printf("%15s %15s %15s %7.2lf %5.2lf %6.2lf %5.2lf %5.2lf %5.2lf\n", s[i].surname, s[i].name, s[i].patronymic, s[i].zachetka, s[i].sub1, s[i].sub2, s[i].sub3, s[i].sub4, s[i].sub5);
	}
	printf("\n");
}
void out_on_screen(student* s, int& count_stud)
{
	printf("	Фамилия	  	    Имя	       Отчество № зач.кн.  Инф.  Алг. Геом. Прогр. Физ. Ср. балл\n");
	double sr_mark;
	for (int i = 0; i < count_stud; i++)
	{
		sr_mark = (s[i].sub1 + s[i].sub2 + s[i].sub3 + s[i].sub4 + s[i].sub5)/5;
		printf("%15s %15s %15s %7.2lf %5.2lf %6.2lf %5.2lf %5.2lf %5.2lf %5.2lf\n", s[i].surname, s[i].name, s[i].patronymic, s[i].zachetka, s[i].sub1, s[i].sub2, s[i].sub3, s[i].sub4, s[i].sub5, sr_mark);
	}
	printf("\n");

}
void sort_stud(student* s, int& count_stud)
{
	for (int i = 0; i < count_stud - 1; i++)
		for (int j = i + 1; j < count_stud; j++)
		{
			if (strcmp(s[i].surname, s[j].surname) > 0)
			{
				std::swap(s[i].surname, s[j].surname);
				std::swap(s[i].name, s[j].name);
				std::swap(s[i].patronymic, s[j].patronymic);
				std::swap(s[i].zachetka, s[j].zachetka);
				std::swap(s[i].sub1, s[j].sub1);
				std::swap(s[i].sub2, s[j].sub2);
				std::swap(s[i].sub3, s[j].sub3);
				std::swap(s[i].sub4, s[j].sub4);
				std::swap(s[i].sub5, s[j].sub4);
			}
		}
}
void out_on_screenD(student* s, int& count_stud)
{
	printf("	Фамилия	  	    Имя	       Отчество № зач.кн.  Инф.  Алг. Геом. Прогр. Физ. Ср. балл\n");
	double sr_mark;
	for (int i = 0; i < count_stud; i++)
	{
		sr_mark = (s[i].sub1 + s[i].sub2 + s[i].sub3 + s[i].sub4 + s[i].sub5) / 5;
		if (sr_mark>=4.0 and sr_mark<=4.5)
			printf("%15s %15s %15s %7.2lf %5.2lf %6.2lf %5.2lf %5.2lf %5.2lf %5.2lf\n", s[i].surname, s[i].name, s[i].patronymic, s[i].zachetka, s[i].sub1, s[i].sub2, s[i].sub3, s[i].sub4, s[i].sub5, sr_mark);
	}
}


int main()
{
	system("chcp 1251");

	student s[100];
	int count_stud = 0;
	read_from_file(s, count_stud);
	sort_stud(s, count_stud);
	out_on_screen(s, count_stud);
	out_on_screenD(s, count_stud);
	system("pause");
	return 0;
}