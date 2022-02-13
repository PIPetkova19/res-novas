#include "pch.h"
#include "CppUnitTest.h"
#include "..\HistoryProject\LinkedList.h"
#include "..\HistoryProject\Menu.h"
#include "..\HistoryProject\Menu.cpp"
#include "..\HistoryProject\LinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		     //Arrange
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnTrueWhenTheInputIsValid)
			TEST_OWNER(L"IGVasilev19")
			TEST_PRIORITY("Low")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(expectToReturnTrueWhenTheInputIsValid)
		{

			//Act
			int x = 12;
			int y = 2005;



			bool result = checkFunctions::checkDay(x, y);


			//Assert
			Assert::AreEqual(true, result);
		}
	};
}
