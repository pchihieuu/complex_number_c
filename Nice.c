#include <stdio.h>
#include <conio.h>
 
typedef struct
{
float real; // phan thuc
float image; // phan ao
 
}MCK;
 
void ImportMCK(MCK *comp, const char name);
MCK CalMCK(MCK compA, MCK compB, const char op);
void ShowMCK(MCK comp, const char name);
 
 
void main()
{
MCK compA, compB, compC;
int sel;
char c;
// Nhap 2 so phuc A,B
ImportMCK(&compA, 'A');
ImportMCK(&compB, 'B');
 
ShowMCK(compA, 'A');
ShowMCK(compB, 'B');
do
{
printf("\n\n1. Cong 2 so phuc: C = A+B");
printf("\n2. Tru 2 so phuc: C = A-B");
printf("\n3. Nhan 2 so phuc: C = A*B");
printf("\n4. Chia 2 so phuc: C = A/B");
printf("\n5.Quay lai ban dau");
printf("\nBan chon: ");
scanf("%d", &sel);
 
switch(sel)
{
case 1:
compC = CalMCK(compA, compB, '+');
ShowMCK(compC,'C');
break;
case 2:
compC = CalMCK(compA, compB, '-');
ShowMCK(compC, 'C');
break;
case 3:
compC = CalMCK(compA, compB, '*');
ShowMCK(compC, 'C');
break;
case 4:
compC = CalMCK(compA, compB, '/');
ShowMCK(compC, 'C');
break;
}
printf("\nBan co muon tiep tuc ko: (y/n)?");
fflush(stdin);
c = getchar();
}
while( c == 'y' || c == 'Y');
getch();
}
 
// Ham nhap so phuc
void ImportMCK(MCK *complex, const char name)
{
printf("\n=============So phuc %c================", name);
printf("\nPhan thuc: ");
scanf("%f", &complex->real);
printf("\nPhan ao: ");
scanf("%f", &complex->image);
}
 
// Ham tinh toan so phuc
MCK CalMCK(MCK compA, MCK compB, const char op)
{
MCK compC;
switch(op)
{
case '+': // A+B
compC.real = compA.real + compB.real;
compC.image = compA.image + compB.image;
break;
case '-': // A-B
compC.real = compA.real - compB.real;
compC.image = compA.image - compB.image;
break;
case '*': // A*B
compC.real = compA.real*compB.real - compA.image*compB.image;
compC.image = compA.real*compB.image + compA.image*compB.real;
break;
case '/': // A/B
compC.real = (float)(compA.real*compB.real + compA.image*compB.image)/
(compB.real*compB.real + compB.image*compB.image);
compC.image = (float)(compA.image*compB.real - compA.real*compB.image)/
(compB.real*compB.real + compB.image*compB.image);
break;
default:
printf("\nToan tu khong hop le");
}
return compC;
}
 
// Ham hien thi so phuc
void ShowMCK(MCK complex, const char name)
{
if(complex.image > 0)
printf("\nSo phuc %c: %0.2f + %0.2fi", name, complex.real, complex.image);
else if(complex.image == 0)
printf("\nSo phuc %c: %0.2f", name, complex.real);
else
printf("\nSo phuc %c: %0.2f - %0.2fi", name, complex.real, (-1)*complex.image);
}