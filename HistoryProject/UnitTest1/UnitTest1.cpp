#include "pch.h"
#include "CppUnitTest.h"
#include "..\HistoryProject\LinkedList.h"
//#include "..\HistoryProject\Menu.h"
//#include "..\HistoryProject\Menu.cpp"
//#include "..\HistoryProject\LinkedList.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace grayCode;



namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnBinaryRepresentationOfFive)
			TEST_OWNER(L"IGVasilev19")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(expectToReturnBinaryRepresentationOfFive)
		{
			//Arrange
			int expected = 101;



			//Act
			int binary = decToBin(5);
			//Assert

			Assert::AreEqual(expected, binary);

		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnGrayRepresentationOfBinaryNumber)
			TEST_OWNER(L"IGVasilev19")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(expectToReturnGrayRepresentationOfBinaryNumber)
		{
			//Arrange
			int expected = 101;



			//Act
			int binary = binToGraysCode(6);
			//Assert

			Assert::AreEqual(expected, binary);

		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnDecimalRepresentationOfGrayNumber)
			TEST_OWNER(L"IGVasilev19")
			TEST_PRIORITY("High")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(expectToReturnDecimalRepresentationOfGrayNumber)
		{
			//Arrange
			int expected = 87;



			//Act
			int dec = grayCodeConversion(101);
			//Assert

			Assert::AreEqual(expected, dec);

		}
		
	};

}