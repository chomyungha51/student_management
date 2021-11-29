#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1 
#define _CRT_SECURE_NO_WARNINGS

/*============================================ level 1. data structures and primitive functions ============================================*/

// 과목 정보

typedef struct course {
	char* course_id;
	int credit;
}COURSE;


COURSE total_courses[100];

is_valid_course();	// 유효한 과목인지 확인 

typedef struct enroll {
	char* course_id;
	char grade;
	int credit;
}ENROLL;

is_valid_grade();	// 유효한 성적인지 확인 

typedef struct semester {
	char* semeseter_info;
	ENROLL* courses;
}SEMESTER;

check_enroll_count();		//3~7과목만 수강하는지 확인

// 학생 정보
typedef struct student {
	struct student* p;
	struct student* left;
	struct student* right;
	int color;

	char* student_id;
	float myGPA;
	int complete_credits;
	SEMESTER* registered;
}STUDENT;

get_GPA();					// GPA 평균 구하기
get_complete_credits();		// 총 수강 학점 구하기

search_semester();			// 해당 학기 수강정보가 이미 존재하는지 검사
take_already();			// 특정 학기에 수강한 과목인지 검사

typedef struct total_students {
	STUDENT* r;
	STUDENT* nil;
}TOTAL;

get_total_GPA();		// 전체 평점 평균 구하기
get_total_students();	// 전체 학생 수 구하기
search_student();	// 존재하는 학생인지 구하기





/* ============================================ level 2. submodules ============================================ */

// insert_enroll()
// is_valid_course() 유효한 과목인지 검사
// is_valid_grade() 유효한 성적인지 검사
// take_already() 이미 수강했던 과목인지 처음 듣는 과목인지 검사
// 수강했던 과목이면 정보만 수정해서 반환
// 입력받은 정보들로 enroll 만들어서 반환

// insert_semesters
// search_semester(); 해당 학기 존재하는지 아닌지 검사
// 존재 안 하면 새로 만들기
// 존재하면 적절한 위치 찾기
// 입력받은 정보들로 insert_enroll() 호출해서 enroll들 만들기 
// check_enroll_count() enroll들 개수 검사
// 적절하면 맨 뒤에 추가

// insert new student
// search_student() 학번 검색으로 존재하는 학생인지 아닌지 검사
// 존재 안 하면 새로 만들기
// 존재하면 노드 찾기
// insert_semesters 호출
// GPA 계산
// 총 수강 학점 계산
// 학생 정보 출력

// delete a student
// search_student() 학번 검색으로 존재하는 학생인지 아닌지 검사
// 해당 학생의 정보 출력
// 해당 학생 삭제

// delete a student info
// search_student() 학번 검색으로 존재하는 학생인지 아닌지 검사
// take_already() 모든 학기에 대해 수강하는 과목인지 검사
// check_enroll_count() 해당 과목을 삭제해도 학기 과목 수 3 이상인지 검사
// 과목 삭제
// 해당 학생 정보 출력

// print a student info
// search_student() 학번 검색으로 존재하는 학생인지 아닌지 검사
// 해당 학생 정보 출력
// 학기별 수강한 과목명, 성적, 과목의 시수
// 내 gpa, 졸업까지 남은 학점 출력
// 전체 학생 수, 전체 학생 학점 평균 출력




/* ============================================ level 3. user interface ============================================ */