#include "make.h"

extern char kname[2][10]; // String for grading
// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){
	/*파라미터: 내가 신청한 과목코드 배열 ,신청한 과목 개수, 교과목 목록 구조체포인터 배열, 교과목 목록 과목 개수*/
	/*리턴값: 변경된 내 수강과목 개수*/
	/*하는 일: 과목코드를 입력받아 내 수강신청 과목을 추가로 등록하는 과정을 반복하다가 끝나면 최종 등록된 내 수강과목의 개수를 리턴한다.*/
	/*반드시 과목코드가 중복되는 경우, 과목코드가 존재하지 않는 경우를 검사해야 한다.*/
	int code, i, j;
	int addmore = 1;
	while(addmore==1){
		printf(">> Enter a class code > ");
		scanf("%d", &code);
		int found = 0;
		for(i=0; i<csize; i++){
			if(c[i]->code == code){ // 과목코드가 존재하는 경우
				found = 1;
				break;
			}
		}
		if(!found){ // 과목코드가 존재하지 않는 경우
			printf(">> No such code of class.\n");
			continue;
		}
		int duplicate = 0;
		for(j=0; j<msize; j++){
			if(my[j] == code){ // 과목코드가 중복되는 경우
				duplicate = 1;
				break;
			}
		}
		if(duplicate){ 
			printf(">> Already applied this class.\n");
			continue;
		}
		my[msize] = code;
		msize++;
		printf(">> Applied [%d] %s.\n", c[i]->code, c[i]->name);
		printf(">> Add more? (1:Yes 2:No) > ");
		scanf("%d", &addmore);
		if(addmore != 1 && addmore != 2){
			printf(">> [invalid input] Add more? (1:Yes 2:No) > ");
			scanf("%d", &addmore);
		}
	}
	return msize;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){
	/*파라미터: 내가 신청한 과목코드 배열, 내가 신청한 과목 개수, 교과목 목록 구조체포인터 배열, 교과목 목록 과목 개수*/
	/*리턴값: 없음*/
	/*하는 일: 내가 수강신청한 과목의 모든 정보를 출력한다.*/

	int i, j, total_credits = 0;
	for(i=0; i<msize; i++){
		for(j=0; j<csize; j++){
			if(c[j]->code == my[i]){
				printf("%d. [%d] %s [credit %d - %s]\n", i+1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
				total_credits += c[j]->unit;
				break;
			}
		}
	}
	printf("All : %d classes, Total Credits: %d\n", msize, total_credits);
	return;
}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){
	/*파라미터: 내가 신청한 과목코드 배열, 내가 신청한 과목 개수, 교과목 목록 구조체포인터 배열, 교과목 목록 과목 개수*/
	/*리턴값: 없음*/
	/*하는 일: 내가 수강신청한 과목의 모든 정보를 my_classes.txt 파일에 저장한다.*/
	/*파일에 포함해야 하는 내용: 내가 신청한 수강 과목 목록 (과목코드, 과목명, 학점수, 평가방식), 총 수강학점, 평가방식별 수강학점, 수강과목수 등*/
	/*파일 예시:
		My Classes
		1. [101] C++ [credit 3 - A+~F]
		2. [110] Reading [credit 1 - P/F]
		3. [201] EngineeringBasic [credit 3 - A+~F]
		4. [205] Java [credit 3 - A+~F]
		5. [208] Project [credit 3 - P/F]
		6. [204] ProgramingStudio [credit 2 - A+~F]
		All : 6 classes, 15 credits (A+~F 11 credits, P/F 4 credits)
	*/
	FILE* fp = fopen("my_classes.txt", "w");
	if(fp == NULL){
		printf("> Failed to save my classes.\n");
		return;
	}
	int i, j, total_credits = 0, grade_credits[2] = {0, 0};
	fprintf(fp, "My Classes\n");
	for(i=0; i<msize; i++){
		for(j=0; j<csize; j++){
			if(c[j]->code == my[i]){
				fprintf(fp, "%d. [%d] %s [credit %d - %s]\n", i+1, c[j]->code, c[j]->name, c[j]->unit, kname[c[j]->grading-1]);
				total_credits += c[j]->unit;
				grade_credits[c[j]->grading]++;
				break;
			}
		}
	}
	fprintf(fp, "All : %d classes, %d credits (%s %d credits, %s %d credits)\n", msize, total_credits, kname[0], grade_credits[0], kname[1], grade_credits[1]);
	fclose(fp);
	return;
}