#include<iostream>
using namespace std;

enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

int RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}
enOperationType GetRandomOperationtype()
{
	short  Op = 0;
	Op = RandomNumber(1, 4);
	return (enOperationType)Op;
}
string GetOpTypeSymbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mult:
		return "*";
	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}
}
short SimpleCalculator(short Number1, short Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Mult:
		return Number1 * Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	default:
		Number1 + Number2;
		break;
	}
}
struct stQuestion
{
	short Number1 = 0;
	short Number2 = 0;
	enOperationType OperationType;
	enQuestionLevel QuestionLevel;
	short CorrectAnswer = 0;
	short PlayerAnswer = 0;
	bool AnswerResult = false;

};
struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions;
	enQuestionLevel QuestionLevel;
	enOperationType OpType;
	short NumberOfWrongAnswers = 0;
	short NumberOfRightAnswers = 0;
	bool isPass = false;

};

short ReadHowManyQuestions()
{
	short NumberOfQuestions;
	do
	{
		cout << "How many questions do you want to answer? ";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);
	return  NumberOfQuestions;
}
enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel = 0;
	do
	{
		cout << "enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix? ";
		cin >> QuestionLevel;

	} while (QuestionLevel < 1 || QuestionLevel > 4);
	return (enQuestionLevel)QuestionLevel;
}
string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = { "Easy","Medium","Hard","Mixed" };
	return arrQuestionLevelText[QuestionLevel - 1];
}
enOperationType ReadOpType()
{
	short Optype = 0;
	do
	{
		cout << "Enter Operation type [1] Add, [2] sub, [3] Mult, [4] Div, [5] Mix? ";
		cin >> Optype;
	} while (Optype < 1 || Optype > 5);

	return (enOperationType)Optype;
}
int ReadQuestionAnswer()
{
	short PlayerAnswer = 0;
	cin >> PlayerAnswer;
	return PlayerAnswer;
}
stQuestion GeneratQuestion(enQuestionLevel QuestionLevel, enOperationType OpType)
{
	stQuestion Question;
	if (QuestionLevel == enQuestionLevel::Mix)
	{
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);

	}
	if (OpType == enOperationType::MixOp)
	{
		OpType = GetRandomOperationtype();
	}

	Question.OperationType = OpType;
	switch (QuestionLevel)
	{
	case enQuestionLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	case enQuestionLevel::MedLevel:

		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	case enQuestionLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	}
}
void GeneratQuizzQuestions(stQuizz& Quizz)
{
	for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
	{
		Quizz.QuestionList[Question] = GeneratQuestion(Quizz.QuestionLevel, Quizz.OpType);
	}
}
void PrintQuestion(stQuizz& Quizz, short QuestionsNumber)
{
	cout << "\n";
	cout << "Question [" << QuestionsNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n";
	cout << Quizz.QuestionList[QuestionsNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionsNumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionsNumber].OperationType);
	cout << "\n---------------" << endl;


}
void CorrectTheQuestionListAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "\nWrong answer :-(\n";
		cout << "the right answer is ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;

	}
	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;
		cout << "\nRigth answer :-)\n";
	}
	cout << endl;
}
void AskCorrectQuizzListAnswer(stQuizz& Quizz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
	{

		PrintQuestion(Quizz, QuestionNumber);
		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		CorrectTheQuestionListAnswer(Quizz, QuestionNumber);

	}
	Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}
string PassFail(bool Pass)
{
	if (Pass)

		return  "PASS :-)";

	else

		return  "FAIL :-(";

}
void PrintResult(stQuizz& Quizz)
{
	cout << "-------------------------------------\n";
	cout << "Final Result is " << PassFail(Quizz.isPass);
	cout << "\n-------------------------------------\n";

	cout << "Number of question     : " << Quizz.NumberOfQuestions << endl;
	cout << "Question Level         : " << GetQuestionLevelText(Quizz.QuestionLevel) << endl;
	cout << "Operation type         : " << GetOpTypeSymbol(Quizz.OpType) << endl;
	cout << "Number of rigth answers: " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number of wrong answers: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "-------------------------------------\n";

}
void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionLevel();
	Quizz.OpType = ReadOpType();

	GeneratQuizzQuestions(Quizz);
	AskCorrectQuizzListAnswer(Quizz);
	PrintResult(Quizz);

}
void ResetScreen()
{
	system("cls");
	system("color 0F");
}
void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();
		cout << "Do you want to play again Y/N? : ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
	srand((unsigned)time(NULL));
	StartGame();

	return 0;

}