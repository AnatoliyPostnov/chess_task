#include <stdio.h>

void king_x(){
	printf("ОШИБКА!!!Введите координату a еще раз:");
	}
void king_y(){
	printf("ОШИБКА!!!Введите координату b еще раз:");
	}
void queen_x(){	
	printf("ОШИБКА!!!Введите координату c еще раз:");	
	}
void queen_y(){	
	printf("ОШИБКА!!!Введите координату d еще раз:");	
	}	
int coordinate(int c){
	int x;
	do{
		scanf("%d",&x);
		if((x<0)||(x>7)){
			if(c==1)
			king_x();
			if(c==2)
			king_y();
			if(c==3)
		    queen_x();
		    if(c==4)
		    queen_y();
			}
	}
	while((x<0)||(x>7));
	return x;
	}
/* Заполнение доски нулями */	
void space(int A[][8],int n,int m){
	for(int j=0;j<=7;j++){
		for(int i=0;i<=7;i++){
			A[i][j]=0;
		}
	}
	}
/* Прорисовка на доске траектории фигуры (цифрами 5) */		
void space_figure(int A[][8],int a,int b){
	for(int i=0;i<=7;i++){
		if (b!=i)
		A[a][i]=5;
		}
	for(int i=0;i<=7;i++){
		if (a!=i)
		A[i][b]=5;
		}
	if(b>a){
		for(int i=0;b-a+i<=7;i++){
			if (a!=i)
			A[i][b-a+i]=5;
		}
	}		
	else {
		for(int i=0;a-b+i<=7;i++){
			if (b!=i)
			A[a-b+i][i]=5;
		}
	}
	for(int i=a,j=b;j!=8&&i>=0;i--,j++)
		A[i][j]=5;
	for(int i=a,j=b;i!=8&&j>=0;i++,j--)
		A[i][j]=5;
	A[a][b]=0;
	}
/*Вывод доски на экран*/		
void space_print_figure(int A[][8],int a,int b){
	for(int j=0;j<=7;j++){
		printf("\n");	
		for(int i=0;i<=7;i++){
			printf("%3d",A[i][j]);
		}	
	}
	printf("\n");
	}	
/* Формирование пространства фигуры */
void space_map(int A[][8],int n,int m,int a,int b){
	space(A,8,8);
	space_figure(A,a,b);
	space_print_figure(A,a,b);	
	}	
/* Проверка ошибок если король под шахом */
int EROR_prog(int A[][8],int a,int b,int B[][8],int c,int d){
	if(A[c][d]==5){
		printf("EROR! Король стоит под шахом");
		return 1;
	}
	if(a==c&&b==d){
		printf("EROR! Координаты фигур совпадают");
		return 1;
		}
	return 0;	
	}
//Определение координат, куда может походить ферзь, чтобы поставить шах королю
void intersection(int A[][8],int B[][8]){
	int C[20],D[20],l=0;	
	for(int j=0;j<=7;j++){	
		for(int i=0;i<=7;i++){
			if(A[j][i]==B[j][i]&& A[j][i]==5 && B[j][i]==5){
				C[l]=j;
				D[l]=i;
				l++;
				}
				
		}	
	}
	printf("\n Ферзь может походить на следующие позиции, чтобы поставить шах:\n");
	for(int i=0;i<l;i++){
		printf("(%d,%d)",C[i],D[i]);
			
	}
	}

int main(void){
	int a,b,c,d;
	int A[8][8]; /* Определенние массива ячеек при которых королю будет шах */
	int B[8][8]; /* Определенние массива ячеек куда может походить ферзь */
	printf("Программа вычисляет ходы для ферзя, чтобы поставить шах королю в один ход.\n");
	
	printf("Ввод координат нахождения короля (от 0 до 7)");
	printf("Введите координату а:");
	a=coordinate(1);
	printf("Введите координату b:");
	b=coordinate(2);
	printf("Вы ввели координаты короля:(%d,%d)\n",a,b);
	
	/* Формирование пространства со значениями при которых королю будет шах */
	space_map(A,8,8,a,b);
		
	/*Ввод координат ферзя*/
	printf("Ввод координат нахождения ферзя (от 0 до 7)");
	printf("Введите координату c:");
	c=coordinate(3);
	printf("Введите координату d:");
	d=coordinate(4);
	
	/* Проверка ошибок если король под шахом */
	if(EROR_prog(A,a,b,B,c,d))
	return 0;
	
	printf("Вы ввели координаты ферзя:(%d,%d)\n",c,d);
	
	/* Формирование пространства со значениями куда может походить ферзь */
	space_map(B,8,8,c,d);

	/*Определение координат, куда может походить ферзь, чтобы поставить шах королю*/
	intersection(A,B);
	return 0;
	}
