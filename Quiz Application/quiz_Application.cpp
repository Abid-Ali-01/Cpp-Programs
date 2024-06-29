#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Question{
    string question;
    char TF;
    public:
    Question(const string& ques, char tf): question(ques), TF(tf){}

    //Getters
    string getQuestion()const {
        return question;
    }
     char  getAnswer()const {
        return TF;
    }

};

class QPaper {
    vector<Question> questions;
    char ans;
    int score = 0;

public:
    void AddQuestion(const Question& question) {
        questions.push_back(question);
        cout << "Question Added to Question Paper" << endl;
    }

    void AskQuestions() {
        for (auto& question : questions) {
            cout << question.getQuestion() << endl;
            cin >> ans;

            // Convert both answers to lowercase for case-insensitive comparison
            char correctAnswer = tolower(question.getAnswer());
            char userAnswer = tolower(ans);

            if (userAnswer == correctAnswer) {
                score++;
                cout << "Correct" << endl;
            } else if (userAnswer == 't' || userAnswer == 'f') {
                cout << "Wrong" << endl;
            } else {
                cout << "Invalid Input, Please Press T or F Only" << endl;
            }

            cout << "Your Score Is: " << score << endl;
        }
        if(score >= 6){
            cout<<"Great Job, You Undersand C++ Very Well"<<endl;
        }
        else{
            cout<<"Nice Try, You Have To Study A Bit More"<<endl;
        }

    }

    
};





int main(){
Question q1("C++ is an extension of the C programming language.", 't');
Question q2("In C++, the new keyword is used to deallocate memory.", 'f');
Question q3(" In C++, a class can have multiple destructors.", 'f');
Question q4("The private access specifier in a class restricts access to class members from outside the class.", 't');
Question q5("Function overloading allows multiple functions to have the same name with different parameter lists.", 't');
Question q6("The standard input stream in C++ is represented by cin.", 't');
Question q7(" In C++, the switch statement can be used with floating-point numbers.", 'f');
Question q8("In C++, inheritance allows a derived class to access private members of its base class.", 'f');
Question q9(" In C++, the keyword this is a pointer to the current object.", 't');
Question q10("The friend keyword in C++ allows a function or another class to access private and protected members of a class.", 't');


QPaper QP;
QP.AddQuestion(q1);
QP.AddQuestion(q2);
QP.AddQuestion(q3);
QP.AddQuestion(q4);
QP.AddQuestion(q5);
QP.AddQuestion(q6);
QP.AddQuestion(q7);
QP.AddQuestion(q8);
QP.AddQuestion(q9);
QP.AddQuestion(q10);

cout<<"------------------------------------------------------------"<<endl;

QP.AskQuestions();





    
}
