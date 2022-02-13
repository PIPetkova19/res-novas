#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnTrueWhenTheInputIsValid)
			TEST_OWNER(L"IGVasilev19")
			TEST_PRIORITY("Low")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(expectToReturnTrueWhenTheInputIsValid)
		{

			Assert::AreEqual(1, 2);
		}
	};
}
