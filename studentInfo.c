#include <stdio.h>
#include <stdlib.h>
#include "header.h"

COURSE* addCOURSE(char* course_id, char grade, int credit_hour, char* semeseter) {
	COURSE* newCourse = (COURSE*)malloc(sizeof(COURSE));
	newCourse->semester = semeseter;
	newCourse->course_id = course_id;
	newCourse->credit = credit_hour;
	newCourse->grade= grade;
	if (grade == 'A') {
		newCourse->point = 4;
	}
	else if (grade == 'B') {
		newCourse->point = 3;
	}
	else if (grade == 'C') {
		newCourse->point = 2;
	}
	else if (grade == 'D') {
		newCourse->point = 1;
	}
	else {
		newCourse->point = 0;
	}
	newCourse->next = NULL;
	return newCourse;
}





//2. 추가

//학번, 학수번호, 성적, 학점, 년도, 학기

//년도-학기
////학수번호, 성적, 학점
//총 학점 평균, 졸업까지 남은 학점
//총 학생 수, 총 학생 학점 평균

// 3. 삭제

//학번

//모든 정보 삭제
//삭제한 정보 출력
//전체 시스템에 있는 총 학생 수와 총 학점평균 출력
// RB 삽입과 삭제 관련 정보도 출력

// 학번, 학수번호

// 이 과목 정보만 삭제
//삭제한 정보 출력
//전체 시스템에 있는 총 학생 수와 총 학점평균 출력
// RB 삽입과 삭제 관련 정보도 출력

