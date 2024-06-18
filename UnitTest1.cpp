#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Plant_Powered\Darren assignment C\gymapp_c\gym_app.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestGetValidatedChar)
        {
            std::istringstream input("y\nn\n");
            std::cin.rdbuf(input.rdbuf());

            Assert::AreEqual('y', getValidatedChar());
            Assert::AreEqual('n', getValidatedChar());

            std::istringstream input2("a\n1\ny\n");
            std::cin.rdbuf(input2.rdbuf());

            Assert::AreEqual('y', getValidatedChar());
        }

        TEST_METHOD(TestDataInput)
        {
            std::istringstream input("John Doe\n2\n70\n");
            std::cin.rdbuf(input.rdbuf());

            dataInput();

            Assert::AreEqual(std::string("John Doe"), athleteName);
            Assert::AreEqual(2, trainingPlan);
            Assert::AreEqual(70.0f, weight);
        }

        TEST_METHOD(TestInputCompetitionCategory)
        {
            std::istringstream input("3\n");
            std::cin.rdbuf(input.rdbuf());

            inputCompetitionCategory();

            Assert::AreEqual(3, category);
        }

        TEST_METHOD(TestGetCompetitionInput)
        {
            trainingPlan = 2;
            std::istringstream input("1\n");
            std::cin.rdbuf(input.rdbuf());

            getCompetitionInput();

            Assert::AreEqual(1, competitions);
        }

        TEST_METHOD(TestPrivateLessonsInput)
        {
            std::istringstream input("5\n");
            std::cin.rdbuf(input.rdbuf());

            privateLessonsInput();

            Assert::AreEqual(5, privateLessons);
        }

        TEST_METHOD(TestYourInfo)
        {
            athleteName = "Jane Doe";
            trainingPlan = 3;
            weight = 65;
            category = 4;
            competitions = 1;
            privateLessons = 2;

            std::istringstream input("y\n");
            std::cin.rdbuf(input.rdbuf());

            yourInfo();

            Assert::AreEqual('y', correct);
        }

        TEST_METHOD(TestCostSessions)
        {
            trainingPlan = 1;
            costSessions();
            Assert::AreEqual(100.0f, costOfSessions);

            trainingPlan = 2;
            costSessions();
            Assert::AreEqual(200.0f, costOfSessions);

            trainingPlan = 3;
            costSessions();
            Assert::AreEqual(300.0f, costOfSessions);
        }

        TEST_METHOD(TestCostCompetitionsFunc)
        {
            competitions = 1;
            costCompetitionsFunc();
            Assert::AreEqual(50.0f, costCompetitions);

            competitions = 0;
            costCompetitionsFunc();
            Assert::AreEqual(0.0f, costCompetitions);
        }

        TEST_METHOD(TestCostPrivateLessons)
        {
            privateLessons = 4;
            costPrivateLessons();
            Assert::AreEqual(100.0f, privateLessonCost);
        }

        TEST_METHOD(TestWeightComparison)
        {
            std::ostringstream output;
            std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

            weightComparison(67, 6);
            Assert::AreEqual(std::string("Your current weight exceeds the maximum weight for this category. Please consider competing in the heavier category."), output.str());

            std::cout.rdbuf(oldCoutBuf);
        }

        TEST_METHOD(TestTotalCostCalculation)
        {
            costOfSessions = 200;
            costCompetitions = 50;
            privateLessonCost = 100;

            totalCostCalculation();

            Assert::AreEqual(350.0f, totalCost);
        }
    };
}
