#include "studentreport.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<string>


int main()
{

	std::vector<Student> StudentList;
	Start(StudentList);

	return 0;
}

Student::Student() {}

void Student::InputData()
{
	//Get Student's Name
	std::cout << "Student's Name: " << "\n";
	std::getline(std::cin, Name);
	
	
	//Get Student's Roll Number
	std::cout << "\n" << "Roll Number:" << "\n";
	std::cin >> RollNumber;

	//Get Student's marks
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
	
	AverageNote();
	GradeResult();
	//system("cls");
}

void Student::AverageNote()
{
	fGrade = (M_Math + M_PE + M_English + M_History + M_Science) / 5.0f; 
	std::cout << "The average is: "<< std::setprecision(3) << fGrade << ".\n";
	
}

void Student::GradeResult() const
{
	if (fGrade >= 90)
	{
		std::cout << "Student's grade is: " << Grade[0] << "\n";
	}
	else if (fGrade >= 80)
	{
		std::cout << "Student's grade is: " << Grade[1] << "\n";
	}
	else if (fGrade >= 70) 
	{
		std::cout << "Student's grade is: " << Grade[2] << "\n";
	}
	else if (fGrade >= 60)
	{
		std::cout << "Student's grade is: " << Grade[3] << "\n";
	}
	else 
	{
		std::cout << "Student's grade is: " << Grade[4] << "\n";
	}

}

void Student::PrintData() 
{
	std::cout << "Name: " << Name << "\n";
	std::cout << "Roll Number: " << RollNumber << "\n";
	AverageNote();
	GradeResult();

}

void Student::PrintSubjects()
{
	std::cout << "PE: " << M_PE << "\n";
	std::cout << "Math: " << M_Math << "\n";
	std::cout << "History: " << M_History << "\n";
	std::cout << "Science: " << M_Science << "\n";
	std::cout << "English: " << M_English << "\n";
}

int Student::GetRollNumber()
{
	return RollNumber;
}

void Student::ModifyName(const std::string& newName)
{
	Name = newName;
}

void Student::ModifyGrade(int SubjectChoice, int NewGrade)
{
	switch (SubjectChoice)
	{

	case 1:
		M_PE = NewGrade;
		break;
	case 2:
		M_Math = NewGrade;
		break;
	case 3:
		M_History = NewGrade;
		break;
	case 4:
		M_Science = NewGrade;
		break;
	case 5: 
		M_English = NewGrade;
		break;
	}
}

char YesorNoQuestion(const std::string& Question)
{
	do
	{
		std::cout << Question;
		std::cin >> gAnswer;
		gAnswer = std::toupper(gAnswer);

		if (gAnswer != 'Y' && gAnswer != 'N')
		{
			std::cout << "Please input Y/N\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	} while (gAnswer != 'Y' && gAnswer != 'N');

	return gAnswer;
}

void Start(std::vector<Student>& studentList)
{

	bool Addmore = true;
		
	do {
		std::cout << "1.Add a new student " << "\n2.Search for student" << "\n3.Edit Student" << "\n4.Exit Program";
		std::cout << "\n\nPlease select a number: " << "\n";
		std::cin >> choice; // lembrar de limitar a resposta para 1/2/3

		Student student;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (choice == 1)
		{
			do
			{
				student.InputData();
				studentList.push_back(student);

				YesorNoQuestion("Add a new student?");
				

			} while (gAnswer == 'Y');
		}
		else if (choice == 2)
		{
			do
			{
				SearchStudent(studentList);
				YesorNoQuestion("Search for another student?");

				// E se eu colocar o Edit Student depois do search para ter opções de modificar o aluno
			} while (gAnswer == 'Y');
		}
		else if (choice == 3)
		{
			do
			{
				EditStudent(studentList);

				YesorNoQuestion("Edit another student?");

			} while (gAnswer == 'Y');	
		}
		else if (choice == 4)
		{
			Addmore = false;
		}
		else
		{
			std::cout << "Invalid choice. Please Enter a valid number\n";
			
		}
	} while (Addmore == true);
}


void SearchStudent(std::vector<Student>& studentList)
{
	std::cout << "Please enter the student's ID: " << std::endl;
	std::cin >> SearchID;

	for (auto& s : studentList)
	{
		if (SearchID == s.GetRollNumber())
		{
			s.PrintData();
		}
	}
}


void EditStudent(std::vector<Student>& studentList)
{
	int rollNum;
	int Subjectchoice;
	bool found = false;

	std::cout << "Please enter the the Roll Number of the student you want to modify " << "\n";
	std::cin >> rollNum;

	for (auto& s : studentList)
	{
		if (s.GetRollNumber() == rollNum)
		{
			s.PrintData();
			//s.PrintSubjects();
			std::cout << "\nPlease choose the option to be modified:" << "\n";
			std::cout << "1.Name " << "\n2.Subject Grade" << "\n3.Exit Program" << "\n";
			std::cin >> choice;

			if (choice == 1)
			{
				std::string NewName;
				std::cout << "\nPlease enter the new name (or type 'exit' to cancel):" << "\n";
				std::cin >> NewName;

				if (NewName == "exit")
				{
					std::cout << "Name change canceled.";
					break;
				}

				std::cout << "Confirm " << NewName <<" ?" << "\n";
				std::cin >> gAnswer;
				
				if (gAnswer == 'Y')
				{
					s.ModifyName(NewName);
					s.PrintData();
					break;

				}
			}
			if (choice == 2)
			{
				int NewGrade;
				s.PrintSubjects();
				std::cout << "\nPlease select the subject grade to be modified: " << "\n";
				std::cout << "1.PE" << "\n2.Math" << "\n3.History" << "\n4.Science" <<"\n5.English" << "\n";
				std::cin >> Subjectchoice;

				std::cout << "Please enter the new grade: ";
				std::cin >> NewGrade;
					
				s.ModifyGrade(Subjectchoice, NewGrade);
				s.PrintSubjects();
			}
			if (choice == 3)
			{
			break;
			}
		}
	}
}