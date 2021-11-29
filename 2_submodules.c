#include "header.h"

bool is_valid_course(COURSE* c) {
	COURSE t; 
	for (int i = 0; i < 100; i++) {
		t = total_courses[i];
		if (strncmp(t.course_id, c->course_id, 7) == 0) {
			return true;
		}
	}
	return false;
}
bool is_valid_grade(char g) {
	for (int i = 0; i < 5; i++) {
		if (g == valid_grade[i]) {
			return true;
		}
	}
	return false;
}

float get_GPA(SEMESTER* r) {
	float curGPA = 0;
	int curCount = 0;

}

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