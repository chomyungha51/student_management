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





//2. �߰�

//�й�, �м���ȣ, ����, ����, �⵵, �б�

//�⵵-�б�
////�м���ȣ, ����, ����
//�� ���� ���, �������� ���� ����
//�� �л� ��, �� �л� ���� ���

// 3. ����

//�й�

//��� ���� ����
//������ ���� ���
//��ü �ý��ۿ� �ִ� �� �л� ���� �� ������� ���
// RB ���԰� ���� ���� ������ ���

// �й�, �м���ȣ

// �� ���� ������ ����
//������ ���� ���
//��ü �ý��ۿ� �ִ� �� �л� ���� �� ������� ���
// RB ���԰� ���� ���� ������ ���

