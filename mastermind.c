/*Mastermind*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int Code[4];

int rNbr()
{	
    int random;
	random=rand()%6+1;
	return random;
}

int randomCode(Code secretCode)
{
	int random;
	int i;
	
	for(i=0;i<4;i++)
	{
		random=rNbr();
		secretCode[i]=random;
	}
}

int Comparaison (Code secretCode)
{
	do
	{
		randomCode(secretCode);
	}
	while( (secretCode[0]==secretCode[1]) || (secretCode[0]==secretCode[2]) || (secretCode[0]==secretCode[3]) || (secretCode[1]==secretCode[2]) || (secretCode[1]==secretCode[3]) || (secretCode[2]==secretCode[3]) );
}

void secretColorConversion(Code secretCode)
{
    char colorCode[4];
	int i;
	
    for(i=0;i<4;i++)
    {
        if(secretCode[i]==1) colorCode[i]='N';
        else if(secretCode[i]==2) colorCode[i]='B';
        else if(secretCode[i]==3) colorCode[i]='V';
        else if(secretCode[i]==4) colorCode[i]='W'; 
        else if(secretCode[i]==5) colorCode[i]='R';
        else if(secretCode[i]==6) colorCode[i]='J';
    }
    printf("%s \n",colorCode);
}
int GPosition(Code colorInput, Code secretCode)
{
    int gPosition=0;
    int i,j;
    for(i=0 ; i<4 ; i++)
        for(j=0 ; j<4 ; j++)
        {
            if(colorInput[j]==1 || colorInput[j]==2 || colorInput[j]==3 || colorInput[j]==4 || colorInput[j]==5 || colorInput[j]==6)
            {
                if(secretCode[i]==colorInput[j])
                    if(i==j)
                        gPosition=gPosition+1;            
            }
            else
                gPosition=0;
        }
    return gPosition;
}

int BPosition(Code colorInput, Code secretCode)
{
    int bPosition=0;
    int i,j;
    for(i=0 ; i<4 ; i++)
        for(j=0 ; j<4 ; j++)
        {
            if(colorInput[j]==1 || colorInput[j]==2 || colorInput[j]==3 || colorInput[j]==4 || colorInput[j]==5 || colorInput[j]==6)
            {
                if(secretCode[i]==colorInput[j])
                    if(i!=j) 
                        bPosition=bPosition+1;
            }
            else
                bPosition=0;
        }
    return bPosition;
}

int main()
{
    system("cls" ); 
    Code colorInput;
    Code secretCode;
    int i;
    int gPosition,bPosition;
    int Try=0;
    int goodCode=0;
    char colorCode[4];
    
	srand(time(NULL));
	Comparaison(secretCode);
	
	printf("Vous disposez de 6 lettres | N | B | V | W | R | J |");
	printf("Entrez les lettres en ligne\n");
	printf(" Comme ceci : RJBN ou rjbn \n");
	printf(" Et non comme cela : \n R \n J\n B\n N\n");
	printf("\n\n" );
    printf("| Essai | A | B | C | D |    |    Reponse   |          |   Entrer     |\n");
    printf("|       |   |   |   |   |    |   gPosition  | bPosition|  | Couleur |\n");
    
    do
    {
        printf("|~~~~~~~|~~~|~~~|~~~|~~~|    |~~~~~~|~~~~~~~|  |   ");
        
        scanf("%s",&colorCode);
        printf("|%4d   |",Try+1); 
        caractersDisplay(colorCode);
        convertColorIput(colorInput, colorCode);
    
        gPosition=GPosition(colorInput,secretCode);
        bPosition=BPosition(colorInput,secretCode);
        
        printf("    |   %d  |   %d   | ", gPosition,bPosition); 
        printf("\n"); 
        
        Try=Try+1;
        for(i=0 ; i<4; i++)
            if(secretCode[i]==colorInput[i]) 
                goodCode += 1;
            if(goodCode==4) 
                Try=10;
    }while(Try!=10);
    
    if(goodCode==4)
    {
        printf("Vous avez gagné");
        secretColorConversion(secretCode);
    }
    else 
    {
        printf("Vous avez perdu");
        printf("\n\n Le code Secret etait :");
        secretColorConversion(secretCode);
    }

    system("pause");
    return 0;
}
