#include<iostream>
#include<string.h>

using namespace std;

class gpokemon
{
private:
	char player1[50];
	int hp;
	int deffense;
	int att;
	char player2[50];
	int hp2;
	int deffense2;
	int att2;
public:
	int total;
	int total1;
	int counter;
	int counter1;
	gpokemon()
	{
		counter = 0;
		strcpy(player1,"");
		strcpy(player2,"");
		counter1 = 0;
		hp = 1;
		att = 1;
		deffense = 1;
		hp2 = 1;
		att2 = 1;
		deffense2 = 1;
	}

	void setplayer(char player[],int h1,int a1,int def1)
	{
		strcpy(player1,player);
		hp = h1;
		att = a1;
		deffense = def1;
	}
		void setplayer2(char player[],int h2,int a2,int def2)
	{
		strcpy(player2,player);
		hp2 = h2;
		att2 = a2;
		deffense2 = def2;
	}
		void attack()
		{
		while(hp >= 0 && hp2 >= 0)
		{
			total = att-deffense2;
		    hp2 = hp2 -total;
			total1 = att-deffense;
		    hp = hp - total1;

			if(hp2 <= 0)
		    {
			    counter++;
		    }
			else if(hp <= 0)
			{
				counter1++;
			}
			else
			{
				counter=0;
				counter1=0;
			}
		}
	}
			void winner()
	{
		if(counter > 0)
		{
			printf("PEMENANGNYA ADALAH %s\n\n",player1);
			printf("Nama PLAYER : %s\n HP : %d\n ATTACK : %d\n DefFENSE : %d\n\n",player1,hp,att,deffense);
			printf(" KALAH ADALAH %s\n",player2);
			printf("Nama PLAYER : %s\n HP : %d\n ATTACK : %d\n DefFENSE : %d\n\n",player2,hp2,att2,deffense2);
		}
		if(counter1 > 0)
		{
			printf("PEEMENANGNYA ADALAH %s\n",player2);
			printf("Nama PLAYER : %s\n HP : %d\n ATTACK : %d\n DefFENSE : %d\n\n",player2,hp2,att2,deffense2);
			printf("KALAH ADALAH  is %s\n",player1);
			printf("Nama PLAYER : %s\n HP : %d\n ATTACK : %d\n DefFENSE : %d\n\n",player1,hp,att,deffense);
		}
	}
};
void main()
{
	gpokemon gameplay;
	int h1,a1,def1,def2,h2,a2;
		char name[100];
	gameplay.setplayer("budi",100,50,90);
	gameplay.setplayer2("agas",100,160,90);
	gameplay.attack();
	gameplay.winner();
}