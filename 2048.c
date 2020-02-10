#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
int control(int p[4][4],int dir,int *point,int *record);
void savedata();
void readdata();
void random(int p[4][4]);
void gametable(int p[4][4]);
void mainwindows();
int check(int p[4][4]);
int table[4][4];
int main(int argv, char*argc[])
{
    int a;
    int dir1,dir2,point=0,record=0;
    int *ppoint=&point,*precord=&record;
    int mod;
    while(1){
        mainwindows();
        a=getch(); 
        if(a=='1'){
            printf("was uesed");
            readdata();
        }
        else if(a=='2'){ 
			while(1){ 
                random(table);
                system("cls"); 
                gametable(table);
                dir1=getch();
                if(dir1>=0&&dir1<=127){
                    control(table,dir1,ppoint,precord);    
                }
                else{
                    dir2=getch();
                    control(table,dir1,ppoint,precord);
                }    
            }
		}
        else if(a=='3'){
            savedata();
            printf("Your record has been saved!\nPress any key to quit\n");
            system("pause");
            break;
        }
        else {
            printf("Wrong Input!Try again!\n");
            system("pause");
            system("cls");
        }
    }
    return 0;
}
void mainwindows()
{
    printf("\n\n\n\n");
    printf("                         ********************************************************************\n");
	printf("                         *                                                                  *\n");    
	printf("                         *                  ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" 2 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1|FOREGROUND_RED | FOREGROUND_GREEN);
    printf("                                             *\n");                            
	printf("                         *                            ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" 0 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1|FOREGROUND_RED | FOREGROUND_GREEN);
    printf("                                   *\n");
	printf("                         *                                      ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" 4 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1|FOREGROUND_RED | FOREGROUND_GREEN);
    printf("                         *\n");
	printf("                         *                                                ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    printf(" 8 ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1|FOREGROUND_RED | FOREGROUND_GREEN);
    printf("               *\n");
	printf("                         *                                                                  *\n");
	printf("                         *         ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 | FOREGROUND_RED);   
    printf("                  1.Record List");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 |FOREGROUND_RED | FOREGROUND_GREEN);
    printf("                          *\n");
	printf("                         *                                                                  *\n");
	printf("                         *         ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 | FOREGROUND_RED);
    printf("                  2.Game Begin");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 |FOREGROUND_RED | FOREGROUND_GREEN);
    printf("                           *\n");
	printf("                         *                                                                  *\n");
	printf("                         *         ");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 | FOREGROUND_RED);
    printf("                  3.Quit");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 |FOREGROUND_RED | FOREGROUND_GREEN);
    printf("                                 *\n");
	printf("                         ********************************************************************\n");
}
void gametable(int p[4][4])
{
    int i,j;
    for (i = 0; i <4; i++)
    {
        printf("  ");
        for(j = 0; j <4; j++)
        {
            if(p[i][j]==0) printf("     ");
            else {
                if(p[i][j]>=0&&p[i][j]<=9)  printf("  %d  ",p[i][j]);
                if(p[i][j]>=10&&p[i][j]<=99)  printf(" %d  ",p[i][j]);
                if(p[i][j]>=100&&p[i][j]<=999)  printf(" %d ",p[i][j]);
                if(p[i][j]>=1000&&p[i][j]<=9999)  printf("%d ",p[i][j]);
                if(p[i][j]>=10000&&p[i][j]<=99999)  printf("%d",p[i][j]);
            }
            if(j==3){
                printf("\n");
                break;
            }
            printf("|");
        }
        if(i==3) break;
        printf("  -----------------------"); 
        printf("\n");       
    }    
}
void random(int p[4][4])
{
    srand(time(NULL));
    int x,y,z;
    z=rand()%3;
    if(z==0){  
        while (1){
            x=rand()%4;
            y=rand()%4;
            if(p[x][y]==0){
                 p[x][y]=2;
                 break;
             }    
        }
        
    }
    else{   
        while (1){
            x=rand()%4;
            y=rand()%4;
            if(p[x][y]==0){
                 p[x][y]=4;
                 break;
             }    
        }
    }    
}

void savedata()
{
    
}
void readdata()
{

}
int control(int p[4][4],int dir,int *point,int *record) 
{
    int i,j;
    if(dir==72||dir==119){
        int check[4]={0,0,0,0};
        for(i=1;i<=3;i++){
            for(j=0;j<4;j++){
                if(p[i][j]!=0){    
                    int t=i-1,len=0;
                    for(;t>=0;t--){
                        if(p[t][j]==0){
                            len++;
                        }
                        else break;
                    }
					if(len!=0){                    
						p[i-len][j]=p[i][j]; 
                    	p[i][j]=0;
					}        
                    if((i-len)==0)  
                        continue;
                    else if((i-len)>0){
                        if(i==1){
                            if(p[i-len][j]==p[i-len-1][j]){
                                p[i-len-1][j]*=2;
                                p[i-len][j]=0;
                                point+=(p[i-len][j]*2);
                                check[j]=1;
                            }
                        }
                        else if(i==2&&check[j]==0){
                            if(p[i-len][j]==p[i-len-1][j]){
                                p[i-len-1][j]*=2;
                                p[i-len][j]=0;
                                point+=(p[i-len][j]*2);
                                check[j]=2;
                            }
                        }
                        else if(i==3&&check[j]!=2){
                            if(p[i-len][j]==p[i-len-1][j]){
                                p[i-len-1][j]*=2;
                                p[i-len][j]=0;
                                point+=(p[i-len][j]*2);
                            }
                        }    
                    }
                }
            }
        }
    }
    else if(dir==80||dir==115){
        int check[4]={0,0,0,0};
        for(i=2;i>=0;i--){
            for(j=0;j<4;j++){
                if(p[i][j]!=0){     
                    int t=i+1,len=0;
                    for(;t<4;t++){
                        if(p[t][j]==0){
                            len++;
                        }
                        else break;
                    }
					if(len!=0){
						p[i+len][j]=p[i][j]; 
                    	p[i][j]=0;	
					}                            
                    if((i+len)==3)  
                        continue;
                    else if((i+len)<3){
                        if(i==2){
                            if(p[i+len][j]==p[i+len+1][j]){
                                p[i+len+1][j]*=2;
                                p[i+len][j]=0;
                                point+=(p[i+len][j]*2);
                                check[j]=1;
                            }
                        }
                        else if(i==1&&check[j]==0){
                            if(p[i+len][j]==p[i+len+1][j]){
                                p[i+len+1][j]*=2;
                                p[i+len][j]=0;
                                point+=(p[i+len][j]*2);
                                check[j]=2;
                            }
                        }
                        else if(i==0&&check[j]!=2){
                            if(p[i+len][j]==p[i+len+1][j]){
                                p[i+len+1][j]*=2;
                                p[i+len][j]=0;
                                point+=(p[i+len][j]*2);
                            }
                        }    
                    }
                }
            }
        }
    }
    else if(dir==75||dir==97){
        int check[4]={0,0,0,0};
        for(j=1;j<=3;j++){
            for(i=0;i<4;i++){
                if(p[i][j]!=0){     
                    int t=j-1,len=0;
                    for(;t>=0;t--){
                        if(p[i][t]==0){
                            len++;
                        }
                        else break;
                    }
					if(len!=0){
                    	p[i][j-len]=p[i][j]; 
                    	p[i][j]=0;
                	}
                    if((j-len)==0)  
                        continue;
                    else if((j+len)>0){
                        if(j==1){
                            if(p[i][j-len]==p[i][j-len-1]){
                                p[i][j-len-1]*=2;
                                p[i][j-len]=0;
                                point+=(p[i][j+len]*2);
                                check[i]=1;
                            }
                        }
                        else if(j==2&&check[i]==0){
                            if(p[i][j-len]==p[i][j-len-1]){
                                p[i][j-len-1]*=2;
                                p[i][j-len]=0;
                                point+=(p[i][j-len]*2);
                                check[i]=2;
                            }
                        }
                        else if(j==3&&check[i]!=2){
                            if(p[i][j-len]==p[i][j-len-1]){
                                p[i][j-len-1]*=2;
                                p[i][j-len]=0;
                                point+=(p[i][j-len]*2);
                            }
                        }    
                    }
                }
            }
        }
    }
    else if(dir==77||dir==100){
        int check[4]={0,0,0,0};
        for(j=2;j>=0;j--){
            for(i=0;i<4;i++){
                if(p[i][j]!=0){     
                    int t=j+1,len=0;
                    for(;t<4;t++){
                        if(p[i][t]==0){
                            len++;
                        }
                        else break;
                    }
					if(len!=0){        
                    	p[i][j+len]=p[i][j]; 
                    	p[i][j]=0;
                	}
					if((j+len)==3)  
                        continue;
                    else if((j+len)<3){
                        if(j==2){
                            if(p[i][j+len]==p[i][j+len+1]){
                                p[i][j+len+1]*=2;
                                p[i][j+len]=0;
                                point+=(p[i][j+len]*2);
                                check[i]=1;
                            }
                        }
                        else if(j==1&&check[i]==0){
                            if(p[i][j+len]==p[i][j+len+1]){
                                p[i][j+len+1]*=2;
                                p[i][j+len]=0;
                                point+=(p[i][j+len]*2);
                                check[i]=2;
                            }
                        }
                        else if(j==0&&check[i]!=2){
                            if(p[i][j+len]==p[i][j+len+1]){
                                p[i][j+len+1]*=2;
                                p[i][j+len]=0;
                                point+=(p[i][j+len]*2);
                            }
                        }    
                    }
                }
            }
        }
	}
    else{
        return 1;   
    }
}

// void random(int p[4][4])
// {
//     srand(time(NULL));
//     int x,y,z,flag=0;
//     z=rand()%3;     //三种情况：生成2,2；2,4；4,4
//     if(z==0){       //2,2
//         while(flag!=2){
//             x=rand()%4;
//             y=rand()%4;
//             if(p[x][y]==0){
//                 p[x][y]=2;
//                 flag++;
//             }
//         }        
//     }
//     else if(z==1){  //2,4
//         while(flag!=2){
//             x=rand()%4;
//             y=rand()%4;
//             if(p[x][y]==0){
//                 p[x][y]=4;
//                 flag++;
//             }
//             if(flag==1){
//                 while(1){
//                 }    
//             }
//         }        
//     }
//     else if(z==2){  //4,4
//         while(flag!=2){
//             x=rand()%4;
//             y=rand()%4;
//             if(p[x][y]==0){
//                 p[x][y]=4;
//                 flag++;
//             }
//         } 
//     }
// }