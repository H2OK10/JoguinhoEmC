
// Meus includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// Meus includes

// Minhas variaveis globais

     int sala = 1;
     int dado;

   // Minhas structs
   
       struct jogador {
       
                int hp;
		int hpfull;
		int forca;
		int defesa;
		int xp;
		int xpneed;
		int lvl;
       
             };

       struct monstros {
       
	        char mname[16];
                int hp;
		int forca;
		int defesa;
		int xp;
       
             };

       struct jogador player = {10,10,2,1,0,10,1};
       struct monstros goblin = {"goblin",5,1,1,5};
       struct monstros *ptrmon;

   // Minhas structs

// Minhas variaveis globais

// Minhas funções

      int chooseMon() {
      
               dado = rand() %2;
 	       if(dado == 0) {
	       
	                dado = 1;      
	           
	            };

	       switch (dado) {
	       
	                case 1 :
				printf("Você encontrou um goblin! \n");
				strcpy(goblin.mname,"goblin");
			        goblin.hp = 5;
				goblin.forca = 1;
				goblin.defesa = 1;
				goblin.xp = 5;
				ptrmon = &goblin;		
				break;
	       
	            };
      
	       return 0;
           };

      int lutar() {
      
               int isluta = 1;
               int turno = 1;
	       int atk;
	       int def;
	       int matk;
	       int mdef;
	       while(isluta == 1) {
	       
	                  if(turno == 1) {
			  
			          dado = rand() %7;
				  if (dado == 0) {
				  
				            dado = 1;
				  
				        };
			          printf("O resultado rolado no seu dado de ataque foi : %d \n", dado);
			          if (dado == 6) {
				  
				            atk = dado + player.forca * 2;   
				  
				        } else {
					
					       atk = dado + player.forca;
					
				           };

                                  dado = rand() %7;
				  if (dado == 0) {
				  
				            dado = 1;
				  
				        };
			          printf("O resultado rolado no dado de defesa do bixano foi : %d \n", dado);
			          if (dado == 6) {
				  
				            mdef = dado + ptrmon->defesa * 2;   
				  
				        } else {
					
					       mdef = dado + ptrmon->defesa;
					
				           };
                                  if (mdef >= atk) {
				  
				             printf("O inimigo bloqueou todo o seu ataque! \n");

				           } else {
					   
					          ptrmon->hp = ptrmon->hp - (atk - mdef);
					          printf("O bixano está com %d de hp \n",ptrmon->hp);

					       };
                                  if (ptrmon->hp <= 0) {
				  
				           printf("O bixano morreu! \n");
					   player.xp = player.xp + ptrmon->xp;
					   sala++;
					   return 0;
				  
				       } else { 
				             printf("Turno do bixano \n");
			                     turno = 2;
					     };
			       };
	       	                  if(turno == 2) {
			  
			          dado = rand() %7;
				  if (dado == 0) {
				  
				            dado = 1;
				  
				        };
			          printf("O resultado rolado no ataque dele foi : %d \n", dado);
			          if (dado == 6) {
				  
				            matk = dado + ptrmon->forca * 2;   
				  
				        } else {
					
					       matk = dado + ptrmon->forca;
					
				           };

                                  dado = rand() %7;
				  if (dado == 0) {
				  
				            dado = 1;
				  
				        };
			          printf("O resultado rolado no seu dado de defesa foi : %d \n", dado);
			          if (dado == 6) {
				  
				            def = dado + player.defesa * 2;   
				  
				        } else {
					
					       def = dado + player.defesa;
					
				           };
                                  if (def >= matk) {
				  
				             printf("Você bloqueou o ataque dele! \n");

				           } else {
					   
					          player.hp = player.hp - (matk - def);
					          printf("Você está com %d de hp \n",player.hp);

					       };
                                  if (player.hp <= 0) {
				  
				           printf("Você morreu! \n");
					   exit(0);
				  
				       } else { 
				             printf("Seu turno! \n");
			                     turno = 1;
					     };
			       };
		         getchar();
	              };

	       return 0;
            };

      int upar() {
      
                if(player.xp >= player.xpneed) {
		 
			 int opti;
		         player.lvl++;
			 printf("Parabens,você avançou de level! \n");
			 printf("E agora está no level %d! \n",player.lvl);
			 printf("Você tem %d de HP,%d de força e %d de defesa \n",player.hp,player.forca,player.defesa);
			 printf("Escolha entre : \n 1- +5 de HP \n 2- +1 de forca \n 3- +1 de defesa \n");
			 scanf("%d",&opti);
			 switch (opti) {
			 
			            case 1 :
					    player.hpfull += 5;
					    printf("Você colocou o seu ponto em HP! \n");
					    break;
			            case 2 :
					    player.forca++;
					    printf("Você colocou o seu ponto em forca! \n");
					    break;
				    case 3 :
					    player.defesa++;
					    printf("Você colocou o seu ponto em defesa! \n");
					    break;
			            default :
			                     printf("Valor incorreto! \n");		    

			       };

			 player.hp = player.hpfull;
			 player.xpneed = (player.xpneed * 2) + player.xp; 
		
		     };
      
		return 0;
           };

      int game() {

 	      printf("Você está na sala %d dessa dungeon daora \n",sala);     
              chooseMon();
	      lutar();
	      upar();
	      game();
              
           };

   // Minha função main
   
        int main() {

                     srand(time(NULL));               
	             printf("Bem-vindo a esse jogo incrivel muito bom mesmo \n");

	             game();
		     return 0;

         	};

   // Minha função main

// Minhas funções
