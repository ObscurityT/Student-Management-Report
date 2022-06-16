#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>

class Student {

private:
	std::string Name;
	std::string Grade{ "ABCDF" };
	int RollNumber;
	float M_PE, M_Math, M_History, M_Science, M_English;
	float fAverage;
	

public: 

void InputData();
void AverageNote();
void GradeResult();
void GetStudentData();
void StudentData(std::string S_Name, std::string S_Grade,  int S_RollNum, float S_Average);
};



int main()
{


	Student estudante;

	std::vector<Student> StudentList;

	estudante.InputData();
	estudante.AverageNote();
	estudante.GradeResult();

	return 0;
}

void Student::InputData()
{
	std::cout << "Student's Name: " << "\n";
	std::cin >> Name;
	std::cout << "\n" << "Roll Number:" << "\n";
	std::cin >> RollNumber;
	std::cout <<"\nPE mark:" << "\n";
	std::cin >> M_PE;
	std::cout << "Math marks:" << "\n";
	std::cin >> M_Math;
	std::cout << "History marks:" << "\n";
	std::cin >> M_History;
	std::cout << "Science marks" << "\n";
	std::cin >> M_Science;
	std::cout << "English marks" << "\n";
	std::cin >> M_English;
}

void Student::AverageNote()
{
	fAverage = (M_Math + M_PE + M_English + M_History + M_Science) / 5; 
	std::cout << "The average is: "<< std::setprecision(3) << fAverage << ". ";
	
}

void Student::GradeResult()
{
	if (fAverage >= 90)
	{
		std::cout << "Student's grade is: " << Grade[0];
	}
	else if ((fAverage >= 80) && (fAverage < 90))
	{
		std::cout << "Student's grade is: " << Grade[1];
	}
	else if ((fAverage >= 70) && (fAverage < 79))
	{
		std::cout << "Student's grade is: " << Grade[2];
	}
	else if ((fAverage >= 60) && (fAverage < 69))
	{
		std::cout << "Student's grade is: " << Grade[3];
	}
	else if ((fAverage >= 0) && (fAverage < 59))
	{
		std::cout << "Student's grade is: " << Grade[4];
	}

}

void Student::GetStudentData()
{
	void InputData();
	void AverageNote();
	void GradeResult();
	void StudentData();
}

void Student::StudentData(std::string S_Name, std::string S_Grade, int S_RollNum, float S_Average)
{

	S_Name  = Name;
	S_Grade = Grade;
	S_RollNum = RollNumber;
	S_Average = fAverage;

}