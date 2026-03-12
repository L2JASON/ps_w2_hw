#include "make.h"

extern char kname[2][10]; // String for grading
// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){
	/*파라미터: 내가 신청한 과목코드 배열 ,신청한 과목 개수, 교과목 목록 구조체포인터 배열, 교과목 목록 과목 개수*/
	/*리턴값: 변경된 내 수강과목 개수*/
	/*하는 일: 과목코드를 입력받아 내 수강신청 과목을 추가로 등록하는 과정을 반복하다가 끝나면 최종 등록된 내 수강과목의 개수를 리턴한다.*/
	/*반드시 과목코드가 중복되는 경우, 과목코드가 존재하지 않는 경우를 검사해야 한다.*/
	int code, i, j;
	while(1){
		printf(">> Enter a code of class to apply (0 to finish) > ");
		scanf("%d", &code);
		if(code == 0) break; // 신청 종료
		int found = 0;
		for(i=0; i<csize; i++){
			if(c[i]->code == code){ // 과목코드가 존재하는 경우
				found = 1;
				break;
			}
		}
		if(!found){ // 과목코드가 존재하지 않는 경우
			printf("> Class not exist.\n");
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
			printf("> Already applied this class.\n");
			continue;
		}
		my[msize] = code;
		msize++;
		printf("> Applied [%d] %s.\n", c[i]->code, c[i]->name);
	}
	return msize;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){


	

}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){



	
}