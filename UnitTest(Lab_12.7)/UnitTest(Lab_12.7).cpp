#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.7/Lab_12.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab127
{
	TEST_CLASS(UnitTestLab127)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* first = NULL;
			Spusok* last = NULL;

			Spusok* first_1 = NULL;
			Spusok* last_1 = NULL;

			Spusok* T = first;

			Start_1(first, last, 36);
			Start_1(first, last, 92);
			Start_1(first, last, 4);
			Start_1(first, last, 27);

			T = first;
			int kil_pro = process(T, first_1, last_1);

			T = first_1;
			int l = T->inf;
			Assert::AreEqual(l, 36);
		}
	};
}
