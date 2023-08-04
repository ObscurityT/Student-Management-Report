#pragma once

#include <vector>
#include <string>

//global variables
char gAnswer;
int SearchID;
int choice;

//classes
class Student {

public:

	//Constructor
	Student();

	Student(std::string Name, int RollNumber, float fGrade) {}

	void InputData();
	void ModifyName(const std::string& newName);
	void ModifyGrade(int SubjectChoice, int NewGrade);
	void AverageNote();
	void GradeResult() const;
	void PrintSubjects();
	void PrintData();
	int GetRollNumber();
	

private:
	std::string Name;
	char Grade[5]{ 'A','B','C','D','F'};
	int RollNumber;
	float M_PE, M_Math, M_History, M_Science, M_English;
	float fGrade;

};

class Student;

//functions
void Start(std::vector<Student>& studentList);
void SearchStudent(std::vector<Student>& studentList);
void EditStudent(std::vector<Student>& studentList);
char YesorNoQuestion(const std::string& Question);