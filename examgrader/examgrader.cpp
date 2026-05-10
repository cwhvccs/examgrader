/* Program name: examgrader.cpp 
Programmer: Christopher Hicks
* Date: 5/10/26
* Requirements: Create a program that compares a student's answers to a list of correct answers.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//number of questions
const int SIZE = 20;

int main()
{
    // Arrays for correct answers and student answers
    char correctAnswers[SIZE];
    char studentAnswers[SIZE];

    // Open input files
    ifstream correctFile("CorrectAnswers.txt");
    ifstream studentFile("StudentAnswers.txt");

    // Check if CorrectAnswers.txt successfully opened
    if (!correctFile)
    {
        cout << "Error opening CorrectAnswers.txt\n";
        return 1;
    }

    // Check if StudentAnswers.txt successfully opened
    if (!studentFile)
    {
        cout << "Error opening StudentAnswers.txt\n";
        return 1;
    }

    // Read correct answers into the correctAnswers array
    for (int i = 0; i < SIZE; i++)
    {
        correctFile >> correctAnswers[i];
    }

    // Read student answers into the studentAnswers array
    for (int i = 0; i < SIZE; i++)
    {
        studentFile >> studentAnswers[i];
    }

    // Variables to count missed and correct answers
    int missed = 0;
    int correct = 0;

    cout << "Questions Missed:\n\n";

    // Compare student answers with correct answers
    for (int i = 0; i < SIZE; i++)
    {
        // If the student's answer is incorrect
        if (studentAnswers[i] != correctAnswers[i])
        {
            // Increase missed count
            missed++;

            // Display the question number,
            // correct answer, and student's answer
            cout << "Question " << (i + 1)
                << " | Correct Answer: " << correctAnswers[i]
                << " | Student Answer: " << studentAnswers[i]
                << endl;
        }
        else
        {
            // Increase correct count if answer matches
            correct++;
        }
    }

    // Calculate percentage score
    double percentage =
        (static_cast<double>(correct) / SIZE) * 100;

    // Display total number of missed questions
    cout << "\nTotal Questions Missed: "
        << missed << endl;

    // set percentage to 2 decimal places
    cout << fixed << setprecision(2);

    // Display percentage correct
    cout << "Percentage Correct: "
        << percentage << "%\n";

    // Determine if the student passed or failed
    if (percentage >= 70.0)
    {
        cout << "Result: PASS\n";
    }
    else
    {
        cout << "Result: FAIL\n";
    }

    // Close files
    correctFile.close();
    studentFile.close();

    return 0;
}