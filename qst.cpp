#include <iostream>
#include <string>
#include <vector>

// Structure to represent a question and its answer
struct Question {
    std::string question;
    std::string answer;
};

int main() {
    std::vector<Question> questions;

    // Populate the list of questions and answers
    Question q1 = {"What is the capital of France?", "Paris"};
    Question q2 = {"What is 2 + 2?", "4"};
    Question q3 = {"Who wrote 'Romeo and Juliet'?", "William Shakespeare"};

    questions.push_back(q1);
    questions.push_back(q2);
    questions.push_back(q3);

    // Main loop to interact with the user
    char choice;
    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Ask a question" << std::endl;
        std::cout << "2. Quit" << std::endl;
        

        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Enter the question number (1-" << questions.size() << "): ";
                int questionNumber;
                std::cin >> questionNumber;

                if (questionNumber >= 1 && questionNumber <= questions.size()) {
                    questionNumber--; // Adjust for 0-based indexing
                    std::cout << "Question: " << questions[questionNumber].question << std::endl;
                    std::string userAnswer;
                    std::cout << "Your Answer: ";
                    std::cin.ignore(); // Consume the newline character
                    std::getline(std::cin, userAnswer);

                    if (userAnswer == questions[questionNumber].answer) {
                        std::cout << "Correct!" << std::endl;
                    } else {
                        std::cout << "Incorrect. The correct answer is: " << questions[questionNumber].answer << std::endl;
                    }
                } else {
                    std::cout << "Invalid question number." << std::endl;
                }
                break;
            case '2':
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
                break;
        }
    } while (choice != '2');

    return 0;
}
