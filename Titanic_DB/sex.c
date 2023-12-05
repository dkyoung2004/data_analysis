#include <iostream>
#include <cstring>

struct STUDENT
{
    char name[20];
    float midterm;
    float final;
    float lab;
    float total;
    struct STUDENT *next;
};

void printTotalScores(struct STUDENT *head)
{
    struct STUDENT *current = head;
    while (current != NULL)
    {
        current->total = current->midterm * 0.3 + current->final * 0.4 + current->lab * 0.3;
        std::cout << "Total score for " << current->name << ": " << current->total << std::endl;
        current = current->next;
    }
}

void printAverages(struct STUDENT *head, int count)
{
    float midtermSum = 0, finalSum = 0, labSum = 0;
    struct STUDENT *current = head;
    while (current != NULL)
    {
        midtermSum += current->midterm;
        finalSum += current->final;
        labSum += current->lab;
        current = current->next;
    }
    std::cout << "Midterm average: " << midtermSum / count << std::endl;
    std::cout << "Final average: " << finalSum / count << std::endl;
    std::cout << "Lab average: " << labSum / count << std::endl;
}

void printStudentScores(struct STUDENT *head, const char *studentName)
{
    struct STUDENT *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, studentName) == 0)
        {
            std::cout << "Midterm score for " << studentName << ": " << current->midterm << std::endl;
            std::cout << "Final score for " << studentName << ": " << current->final << std::endl;
            std::cout << "Lab score for " << studentName << ": " << current->lab << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Student with name " << studentName << " not found." << std::endl;
}

int main()
{
    struct STUDENT *head = NULL;
    struct STUDENT *temp = NULL;

    const char *names[10] = {"aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii", "jjj"};
    float midterms[10] = {10, 20, 30, 40, 50, 60, 50, 40, 30, 20};
    float finals[10] = {10, 20, 30, 40, 50, 60, 50, 40, 30, 20};
    float labs[10] = {40, 50, 60, 70, 80, 90, 80, 70, 60, 50};

    for (int i = 0; i < 10; ++i)
    {
        temp = new STUDENT();
        strcpy(temp->name, names[i]);
        temp->midterm = midterms[i];
        temp->final = finals[i];
        temp->lab = labs[i];
        temp->next = head;
        head = temp;
    }

    printTotalScores(head);
    printAverages(head, 10);
    printStudentScores(head, "hhh");

    return 0;
}