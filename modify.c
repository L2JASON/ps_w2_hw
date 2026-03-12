#include "modify.h"
// You must complete these functions.
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.

	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));

	printf(">> code number > ");
	scanf("%d", &(p->code));
	/* 과목 코드 중복 예외 처리 */
	for(int i=0; i<csize; i++){
		if(c[i]->code == p->code){
			printf("> Don't allow the duplicate class code.\n");
			return csize;
		}
	}
	printf(">> class name > ");
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}

void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;
	printf(">> Enter a code of class > ");
	scanf("%d", &code);
	/* 과목코드를 입력받은 후 수정작업을 진행하기 위해 과목구조체 포인터의 값을 할당하는 과정 */
	int found = 0;
	for(int i=0; i<csize; i++){
		if(c[i]->code == code){
			p = c[i];
			found = 1;
			break;
		}
	}
	/* 과목코드가 존재하지 않는 경우 예외 처리*/
	if(!found){
		printf("> Class not exist.\n");
		return;
	}
	printf("> Current: [%d] %s [credits %d - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("> Enter new class name > ");
	scanf("%s", p->name);
	printf("> Enter new credits > ");
	scanf("%d", &(p->unit));
	printf("> Enter new grading(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	printf("> Modified.\n");

}
