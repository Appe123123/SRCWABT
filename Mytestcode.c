#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define height 6
#define width 7

typedef struct User{
    char Name[30];
    char ID[16];
    char Password[16];
    int WIN;
    int LOSE;

    struct User *next;
}User;

FILE* fileRead(void);
void fileSave(FILE *);

//ABOUT GAME
void menuPrint(void);
void setBoard(void);
void makeBoard(void);
void startGame(void);
void printRes(int);
void marker(int, int);
int p_turn(void);
int grade(int);
int game_menuPrint(void);

//About CRUD
void Login(void);
void SignUp(void);
void deleteUser(void);
void modifyUser(void);
void showChart(void);
void setNode(FILE *);



char board[height][width];

User* head = NULL;
User* last = NULL;

int main() {
    int n = 0;
    FILE *fp = fileRead();
    setNode(fp);

    while(n != 5) {
        menuPrint();
        scanf("%d", &n);
        getchar();
        switch (n){
            case 1:

                //Login();
                printf("LOGIN\n");
                break;

            case 2:

                setBoard();
                makeBoard();
                //startGame();

                break;

            case 3:

                //SignUp();
                printf("3!\n");

                break;

            case 4:
                //showChart();
                printf("4!\n");
                break;


            case 5:

                
                system("clear");
                printf("프로그램을 종료합니다.");
                getchar();
                system("clear");
                //fileSave(fp);
                exit(0);
                
                break;

            default:
                break;

    
        }

        //system("clear");

    }
        




    return 0;
}

FILE *fileRead() {
    FILE *f;
    f = fopen("USERDATA.txt", "r");
    if(f == NULL) {
        printf("ERROR: 파일을 열 수 없습니다!\n");
        exit(0);

    }
    else return f;
}

void menuPrint(){


    //system("clear");

    printf("                           ======사목게임======\n\n");

    printf("         <<로그인 없이도 플레이 가능!(점수는 기록되지 않아요ㅠ)>>\n\n");
    
    printf("1. 로그인\n");
    
    printf("2. 게임 시작\n");
    
    printf("3. 회원가입\n");
    
    printf("4. 순위\n");
    
    printf("5. 게임 종료\n");
    
    printf(":");

}

void setBoard() {

    for(int i = 0;i<height;i++){

        for(int k = 0;k<width;k++){

            board[i][k] = '_';

        }

    }

}

void makeBoard() {

    system("clear");

    printf("                        ");

    for(int i = 1;i<8;i++){
        
        printf("  %d ", i);

    }

    printf("\n");

    for(int i = 0;i<height;i++){

        printf("                        ");

        for(int k = 0;k<width;k++){

            printf("|_%c_",board[i][k]);

        }

        printf("|\n");

    }

}

void setNode(FILE *fp) {
	
	User *tmpNode = NULL;
	while(1) {
		User tmp;
		fscanf(fp, "%s %s %s %d %d",tmp.Name, tmp.ID, tmp.Password, &tmp.WIN, &tmp.LOSE);
		if(feof(fp) != 0)
			break;
		tmpNode = (User *)malloc(sizeof(User));
		tmpNode->next = NULL;
		strcpy(tmpNode->Name,tmp.Name);
		strcpy(tmpNode->ID,tmp.ID);
		strcpy(tmpNode->Password,tmp.Password);
        tmpNode->WIN = tmp.WIN;
        tmpNode->LOSE = tmp.LOSE;
			if(head == NULL) 
				head = tmpNode;
			else {
				User *New = head;
				while(New->next != NULL) {
					New = New->next;
				}
				New->next = tmpNode;
			}
	}
	fclose(fp);

}