/*

사목게임 구현
요구 사항
1. 사목게임(6x7)
2. CRUD 구현(file + linked list)
3. 포인터를 이용할 것

구현된 기능마다 점수가 나눠져 있음

총 100점

사목게임(60):
    기본구현(25):

    채점기능(35):
        세로(7)
        가로(7)
        대각선(16)
    

CRUD(40):
    CREAT(10)
    READ(10)
    UPDATE(10)
    DELETE(10)

*/
//로그인 없이 플레이하면 점수가 파일에 저장되지 않음. 이렇게 되면


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define H 6
#define W 7

//About game
void menu(void);
void setGround(void);
void makeGround(void);
void startGame(void);
void printRes(int);
void marker(int, int);
int p_turn(void);
int grade(int);
int gameMenu(void);

//About CRUD
void Login(void);
void signup(void);
void deleteUser(void);
void modifyUser(void);
void showChart(void);

//About linked list
void freeNode(void);
void setNode(FILE*);

//About file
FILE* openFileUserInfo(void);

char ground[H][W];
int count = 0;

typedef struct User{

    char id[100];
    char password[100];

    int win;
    int lose;


    struct User* next;

}User;

User* head = NULL;
User* last = NULL;

int main(){
    
    while(1){

        menu();

        int n;
        scanf("%d", &n);
        getchar();

        switch (n){
            case 1:

                Login();

                break;

            case 2:

                setGround();
                makeGround();
                startGame();

                break;

            case 3:

                signup();

                break;

            case 4:


                system("clear");
                printf("프로그램을 종료합니다.");
                getchar();
                system("clear");
                exit(0);

                break;

            case 5:

                showChart();

                break;

            default:
                break;

    
        }

        system("clear");

    }

    return 0;

}

void menu(){


    system("clear");

    printf("                           ======사목게임======\n\n");

    printf("         <<로그인 없이도 플레이 가능!(점수는 기록되지 않아요ㅠ)>>\n\n");
    printf("                           ");
    printf("1. 로그인\n");
    printf("                           ");
    printf("2. 게임 시작\n");
    printf("                           ");
    printf("3. 회원가입\n");
    printf("                           ");
    printf("4. 게임 종료\n");
    printf("                           ");
    printf("5. 순위\n");
    printf("                           ");
    printf(":");

}

void setGround(){

    for(int i = 0;i<H;i++){

        for(int k = 0;k<W;k++){

            ground[i][k] = '_';

        }

    }

}

void makeGround(){

    system("clear");

    printf("                        ");

    for(int i = 1;i<8;i++){
        
        printf("  %d ", i);

    }

    printf("\n");

    for(int i = 0;i<H;i++){

        printf("                        ");

        for(int k = 0;k<W;k++){

            printf("|_%c_",ground[i][k]);

        }

        printf("|\n");

    }

}
void marker(int n, int c){
    
    char maker;
    int i = H-1;
    
    if(c == 1) maker = 'O';
    else maker = '@';
    
    for(;i>=0;i--){
        
        if(ground[i][n-1] == '_'){

            ground[i][n-1] = maker;
            break;

        }
        
    }
    
}
void printRes(int t){
    
    makeGround();
    printf("                        ");
    printf("P%d wins!\n",t);
    
}
void startGame(){

    while(1){

        marker(gameMenu(),p_turn());
        makeGround();

        if(count >= 6){
            
            if(grade(p_turn())) {

                printRes(grade(p_turn()));
                getchar();

                break;

            }
            
        }
        
        count++;

    }

}

int gameMenu(){

    int n;
    printf("                    ");
    printf("P1's maker is O, P2's maker is @\n");
    printf("                    ");
    printf("P%d's turn, Enter the column number: ",p_turn());
    
    scanf("%d",&n);
    getchar();
    
    return n;

}

FILE* openFileUserInfo(){

    FILE *f;

    if((f = fopen("userInformation.txt", "r")) == NULL){

        printf("파일을 열 수가 없습니다.\n");
        exit(0);
        
    }

    else return f;
    
    return 0;

}

void setNode(FILE* f){
    
    
    User* cur = NULL;
    User* pre = NULL;

    while(1){

        User* node = (User*)malloc(sizeof(User));
            
        if(EOF == (fscanf(f,"%s %s %s %s",node->id, node->password, node->win, node->lose ))) break;


        if(head == NULL){

            head = node;
            node->next = last;

        }
        else{

            if(node->eng < head->eng){
               
                User* tmp = NULL;

                tmp = head;
                head = node;
                head->next = tmp;

            }
            else{

                pre = head;
                cur = pre->next;

                while(1){

                    if(cur == NULL && strcmp(node->eng,pre->eng)>0){

                        pre->next = node;
                        pre->next->next = cur;
                       
                        break;

                    }
                    else if(strcmp(node->eng,cur->eng)<0){

                        User* tmp = NULL;

                        tmp = cur;
                        pre->next = node;
                        pre->next->next = tmp;

                        break;

                    }
                    else{
                        
                        pre = cur;
                        cur = cur->next;

                    } 

                }
 
            }

        }
       
        count++;

    }

    fclose(f);
    
    

}

void Login(){

}
void signup(){

    char id[100];
    char password[100];

    printf("+++++++++++회원가입+++++++++++");

    printf("ID :");
    scanf("%s",id);
    printf("Password :");
    scanf("%s",password);

}

void createUser(){

}
void deleteUser(){

}
void modifyUser(){

}
void showChart(){
    
}

int p_turn(){
    
    int c = count%2;
    
    return c+1;
    
}
int grade(int m){
    
    char maker;
    
    int h,v,d,i,k;
    
    if(m == 1) maker = 'O';
    else maker = '@';

    //Horizontal
    for(i = 0;i<H;i++){

        for(k = 0;k<4;k++){

            h = 0;
            
            for(int j = k ;j<k+4;j++){
                
                if(ground[i][j] == maker) h++;

                else break;
                
            }
            
            if(h == 4 && m == 1) return 1;
            else if(h == 4 && m == 2) return 2;
            
        }
       
    }
    //Vertical
    for(i = 0;i<3;i++){

        for(k = 0;k<W;k++){
            
            v = 0;
            
            for(int j = i;j<i+4;j++){
                
                if(ground[j][k] == maker) v++;

                else break;

            }
            
            if(v == 4 && m == 1) return 1;
            else if(v == 4 && m == 2) return 2;
            
        }

    }
    //Diagonal
    for(int i = 0;i<3;i++){

        for(int k = 0;k<W;k++){
            
            d = 0;
            
            if(k<=3){

                for(int j = 0;j<4;j++){
                    
                    if(ground[i+j][k+j] == maker) d++;

                    else break;

                }

            }

            d = 0;

            if(k>=3){

                for(int j = 0;j<4;j++){
                    
                    if(ground[i+j][k-j] == maker) d++;

                    else break;

                }
                
            }

            if(d == 4 && m == 1) return 1;
            else if(d == 4 && m == 2) return 2;

        }

    }
    
    return 0;
    
}
