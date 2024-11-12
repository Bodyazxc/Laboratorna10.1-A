#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "�����������", "���������������", "����'������ �����", "����'������ ��������", "��������� ������������" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_info;
};

void Create(Students* S, const int N);
void CountStudentsWithoutThrees(Students* S, int N, int& count);
double PercentageLowAverage(Students* S, const int N);
void Print(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ ������� ��������: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);

    int count_without_threes = 0;
    CountStudentsWithoutThrees(S, N, count_without_threes);

    cout << "ʳ������ ��������, �� ������� ��� �����: " << count_without_threes << endl;
    cout << "������� ��������, �������� ��� ���� ������ �� 4: " << setprecision(2) << PercentageLowAverage(S, N) << "%" << endl;

    delete[] S;
    return 0;
}

void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "����� ��������: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "�������: "; getline(cin, S[i].surname); cout << endl;
        cout << "����: "; cin >> S[i].course; cout << endl;
        cout << "������������� (0 - �����������, 1 - ���������������, 2 - ����'������ �����,";
        cout << "\n3 - ����'������ ��������, 4 - ��������� ������������): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "������ � ������: "; cin >> S[i].grade_physics; cout << endl;
        cout << "������ � ����������: "; cin >> S[i].grade_math; cout << endl;
        cout << "������ � �����������: "; cin >> S[i].grade_info; cout << endl;
        cout << endl;
    }
}

void CountStudentsWithoutThrees(Students* S, int N, int& count)
{
    count = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i].grade_physics > 3 && S[i].grade_math > 3 && S[i].grade_info > 3)
        {
            count++;
        }
    }
}

double PercentageLowAverage(Students* S, const int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        double average = (S[i].grade_physics + S[i].grade_math + S[i].grade_info) / 3.0;
        if (average < 4)
        {
            count++;
        }
    }
    return count * 100.0 / N;
}

void Print(Students* S, const int N)
{
    cout << "=================================================================================================" << endl;
    cout << "|  �  |   �������   |  ����  |     �������������     |  Գ����  |  ����������  |  �����������  |" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << left << i + 1 << " ";
        cout << "|" << setw(14) << left << S[i].surname;
        cout << "|" << setw(8) << left << S[i].course;
        cout << "|" << setw(23) << left << speciality_str[S[i].speciality];
        cout << "|" << setw(10) << left << S[i].grade_physics;
        cout << "|" << setw(14) << left << S[i].grade_math;
        cout << "|" << setw(15) << left << S[i].grade_info << "|" << endl;
    }
    cout << "=================================================================================================" << endl << endl;
}