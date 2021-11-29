#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RED 0
#define BLACK 1 
#define _CRT_SECURE_NO_WARNINGS

/*============================================ level 1. data structures and primitive functions ============================================*/

typedef struct course {
	char* course_id;
	int credit;
}COURSE;

typedef struct enroll {
	char* course_id;
	char grade;
	int credit;
	struct enroll* next;
}ENROLL;

typedef struct semester {
	char* semeseter_info;
	ENROLL* courses;
	struct semester* next;
}SEMESTER;

typedef struct student {
	struct student* p;
	struct student* left;
	struct student* right;
	int color;

	int student_id;
	float myGPA;
	int complete_credits;
	SEMESTER* registered;
}STUDENT;

typedef struct total_students {
	STUDENT* r;
	STUDENT* nil;
}TOTAL;

TOTAL* r;
COURSE total_courses[100];
char valid_grade[5];

void create_nilnode(TOTAL* r);

STUDENT* create_student(TOTAL* r, int student_id, ENROLL* new_infos);				// 학생 만들기
STUDENT* search_student(TOTAL* r, STUDENT* n, int student_id);	// 학생 찾기

void insert_node(TOTAL* r, int student_id, ENROLL* new_infos);						// 학생 추가하기
void delete_node(TOTAL* r, int student_id);						// 학생 삭제하기

int get_point(char grade);										// 성적->점수

int get_total_students(TOTAL* r, STUDENT* n);					// 총 학생 수 찾기
float get_total_GPA(TOTAL* r, STUDENT* n);						// 총 GPA 찾기

void print_rb_info(TOTAL* r, STUDENT* n);						// rb-tree 정보 출력
void print_student_info(TOTAL* r, STUDENT* n);					// 학생 정보 출력





/* ============================================ level 2. submodules ============================================ */

is_valid_course();	// 유효한 과목인지 확인 
is_valid_grade();	// 유효한 성적인지 확인 


get_GPA();					// GPA 평균 구하기
get_complete_credits();		// 총 수강 학점 구하기

check_enroll_count();		//3~7과목만 수강하는지 확인
search_semester();			// 해당 학기 수강정보가 이미 존재하는지 검사
take_already();			// 특정 학기에 수강한 과목인지 검사

insert_enroll();
// is_valid_course() 유효한 과목인지 검사
// is_valid_grade() 유효한 성적인지 검사
// take_already() 이미 수강했던 과목인지 처음 듣는 과목인지 검사
// 수강했던 과목이면 정보만 수정해서 반환
// 입력받은 정보들로 enroll 만들어서 반환

insert_semester();
// search_semester(); 해당 학기 존재하는지 아닌지 검사
// 존재 안 하면 새로 만들기
// 존재하면 적절한 위치 찾기
// 입력받은 정보들로 insert_enroll() 호출해서 enroll들 만들기 
// check_enroll_count() enroll들 개수 검사
// 적절하면 맨 뒤에 추가

insert_student();
// search_student() 학번 검색으로 존재하는 학생인지 아닌지 검사
// 존재 안 하면 새로 만들기
// 존재하면 노드 찾기
// insert_semesters 호출
// GPA 계산
// 총 수강 학점 계산
// 학생 정보 출력

delete_student();
// search_student() 학번 검색으로 존재하는 학생인지 아닌지 검사
// 해당 학생의 정보 출력
// 해당 학생 삭제

delete_student_info();
// search_student() 학번 검색으로 존재하는 학생인지 아닌지 검사
// take_already() 모든 학기에 대해 수강하는 과목인지 검사
// check_enroll_count() 해당 과목을 삭제해도 학기 과목 수 3 이상인지 검사
// 과목 삭제
// 해당 학생 정보 출력

// search_student() 학번 검색으로 존재하는 학생인지 아닌지 검사




/* ============================================ level 3. user interface ============================================ */
//1. 검색

//2. 삽입

//3. 삭제