#include <stdio.h>
void kaidan(int );
int F1 = 1, F2 = 2, F3 = 0, i = 2;
	
int main(void){
	int n , ans = 0;
	do{
	printf("階段の段数 = ");
	scanf("%d", &n);
	}while(n < 3);
	ans = kaidan(n);
	printf("%d 段の登り方 = %d\n", n , ans);
	return 0;
}


void kaidan(int x){
	if (i == x){
		return F3;
	}else{
		F3 = F1 + F2;
		F1 = F2;
		F2 = F3;
		i++;
		kaidan(x);
	}
}
