#pragma once

#include <vector>
#include <string>


//classes
class Student {

public:

	//Constructor
	Student(std::string Name, int RollNumber, float fGrade) {}
	Student(); // definir no cpp

	void InputData(const Student& student);
	void ModifyName(std::string& newName);
	void ModifyGrade(int SubjectChoice, int& NewGrade);
	void SearchStudent(std::vector<Student>& studentList);
	void AverageNote();
	void GradeResult() const;
	void PrintSubjects();
	void PrintData();
	int GetRollNumber();
	

private:

	std::string Name;
	char Grade[5]{ 'A','B','C','D','F'};
	int RollNumber{0};
	float M_PE{0.f}, M_Math{0.f}, M_History{0.f}, M_Science{0.f}, M_English{0.f};
	float fGrade{0.f};

};


//functions
void Start(std::vector<Student>& studentList);
void EditStudent(std::vector<Student>& studentList);
char YesOrNoQuestion(const std::string& Question);