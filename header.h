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

STUDENT* create_student(TOTAL* r, int student_id, ENROLL* new_infos);				// �л� �����
STUDENT* search_student(TOTAL* r, STUDENT* n, int student_id);	// �л� ã��

void insert_node(TOTAL* r, int student_id, ENROLL* new_infos);						// �л� �߰��ϱ�
void delete_node(TOTAL* r, int student_id);						// �л� �����ϱ�

int get_point(char grade);										// ����->����

int get_total_students(TOTAL* r, STUDENT* n);					// �� �л� �� ã��
float get_total_GPA(TOTAL* r, STUDENT* n);						// �� GPA ã��

void print_rb_info(TOTAL* r, STUDENT* n);						// rb-tree ���� ���
void print_student_info(TOTAL* r, STUDENT* n);					// �л� ���� ���





/* ============================================ level 2. submodules ============================================ */

is_valid_course();	// ��ȿ�� �������� Ȯ�� 
is_valid_grade();	// ��ȿ�� �������� Ȯ�� 


get_GPA();					// GPA ��� ���ϱ�
get_complete_credits();		// �� ���� ���� ���ϱ�

check_enroll_count();		//3~7���� �����ϴ��� Ȯ��
search_semester();			// �ش� �б� ���������� �̹� �����ϴ��� �˻�
take_already();			// Ư�� �б⿡ ������ �������� �˻�

insert_enroll();
// is_valid_course() ��ȿ�� �������� �˻�
// is_valid_grade() ��ȿ�� �������� �˻�
// take_already() �̹� �����ߴ� �������� ó�� ��� �������� �˻�
// �����ߴ� �����̸� ������ �����ؼ� ��ȯ
// �Է¹��� ������� enroll ���� ��ȯ

insert_semester();
// search_semester(); �ش� �б� �����ϴ��� �ƴ��� �˻�
// ���� �� �ϸ� ���� �����
// �����ϸ� ������ ��ġ ã��
// �Է¹��� ������� insert_enroll() ȣ���ؼ� enroll�� ����� 
// check_enroll_count() enroll�� ���� �˻�
// �����ϸ� �� �ڿ� �߰�

insert_student();
// search_student() �й� �˻����� �����ϴ� �л����� �ƴ��� �˻�
// ���� �� �ϸ� ���� �����
// �����ϸ� ��� ã��
// insert_semesters ȣ��
// GPA ���
// �� ���� ���� ���
// �л� ���� ���

delete_student();
// search_student() �й� �˻����� �����ϴ� �л����� �ƴ��� �˻�
// �ش� �л��� ���� ���
// �ش� �л� ����

delete_student_info();
// search_student() �й� �˻����� �����ϴ� �л����� �ƴ��� �˻�
// take_already() ��� �б⿡ ���� �����ϴ� �������� �˻�
// check_enroll_count() �ش� ������ �����ص� �б� ���� �� 3 �̻����� �˻�
// ���� ����
// �ش� �л� ���� ���

// search_student() �й� �˻����� �����ϴ� �л����� �ƴ��� �˻�




/* ============================================ level 3. user interface ============================================ */
//1. �˻�

//2. ����

//3. ����