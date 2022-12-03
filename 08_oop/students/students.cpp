#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool CompareStudentsGrades(pair<int, int> a, pair<int, int> b)
{
	if (a.first >= b.first) {
		return true;
	}

	return false;
}


class Student {
private:
	string name;
	int grade = 0;

public:
	Student(string name) {
		this->name = name;
	}

	Student() {
		this->name = "";
		this->grade = 0;
	}

	string getName() {
		return this->name;
	}

	int getGrade() {
		return this->grade;
	}

	void setGrade(int grade) {
		this->grade = grade;
	}
};

class StudentList {
private:
	vector<Student*> studentList;

	vector<Student*> getStudentsFromPairByIndex(vector<Student*> studentList, vector<pair<int, int>> gradeByIndex) {
		vector<Student*> bottomGradeStudents;

		for (auto i : gradeByIndex)
		{
			bottomGradeStudents.push_back(studentList.at(i.second));
		}

		return bottomGradeStudents;
	}

public:
	StudentList() {
	}

	void addStudent(Student* student) {
		studentList.push_back(student);
	}


	void removeStudent(const Student* student) {
		studentList.erase(remove(studentList.begin(), studentList.end(), student), studentList.end());
	}


	void setGrade(Student* student, int grade) {
		auto it = find(studentList.begin(), studentList.end(), student);
		int index = it - studentList.begin();

		Student* targetStudent = studentList.at(index);
		targetStudent->setGrade(grade);
	}


	double getStudentsAverageGrade() {
		int total = 0;

		for (auto& student : studentList) {
			total += student->getGrade();
		}

		return total / studentList.size();
	}


	vector<Student*> getTopStudents() {
		vector<pair<int, int>> topStudentsGradeByIndex;

		for (int i = 0; i < studentList.size() > 5 ? 5 : studentList.size(); ++i) {
			if (studentList[i]->getGrade() < 4) {
				continue;
			}
			topStudentsGradeByIndex.push_back({ studentList[i]->getGrade(), i });
		}

		sort(topStudentsGradeByIndex.begin(), topStudentsGradeByIndex.end(), CompareStudentsGrades);

		return getStudentsFromPairByIndex(studentList, topStudentsGradeByIndex);
	}

	vector<Student*> getBottomStudents() {
		vector<pair<int, int>> bottomStudentsGradeByIndex;

		for (int i = 0; i < studentList.size() > 5 ? 5 : studentList.size(); ++i) {
			if (studentList[i]->getGrade() > 3) {
				continue;
			}
			bottomStudentsGradeByIndex.push_back({ studentList[i]->getGrade(), i });
		}

		sort(bottomStudentsGradeByIndex.begin(), bottomStudentsGradeByIndex.end(), CompareStudentsGrades);

		return getStudentsFromPairByIndex(studentList, bottomStudentsGradeByIndex);
	}


	string printStudents() {
		return printStudents(studentList);
	}


	string printStudents(vector<Student*> studentList) {
		string studentsData = "";

		for (auto& student : studentList) {
			studentsData += ("Name: " + student->getName() + " | Grade: " + to_string(student->getGrade()) + "\n");
		}

		return studentsData;
	}
};

int main()
{
	StudentList studentList = StudentList();

	Student semenov = Student("Yuri Semenov");
	studentList.addStudent(&semenov);
	studentList.setGrade(&semenov, 5);

	Student tsal = Student("Vitaly Tsal");
	studentList.addStudent(&tsal);
	studentList.setGrade(&tsal, 3);

	//cout << semenov.getGrade();
	//cout << tsal.getGrade();

	//cout << studentList.getStudentsAverageGrade();

	cout << studentList.printStudents() << endl;
	cout << studentList.printStudents(studentList.getTopStudents()) << endl;
	cout << studentList.printStudents(studentList.getBottomStudents()) << endl;

	return 0;

	//studentList.removeStudent(&semenov);
	//studentList.removeStudent(&tsal);
}
