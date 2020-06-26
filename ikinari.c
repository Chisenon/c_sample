#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct character {
	char name[20] ;
	int life , attack , defense ;
} data [] = {{ "    勇者" , 100 , 100 , 100 },      //0
			 { "スライム" ,  50 ,  50 ,  50 },      //1
			 { "  オーク" , 150 ,  70 , 150 },      //2
			 { "ゴブリン" , 150 , 150 ,  70 },      //3
			 { "シャミコ" ,1000 , 500 , 500 }};     //4
	
	
int main(void){
	
	int go = 0 , user = 1 , i ;
	char save;
	int much = 1;
	int cnt = 4;
	int random = 0 , enemyrandom = 0 , enemy = 0;
	int act ,  dmg , point;
	int result = 0;
	int error;
	int command;
	char fake;
	
	struct character *pdt ;
	pdt = data;
	
	printf("ゲームスタート！\n");
	printf("あなた -> * で  ＠  がゴールです！！！\n");
	printf("検討を祈ります！！！\n");
	
	char a[21] = " ___________________"; 
	char b[22] = "|_|_|_|_|_|_|_|_|_|@|";
	char c[22] = "|_|_|_|_|_|_|_|_|_|_|";
	char d[22] = "|_|_|_|_|_|_|_|_|_|_|";
	char e[22] = "|*|_|_|_|_|_|_|_|_|_|";
	
	char now[2] = "*";
	char goal[2] = "@";
	
	while(much != 0){
		
		printf("%s\n", a);
		printf("%s\n", b);
		printf("%s\n", c);
		printf("%s\n", d);
		printf("%s\n", e);
		
		printf("残HP %d \n",(pdt + 0)->life); 
		printf("\n");
		printf("左 : 1\n");
		printf("右 : 2\n");
		printf("前 : 3\n");
		printf("後 : 4\n\n");
		
		printf("どっちに進む？数字を入力してください。:"); 
		fake = getchar();
		while (getchar() != '\n');
		go = fake &0x0f;    // 演算処理
		
		printf("--------------------------------------------------------\n");
		
		if (go == 1){
			if (user - 2 >= 0){
				error = 0;
				
				if (cnt == 4){
					save = e[user];
					e[user] = e[user - 2];
					user = user - 2;
					now[0] = e[user];
					e[user] = save;
					much = strcmp(now, goal);
				}else if (cnt == 3){
					save = d[user];
					d[user] = d[user -2];
					user = user - 2;
					now[0] = d[user];
					d[user] = save;
					much = strcmp(now, goal);
				}else if (cnt == 2){
					save = c[user];
					c[user] = c[user - 2];
					user = user - 2;
					now[0] = c[user];
					c[user] = save;
					much = strcmp(now, goal);
				}else if (cnt == 1){
					save = b[user];
					b[user] = b[user - 2];
					user = user - 2;
					now[0] = b[user];
					b[user] = save;
					much = strcmp(now, goal);
				}else if (cnt == 0){
					save = a[user];
					a[user] = a[user - 2];
					user = user - 2;
					now[0] = a[user];
					a[user] = save;
					much = strcmp(now, goal);
				}
			}else if (user - 2 < 0){
				printf("見えない壁があるみたいだ\n");
				error = 1;
			}
			
		}else if (go == 2){
			if (user +2 >= 0){
				error = 0;
				if (cnt == 4){
					save = e[user];
					e[user] = e[user + 2];
					user = user + 2;
					now[0] = e[user];
					e[user] = save;
					much = strcmp(now, goal);
				}else if (cnt == 3){
					save = d[user];
					d[user] = d[user +2];
					user = user + 2;
					now[0] = d[user];
					d[user] = save;
					much = strcmp(now, goal);
				}else if (cnt == 2){
					save = c[user];
					c[user] = c[user + 2];
					user = user + 2;
					now[0] = c[user];
					c[user] = save;
					much = strcmp(now, goal);
				}else if (cnt == 1){
					save = b[user];
					b[user] = b[user + 2];
					user = user + 2;
					now[0] = b[user];
					b[user] = save;
					much = strcmp(now, goal);
				}else if (cnt == 0){
					save = a[user];
					a[user] = a[user + 2];
					user = user + 2;
					now[0] = a[user];
					a[user] = save;
					much = strcmp(now, goal);
				}
			}else if (user + 2 < 20){
				printf("見えない壁があるみたいだ\n");
				error = 1;
			}
			
		}else if (go == 3){
			error = 0;
			
			if (cnt == 4){
				save = e[user];
				e[user] = d[user]; 
				now[0] = d[user];
				d[user] = save;
				much = strcmp(now,goal);
				cnt = cnt - 1;
			}else if (cnt == 3){
				save = d[user];
				d[user] = c[user]; 
				now[0] = c[user];
				c[user] = save;
				much = strcmp(now,goal);
				cnt = cnt - 1;
			}else if (cnt == 2){
				save = c[user];
				c[user] = b[user]; 
				now[0] = b[user];
				b[user] = save;
				much = strcmp(now,goal);
				cnt = cnt - 1;
			}else if (cnt == 1){
				printf("見えない壁があるみたいだ\n");
				error = 1;
			}
			
		}else if (go == 4){
			error = 0;
			
			if (cnt == 3){
				save = d[user];
				d[user] = e[user]; 
				now[0] = e[user];
				e[user] = save;
				much = strcmp(now,goal);
				cnt = cnt + 1;
			}else if (cnt == 2){
				save = c[user];
				c[user] = d[user]; 
				now[0] = d[user];
				d[user] = save;
				much = strcmp(now,goal);
				cnt = cnt + 1;
			}else if (cnt == 1){
				save = b[user];
				b[user] = c[user]; 
				now[0] = c[user];
				c[user] = save;
				much = strcmp(now,goal);
				cnt = cnt + 1;
			}else if (cnt == 4){
				printf("見えない壁があるみたいだ\n");
				error = 1; 
			}  
		}else{
			printf("もう一度入力してね！\n");
			error = 1;
		}
		
		if (error == 0){
			srand((unsigned int)time(NULL));
			random = rand() % ( 2 + 1 ) + 1;
			
			if (random == 1){
				printf("なにも起きなかった...\n");
			}else if (random == 2){
				printf("休憩した。体力が2回復した。\n");
				(pdt + 0)->life = (pdt + 0)->life + 2;
			}else if (random == 3){
				enemyrandom = rand() % ( 3 + 1 ) + 1;
				printf("%s が現れた！\n", (pdt + enemyrandom)->name);
				enemy = 1;
				printf("--------------------------------------------------------\n");
			}
			
			if (enemy == 1){
				while ((pdt + enemyrandom)->life > 0){
					printf("%8s: HP = %5d, 攻撃力 = %5d, 防御力 = %5d\n", (pdt + 0)->name, (pdt + 0)->life, (pdt + 0)->attack, (pdt + 0)->defense);
					printf("%8s: HP = %5d, 攻撃力 = %5d, 防御力 = %5d\n",(pdt + enemyrandom)->name, (pdt + enemyrandom)->life, (pdt + enemyrandom)->attack, (pdt + enemyrandom)->defense);
					printf("(0) 攻撃\n(1) 強化\n(2) 回復\n");
					printf("Command:");
					scanf("%d", &command);
					switch (command){
						case 0:
							point = (pdt + 0)->attack - (pdt + enemyrandom)->defense;
							(pdt + enemyrandom)->life -= point;
							printf("%s の 攻撃！ %s は %d のダメージを受けた！\n", (pdt + 0)->name, (pdt + enemyrandom)->name, point);
							break;
						case 1:
							point = rand() % ( 49 + 1 ) + 20;
							(pdt + 0)->attack += point;
							printf("%s の 強化！ %s の  攻撃力 が %d 上昇した！\n", (pdt + 0)->name, (pdt + 0)->name, point);
							break;
						case 2:
							point = rand() % ( 49 + 1 ) + 10;
							(pdt + 0)->life += point;
							printf("%s の 回復！  %s の HP が  %d 回復した！\n", (pdt + 0)->name, (pdt + 0)->name, point);
							break;
					}
					
					
					if ((pdt + enemyrandom)->life <= 0){
						printf("\n%s に 勝利した！！\n\n", (pdt + enemyrandom)->name);
						enemy = 0;
						system("PAUSE");
						break;
					}
					
					command = rand() % 3;
					switch (command){
						case 0:
						point = (pdt + enemyrandom)->attack - (pdt + 0)->defense;
						(pdt + 0)->life -= point;
						printf("%s の 攻撃！ %s は %d のダメージを受けた！\n", (pdt + enemyrandom)->name, (pdt + 0)->name, point);
						break;
					case 1:
						point = rand() % ( 49 + 1 ) + 20;
						(pdt + enemyrandom)->attack += point;
						printf("%s の 強化！ %s の  攻撃力 が %d 上昇した！\n", (pdt + enemyrandom)->name, (pdt + enemyrandom)->name, point);
						break;
					case 2:
						point = rand() % ( 49 + 1 ) + 10;
						(pdt + enemyrandom)->life += point;
						printf("%s の 回復！  %s の HP が  %d 回復した！\n", (pdt + enemyrandom)->name, (pdt + enemyrandom)->name, point);
						break;
					}
					
					if ((pdt + 0)->life <= 0){
						printf("\n\n【 %s は 倒されてしまった... 】\n\n", (pdt + 0)->name);
					return 0;
					
					}
				}
			}
			
			enemy = 0;
		}
		
		
		printf("--------------------------------------------------------\n"); 
		}
		if (result == 0){
		printf("ゴールしました！！！おめでとう！\n");
		}
		system("PAUSE");
		printf("--------------------------------------------------------\n");
	return 0;
}
