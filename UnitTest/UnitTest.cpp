#include "pch.h"
#include "CppUnitTest.h"
#include "../Program/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(met_myrand)
		{
			srand(time(NULL));
			int m = myrand(1, 3);
			Assert::IsTrue(m == 1 || m == 2 || m == 3, L"Incorrect method myrand!");
		}
	};
}
