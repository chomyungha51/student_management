#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define BLACK 1 
#define _CRT_SECURE_NO_WARNINGS

/*============================================ level 1. data structures and primitive functions ============================================*/

// ���� ����

typedef struct course {
	char* course_id;
	int credit;
}COURSE;


COURSE total_courses[100];

is_valid_course();	// ��ȿ�� �������� Ȯ�� 

typedef struct enroll {
	char* course_id;
	char grade;
	int credit;
}ENROLL;

is_valid_grade();	// ��ȿ�� �������� Ȯ�� 

typedef struct semester {
	char* semeseter_info;
	ENROLL* courses;
}SEMESTER;

check_enroll_count();		//3~7���� �����ϴ��� Ȯ��

// �л� ����
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

get_GPA();					// GPA ��� ���ϱ�
get_complete_credits();		// �� ���� ���� ���ϱ�

search_semester();			// �ش� �б� ���������� �̹� �����ϴ��� �˻�
take_already();			// Ư�� �б⿡ ������ �������� �˻�

typedef struct total_students {
	STUDENT* r;
	STUDENT* nil;
}TOTAL;

get_total_GPA();		// ��ü ���� ��� ���ϱ�
get_total_students();	// ��ü �л� �� ���ϱ�
search_student();	// �����ϴ� �л����� ���ϱ�





/* ============================================ level 2. submodules ============================================ */

// insert_enroll()
// is_valid_course() ��ȿ�� �������� �˻�
// is_valid_grade() ��ȿ�� �������� �˻�
// take_already() �̹� �����ߴ� �������� ó�� ��� �������� �˻�
// �����ߴ� �����̸� ������ �����ؼ� ��ȯ
// �Է¹��� ������� enroll ���� ��ȯ

// insert_semesters
// search_semester(); �ش� �б� �����ϴ��� �ƴ��� �˻�
// ���� �� �ϸ� ���� �����
// �����ϸ� ������ ��ġ ã��
// �Է¹��� ������� insert_enroll() ȣ���ؼ� enroll�� ����� 
// check_enroll_count() enroll�� ���� �˻�
// �����ϸ� �� �ڿ� �߰�

// insert new student
// search_student() �й� �˻����� �����ϴ� �л����� �ƴ��� �˻�
// ���� �� �ϸ� ���� �����
// �����ϸ� ��� ã��
// insert_semesters ȣ��
// GPA ���
// �� ���� ���� ���
// �л� ���� ���

// delete a student
// search_student() �й� �˻����� �����ϴ� �л����� �ƴ��� �˻�
// �ش� �л��� ���� ���
// �ش� �л� ����

// delete a student info
// search_student() �й� �˻����� �����ϴ� �л����� �ƴ��� �˻�
// take_already() ��� �б⿡ ���� �����ϴ� �������� �˻�
// check_enroll_count() �ش� ������ �����ص� �б� ���� �� 3 �̻����� �˻�
// ���� ����
// �ش� �л� ���� ���

// print a student info
// search_student() �й� �˻����� �����ϴ� �л����� �ƴ��� �˻�
// �ش� �л� ���� ���
// �б⺰ ������ �����, ����, ������ �ü�
// �� gpa, �������� ���� ���� ���
// ��ü �л� ��, ��ü �л� ���� ��� ���




/* ============================================ level 3. user interface ============================================ */