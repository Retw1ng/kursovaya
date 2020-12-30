#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <tchar.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
int** arr;
FILE* data;
int n;
int** array;


int* dynamic_dist(int count) {

	int* dist;
	dist = (int*)malloc(count * sizeof(int));
	return dist;

}

void generate_pow1(int* massiv, int count) {
	for (int i = 0; i < count; i++) {
		massiv[i] = 0;
	}
}
int** dynamic(int count) {

	int** mass;
	mass = (int**)malloc(count * sizeof(int*));
	for (int i = 0; i < count; i++) mass[i] = (int*)malloc(count * sizeof(int));
	return mass;

}

void print(int** mass, int count) {
	data = fopen("data.txt", "a");
	printf(" ");
	fprintf(data, " ");
	for (int k = 1; k <= count; k++) {
		printf("%d ", k);
		fprintf(data, "%d ", k);
	}
	printf("\n —---------\n");
	fprintf(data, "\n —---------\n");
	for (int i = 0; i < count; i++) {
		printf("%d |", i + 1);
		fprintf(data, "%d |", i + 1);
		for (int j = 0; j < count; j++) {
			printf("%d ", mass[i][j]);
			fprintf(data, "%d ", mass[i][j]);
		}
		printf("\n");
		fprintf(data, "\n");
	}
	fclose(data);
}

void kurs() {
	int test = 0;
	int m = 0;
	int* pow1;
	int pow_matrix;
	srand(time(NULL));
	pow1 = dynamic_dist(n);
	generate_pow1(pow1, n);

	for (int i = 0; i < n; i++) {
		pow_matrix = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) pow_matrix++;
		}
		pow1[i] = pow_matrix;
	}
	data = fopen("data.txt", "a");

	printf("Изолированные вершины - ");
	fprintf(data, "Изолированные вершины - ");

	for (int i = 0; i < n; i++) {
		if (pow1[i] == 0) {
			m = i + 1;
			printf(" %d ", m);
			test++;
			fprintf(data, "%d ", m);


		}
	}
	if (test == 0) {
		printf("Таких вершин нет");
		fprintf(data, "Таких вершин нет");
	}
	test = 0;
	fprintf(data, "\n");
	fclose(data);
	printf("\n");
}



void random() {
	int test = 0;
	int c;
	int min = 1000;
	srand(time(NULL));
	printf("Введите порядок массива - ");
	scanf("%d", &n);
	printf("Введите вероятность выпадения 0 в процентах - ");
	scanf("%d", &c);
	arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) arr[i] = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				int v;
				v = rand() % 100;
				if (v > c) {
					arr[i][j] = 1;
				}
				else {
					arr[i][j] = 0;
				}
				arr[j][i] = arr[i][j];
			}
			else if (i == j) arr[i][j] = 0;
		}
	}
	print(arr, n);
	printf(" ");
}

void file() {
	char OPEN = 'A';
	char name[50];
	FILE* fp;
	int s, k = 0;
	int v;
	int num;
	printf("Введите название файла для чтения значений, но не более 50 символов (Пример: vvod.txt):");
	scanf("%s", name);
	if ((fp = fopen(name, "r")) == NULL) {
		while ((OPEN != '1')) {
			printf("Данного файла не существует. Проверьте правильность ввода названия файла!\n");
			printf("Для выхода из программы нажмите - 1\n");
			scanf("%c", &OPEN, 1);
			if (OPEN == '1') {
				system("cls");
				exit(0);
			}
		}
	}

	if (OPEN == 'A') {
		while ((fscanf(fp, "%d", &s) != EOF)) {
			v = (fscanf(fp, "%d", &s));
			if (v == 0) {
				printf("Неверный формат данных! Проверьте файл.\n");
				exit(0);
				break;
			}
		}
	}

	fclose(fp);
	fp = fopen(name, "r");
	if (OPEN == 'A') {

		while ((fscanf(fp, "%d", &s) != EOF)) {
			if (!fp) break;
			n += 1;
		}
		rewind(fp);
		num = sqrt(n);
		printf("%d\n", num);
		arr = dynamic(num);

		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				fscanf_s(fp, "%d", &arr[i][j]);
			}
		}
		printf("Массив считан из файла.\n");
		print(arr, num);

		fclose(fp);
		n = num;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x;
	printf("\n Введите цифру 1 для рандомного заполнения ");
	printf("\n Введите цифру 2 считывания массива из файла ");
	printf("\n Введите 0 чтобы выйти \n");
	printf(" Ожидается ввод: —> ");
	scanf("%d", &x);
	data = fopen("data.txt", "w");
	fclose(data);

	while (x != 0) {
		if (x == 1) {
			random();
			kurs();
		}
		if (x == 2) {
			file();
			kurs();
		}
		if (x > 2) {
			printf("Такого пункта меню не существует \n");
		}
		scanf("%d", &x);
	}
}