#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream> 
#include "C:\Users\Plant_Powered\Darren assignment C\gymapp_c\gym_app.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // Test for getValidatedChar function
        // Purpose: Validate user input validation function
        // Parameters tested: User input ('y', 'n', 'a', '1')
        // Desired outcome: Ensure correct validation and return of expected characters
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

        // Test for dataInput function
        // Purpose: Validate data input and storage
        // Parameters tested: Athlete name, training plan, weight
        // Desired outcome: Ensure correct storage and retrieval of input data
        TEST_METHOD(TestDataInput)
        {
            std::istringstream input("John Doe\n2\n70\n");
            std::cin.rdbuf(input.rdbuf());
            dataInput();
            Assert::AreEqual(std::string("John Doe"), athleteName);
            Assert::AreEqual(2, trainingPlan);
            Assert::AreEqual(70.0f, weight);
        }

        // Test for inputCompetitionCategory function
        // Purpose: Validate input and storage of competition category
        // Parameters tested: Competition category input
        // Desired outcome: Ensure correct storage and retrieval of competition category
        TEST_METHOD(TestInputCompetitionCategory)
        {
            std::istringstream input("3\n");
            std::cin.rdbuf(input.rdbuf());
            inputCompetitionCategory();
            Assert::AreEqual(3, category);
        }

        // Test for getCompetitionInput function
        // Purpose: Validate input and storage of competition count
        // Parameters tested: Competition count input
        // Desired outcome: Ensure correct storage and retrieval of competition count
        TEST_METHOD(TestGetCompetitionInput)
        {
            trainingPlan = 2;
            std::istringstream input("1\n");
            std::cin.rdbuf(input.rdbuf());
            getCompetitionInput();
            Assert::AreEqual(1, competitions);
        }

        // Test for privateLessonsInput function
        // Purpose: Validate input and storage of private lessons count
        // Parameters tested: Private lessons count input
        // Desired outcome: Ensure correct storage and retrieval of private lessons count
        TEST_METHOD(TestPrivateLessonsInput)
        {
            std::istringstream input("5\n");
            std::cin.rdbuf(input.rdbuf());
            privateLessonsInput();
            Assert::AreEqual(5, privateLessons);
        }

        // Test for yourInfo function
        // Purpose: Validate information display function
        // Parameters tested: None (uses predefined values for athlete info)
        // Desired outcome: Ensure correct display of athlete information
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

        // Test for costSessions function
        // Purpose: Validate calculation of session costs based on training plan
        // Parameters tested: Training plan (1, 2, 3)
        // Desired outcome: Ensure correct calculation of session costs
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

        // Test for costCompetitionsFunc function
        // Purpose: Validate calculation of competition costs based on count
        // Parameters tested: Competitions count (1, 0)
        // Desired outcome: Ensure correct calculation of competition costs
        TEST_METHOD(TestCostCompetitionsFunc)
        {
            competitions = 1;
            costCompetitionsFunc();
            Assert::AreEqual(50.0f, costCompetitions);

            competitions = 0;
            costCompetitionsFunc();
            Assert::AreEqual(0.0f, costCompetitions);
        }

        // Test for costPrivateLessons function
        // Purpose: Validate calculation of private lessons cost
        // Parameters tested: Private lessons count (4)
        // Desired outcome: Ensure correct calculation of private lessons cost
        TEST_METHOD(TestCostPrivateLessons)
        {
            privateLessons = 4;
            costPrivateLessons();
            Assert::AreEqual(100.0f, privateLessonCost);
        }

        // Test for weightComparison function
        // Purpose: Validate weight comparison function
        // Parameters tested: Current weight (67), maximum weight for category (6)
        // Desired outcome: Ensure correct output message for weight comparison
        TEST_METHOD(TestWeightComparison)
        {
            std::ostringstream output;
            std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

            weightComparison(67, 6);
            Assert::AreEqual(std::string("Your current weight exceeds the maximum weight for this category. Please consider competing in the heavier category."), output.str());

            std::cout.rdbuf(oldCoutBuf);
        }

        // Test for totalCostCalculation function
        // Purpose: Validate calculation of total cost including sessions, competitions, and private lessons
        // Parameters tested: Cost of sessions (200), cost of competitions (50), private lesson cost (100)
        // Desired outcome: Ensure correct calculation of total cost
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
