#include <igloo/igloo.h>
#include <SortedArray.h>

using namespace igloo;

int main() {
	Context (SortedArrayInsertTest){
		Spec(InsertFiveAtZero) {
			SortedArray expected;
			expected.append(5);

			SortedArray actual;
			actual.insert(0,5);

			Assert::That(actual, Equals(expected));
		}
		Spec(InsertFiveAtEnd) {
			SortedArray expected;
			expected.append(1);
			expected.append(1);
			expected.append(5);
			expected.append(12);
			expected.append(14);
			expected.append(31);
			
			SortedArray actual;
			actual.append(12);
			actual.append(1);
			actual.append(31);
			actual.append(14);
			actual.append(1);

			actual.insert(4,5);

			Assert::That(actual, Equals(expected));
		}

		Spec(InsertFiveAtFront) {
			SortedArray expected;
			expected.append(1);
			expected.append(1);
			expected.append(5);
			expected.append(12);
			expected.append(14);
			expected.append(31);
			
			SortedArray actual;
			actual.append(12);
			actual.append(1);
			actual.append(31);
			actual.append(14);
			actual.append(1);

			actual.insert(0,5);

			Assert::That(actual, Equals(expected));
		}

		Spec(InsertFiveAtMid) {
			SortedArray expected;
			expected.append(1);
			expected.append(1);
			expected.append(5);
			expected.append(12);
			expected.append(14);
			expected.append(31);
			
			SortedArray actual;
			actual.append(12);
			actual.append(1);
			actual.append(31);
			actual.append(14);
			actual.append(1);

			actual.insert(2,5);

			Assert::That(actual, Equals(expected));
		}
	};
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
