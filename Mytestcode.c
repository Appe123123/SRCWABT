#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define height 6
#define width 7

/*
Request
1. USER2
2. 마지막 유저 읽지 못함
3. 게임기능 결합
4. 승률 순으로 정렬 기능 구현

*/
typedef struct User{
    char Name[30];
    char ID[16];
    char Password[16];
    int WIN;
    int LOSE;

    struct User *next;
}User;

typedef struct status{
    int log;
    User user_now;
}status;

status STATUS;

FILE* fileRead(void);
void fileSave(void);

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


//temporary func

void printName();


char board[height][width];

User *head = NULL;
User *last = NULL;

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

                Login();
                
                break;

            case 2:

                setBoard();
                makeBoard();
                //startGame();

                break;

            case 3:

                SignUp();

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
                fileSave();
                exit(0);
                
                break;

            case 6:
                printName();
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

    printf("\n\n                           ======사목게임======\n\n");

    printf("         <<로그인 없이도 플레이 가능!(점수는 기록되지 않아요ㅠ)>>\n\n");
    
    printf("1. 로그인\n");
    
    printf("2. 게임 시작\n");
    
    printf("3. 회원가입\n");
    
    printf("4. 순위\n");
    
    printf("5. 게임 종료\n");
    
    printf(":");

}

void setBoard() {

    for(int i = 0; i<height; i++){

        for(int k = 0; k<width; k++){

            board[i][k] = '_';

        }

    }

}

void makeBoard() {

    system("clear");

    printf("                        ");

    for(int i = 1; i<8; i++){
        
        printf("  %d ", i);

    }

    printf("\n");

    for(int i = 0;i<height;i++){

        printf("                        ");

        for(int k = 0; k < width; k++){

            printf("|_%c_",board[i][k]);

        }

        printf("|\n");

    }

}

void setNode(FILE *fp) {
	int t = 1;
	User *tmpNode = NULL;
	while(1) {
		User tmp;
		fscanf(fp, "%s %s %s %d %d",tmp.Name, tmp.ID, tmp.Password, &tmp.WIN, &tmp.LOSE);
		if(feof(fp) != 0)
			break;
        printf("Reading Data %d\n", t++);
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

void fileSave(void) {
    FILE *fp = fopen("USERDATA.txt", "w");
    if (head != NULL) {
        while(1) {
            User *aa = head;
            fprintf(fp, "%s %s %s %d %d\n", aa->Name, aa->ID, aa->Password, aa->WIN, aa->LOSE);
            if(head->next == NULL)
                break;
            head = head->next;
        }
    }
}

void Login(void) {
    char s_id[16];
    char s_pswd[16];
    int check_id;
    int check_pswd;

    printf("|ID| ");
    scanf("%s", s_id);
    getchar();
    printf("|PASSWORD| ");
    scanf("%s", s_pswd);

    User *temp = head;
    while(temp->next != NULL) {
        check_id = strcmp(s_id, temp->ID);
        check_pswd = strcmp(s_pswd, temp->Password);
        if(check_id == 0 && check_pswd == 0) {
            printf("로그인 되었습니다.\n");
            STATUS.log = 1;
            STATUS.user_now = *temp;
            return;
        }
        temp = temp->next;
    }
    printf("아이디와 비밀번호가 일치하지 않습니다.\n");
}

void SignUp(void) {
    char s_name[10];
    char s_id[16];
    char s_pswd[16];
    User *temp = head;
    printf("|이름| ");
    scanf(" %s", s_name);
    printf("|ID| ");
    scanf(" %s", s_id);
    while(temp->next != NULL) {
        if(strcmp(temp->ID,s_id) == 0) {
            printf("이미 존재하는 ID입니다!");
            return;
        }
        temp = temp->next;
    }

    printf("|PassWord| ");
    scanf(" %s", s_pswd);

    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    User *New = NULL;
    New = (User *)malloc(sizeof(User));
    strcpy(New->Name, s_name);
    strcpy(New->ID, s_id);
    strcpy(New->Password, s_pswd);
    New->WIN = 0;
    New->LOSE = 0;
    New -> next = NULL;

    temp->next = New;


}

void printName() {
    int i = 1;
    User *temp = head;
    while(temp->next != NULL) {
        printf("| %d | %s \n", i++, temp->Name);
        
        temp = temp->next;
    }
    if(temp->next == NULL) {
            printf("NULL!\n");
        }
}