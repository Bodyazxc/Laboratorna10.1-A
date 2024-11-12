#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna10.1A/Laboratorna10.1A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101A
{
	TEST_CLASS(UnitTest101A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Students students[2];

            
            students[0].grade_physics = 3;
            students[0].grade_math = 3;
            students[0].grade_info = 3;

            students[1].grade_physics = 5;
            students[1].grade_math = 5;
            students[1].grade_info = 5;

            double result = PercentageLowAverage(students, 2);

            Assert::AreEqual(result, 50.0, 0.001);
		}
	};
}
