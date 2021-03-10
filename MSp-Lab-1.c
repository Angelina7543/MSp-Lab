#include<conio.h>
#include<stdio.h>

int main()
{
   int Mat_Smej[100][100]={0}; //Matrita smejnosti
   int Mat_Inc[100][100]={0}; //Matrita incidentnosti
   int Spisok[100][100]={0}; 
   int Kol_Ver, Kol_Sveaz;
   int i, j;

   unsigned graf;


    printf("1) Matrita smejnosti \n");
    printf("2) Matrita intidentnosti \n");
    printf("3) Spisok \n");

    printf("\n");

    printf("Vibrati variant, vvesti cislo -  ");
    scanf("%d", &graf);

//Utocnenia
    printf("\n Kolicestvo versin? \n");
    scanf("%d", &Kol_Ver);
    printf(" Kolicestvo sveazei? \n");
    scanf("%d", &Kol_Sveaz);


    if (graf > 3) {
        graf = graf % 3;
    }

    switch (graf) {

// MATRITA SMEJNOSTI
    case 1:

       printf("\n Matrica smejnosti - vesti cisla: \n");
    for ( i=1; i<=Kol_Ver; i++)
    {
    for ( j=1; j<=Kol_Ver; j++)

        scanf("%d", &Mat_Smej[i][j]);
    }
printf("\n");

//Matrica smejnosti (vivod)

    printf("\n Matrica smejnosti rezulitat: \n");
    printf("\n");
    printf("   |");
    for ( i=1; i<=Kol_Ver; i++)
    if ( i<10 ) printf(" X%d |", i);
       else printf(" X%d |", i);
    printf("\n");
    for ( j=1; j<=Kol_Ver; j++)
    printf("------");
    printf("\n");
    for ( i=1; i<=Kol_Ver; i++)
    {
    if ( i<10 ) printf("X%d |", i);
       else printf("X%d |", i);
    for ( j=1; j<=Kol_Ver; j++)
        printf("  %d |", Mat_Smej[i][j]);
    printf("\n");
    for ( j=1; j<=Kol_Ver; j++)
    printf("------");
    printf("\n");
    }
    for ( j=0; j<=Kol_Ver; j++)
    printf("   |");
    printf("\n");
        break;

//MATRITA INTIDENTNOSTI
    case 2:

        printf("\n Matrica incidentnosti - vesti cisla: \n");
    for ( i=1; i<=Kol_Sveaz; i++)
    {
    for ( j=1; j<=Kol_Ver; j++)
        scanf("%d", &Mat_Inc[i][j]);
    }
printf("\n");

//Matrica incidentnosti (vivod)

    printf("\n Matrica incidentnosti rezulitat: \n");
    printf("\n");
    printf("   |");
    for ( i=1; i<=Kol_Ver; i++)
    if ( i<10 ) printf(" X%d |", i);
       else printf(" X%d |", i);
    printf("\n");
    for ( j=1; j<=Kol_Ver; j++)
        printf("------");
        printf("\n");
    for ( i=1; i<=Kol_Sveaz; i++)
    {
    if ( i<10 ) printf("U%d |", i);
       else printf("U%d |", i);
    for ( j=1; j<=Kol_Ver; j++)
        if ( Mat_Inc[i][j]<0 ) printf(" %d |", Mat_Inc[i][j]);
           else printf("  %d | ", Mat_Inc[i][j]);
    printf("\n");
     for ( j=1; j<=Kol_Ver; j++)
    printf("------");
    printf("\n");
    }
     for ( j=0; j<=Kol_Ver; j++)
    printf("   |");
    printf("\n");
        break;

//SPISOK
    case 3:
        printf("\n Spisok - vesti cisla: \n");
    for ( i=1; i<=Kol_Ver; i++)
    {
    for ( j=1; j<=20; j++)
        {
        scanf("%d", &Spisok[i][j]);
        if ( Spisok[i][j]==0 ) break;
        }
    }
printf("\n");

//Spisok (vivod)

    printf("\n Spisok rezulitat: \n");
    printf("\n");
    for ( i=1; i<=Kol_Ver; i++)
    {
    if ( i<10 ) printf(" %d |", i);
       else printf(" %d |", i);
    j=1;
    while(Spisok[i][j]!=0)
    {
    printf(" %d,", Spisok[i][j]);
    j++;
    }
    printf(" 0\n");
    for ( j=1; j<=Kol_Ver; j++)
    printf("-----");
    printf("\n");
    }
    printf("\n");
        break;

    default:  printf("Error");
    }

    getch();
    return 0;
}
