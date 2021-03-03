#include<stdio.h>
#include<windows.h>

int main(void){
    FILE *fp;
    char buf[1024]={0};
    char aa[20][1024]={0};
    int count = -1;
    int i=0;
    
    if((fp=fopen("aa.txt","r"))!=NULL){
        while(fgets(buf,1024,fp)!=NULL){
            if(strstr(buf,"frame")!=NULL){
                count++;
            }
            if(count>=0){
                strcat(aa[count],buf);
            }
        }
        fclose(fp);

        while(1){
            printf("%s",aa[i++]);
            Sleep(50);
            system("cls");
            if(i>count){
                i=0;
            }
        }
    }
    return 0;
}
