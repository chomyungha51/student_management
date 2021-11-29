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