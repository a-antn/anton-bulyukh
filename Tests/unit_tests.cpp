#include <stdexcept>
#include <string>
#include <utility>

#include "CppUnitTest.h"
#include "../DoublyLinkedList/doubly_linked_list.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(DoublyLinkedListTests)
    {
    public:

        TEST_METHOD(DefaultConstructor_CreatesEmptyList)
        {
            //Arrange & Act
            DoublyLinkedList list;

            //Assert
            Assert::IsTrue(list.IsEmpty());
            Assert::AreEqual(static_cast<std::size_t>(0), list.Size());
        }

        TEST_METHOD(InitializerList_CreatesListWithValues)
        {
            //Arrange & Act
            DoublyLinkedList list = { 1, 2, 3 };

            //Assert
            Assert::IsFalse(list.IsEmpty());
            Assert::AreEqual(static_cast<std::size_t>(3), list.Size());
            Assert::AreEqual(1, list.Front());
            Assert::AreEqual(3, list.Back());
        }

        TEST_METHOD(PushBack_AddsElementToEnd)
        {
            //Arrange
            DoublyLinkedList list;

            //Act
            list.PushBack(10);
            list.PushBack(20);

            //Assert
            Assert::AreEqual(10, list.Front());
            Assert::AreEqual(20, list.Back());
            Assert::AreEqual(static_cast<std::size_t>(2), list.Size());
        }

        TEST_METHOD(PushFront_AddsElementToBeginning)
        {
            //Arrange
            DoublyLinkedList list;

            //Act
            list.PushFront(10);
            list.PushFront(20);

            //Assert
            Assert::AreEqual(20, list.Front());
            Assert::AreEqual(10, list.Back());
            Assert::AreEqual(static_cast<std::size_t>(2), list.Size());
        }

        TEST_METHOD(PopBack_RemovesLastElement)
        {
            //Arrange
            DoublyLinkedList list = { 1, 2, 3 };

            //Act
            const bool removed = list.PopBack();

            //Assert
            Assert::IsTrue(removed);
            Assert::AreEqual(2, list.Back());
            Assert::AreEqual(static_cast<std::size_t>(2), list.Size());
        }

        TEST_METHOD(PopFront_RemovesFirstElement)
        {
            //Arrange
            DoublyLinkedList list = { 1, 2, 3 };

            //Act
            const bool removed = list.PopFront();

            //Assert
            Assert::IsTrue(removed);
            Assert::AreEqual(2, list.Front());
            Assert::AreEqual(static_cast<std::size_t>(2), list.Size());
        }

        TEST_METHOD(PopFromEmpty_ReturnsFalse)
        {
            //Arrange
            DoublyLinkedList list;

            //Act & Assert
            Assert::IsFalse(list.PopBack());
            Assert::IsFalse(list.PopFront());
        }

        TEST_METHOD(CopyConstructor_CreatesIndependentCopy)
        {
            //Arrange
            DoublyLinkedList src = { 1, 2, 3 };

            //Act
            DoublyLinkedList copy(src);

            //Assert
            Assert::IsTrue(src == copy);
            copy.PushBack(4);
            Assert::IsFalse(src == copy);
            Assert::AreEqual(static_cast<std::size_t>(3), src.Size());
        }

        TEST_METHOD(MoveConstructor_TransfersData)
        {
            //Arrange
            DoublyLinkedList src = { 1, 2, 3 };

            //Act
            DoublyLinkedList dst(std::move(src));

            //Assert
            Assert::AreEqual(static_cast<std::size_t>(3), dst.Size());
            Assert::AreEqual(1, dst.Front());
            Assert::AreEqual(3, dst.Back());
            Assert::IsTrue(src.IsEmpty());
        }

        TEST_METHOD(CopyAssignment_CopiesValues)
        {
            //Arrange
            DoublyLinkedList a = { 1, 2, 3 };
            DoublyLinkedList b = { 9, 9 };

            //Act
            b = a;

            //Assert
            Assert::IsTrue(a == b);
            Assert::AreEqual(static_cast<std::size_t>(3), b.Size());
        }

        TEST_METHOD(MoveAssignment_TransfersData)
        {
            //Arrange
            DoublyLinkedList src = { 1, 2, 3 };
            DoublyLinkedList dst;

            //Act
            dst = std::move(src);

            //Assert
            Assert::AreEqual(static_cast<std::size_t>(3), dst.Size());
            Assert::IsTrue(src.IsEmpty());
        }

        TEST_METHOD(SelfAssignment_DoesNotBreakList)
        {
            //Arrange
            DoublyLinkedList list = { 1, 2, 3 };

            //Act
            list = list;

            //Assert
            Assert::AreEqual(static_cast<std::size_t>(3), list.Size());
            Assert::AreEqual(1, list.Front());
            Assert::AreEqual(3, list.Back());
        }

        TEST_METHOD(ToString_FormatsNonEmptyList)
        {
            //Arrange
            DoublyLinkedList list = { 1, 2, 3 };

            //Act
            const std::string text = list.ToString();

            //Assert
            Assert::AreEqual(std::string("[1, 2, 3]"), text);
        }

        TEST_METHOD(ToString_FormatsEmptyList)
        {
            //Arrange
            DoublyLinkedList list;

            //Act
            const std::string text = list.ToString();

            //Assert
            Assert::AreEqual(std::string("[]"), text);
        }

        TEST_METHOD(IsEmpty_TogglesCorrectly)
        {
            //Arrange
            DoublyLinkedList list;

            //Act & Assert
            Assert::IsTrue(list.IsEmpty());
            list.PushBack(42);
            Assert::IsFalse(list.IsEmpty());
            list.PopBack();
            Assert::IsTrue(list.IsEmpty());
        }

        TEST_METHOD(At_ReturnsValueByIndex)
        {
            //Arrange
            DoublyLinkedList list = { 10, 20, 30 };

            //Assert
            Assert::AreEqual(10, list.At(0));
            Assert::AreEqual(20, list.At(1));
            Assert::AreEqual(30, list.At(2));
        }

        TEST_METHOD(At_OutOfRange_Throws)
        {
            //Arrange
            DoublyLinkedList list = { 1, 2, 3 };

            //Act & Assert
            Assert::ExpectException<std::out_of_range>([&]() { list.At(10); });
        }

        TEST_METHOD(Front_OnEmpty_Throws)
        {
            //Arrange
            DoublyLinkedList list;

            //Act & Assert
            Assert::ExpectException<std::out_of_range>([&]() { list.Front(); });
        }

        TEST_METHOD(Back_OnEmpty_Throws)
        {
            //Arrange
            DoublyLinkedList list;

            //Act & Assert
            Assert::ExpectException<std::out_of_range>([&]() { list.Back(); });
        }

        TEST_METHOD(Clear_RemovesAllElements)
        {
            //Arrange
            DoublyLinkedList list = { 1, 2, 3, 4, 5 };

            //Act
            list.Clear();

            //Assert
            Assert::IsTrue(list.IsEmpty());
            Assert::AreEqual(static_cast<std::size_t>(0), list.Size());
        }

        TEST_METHOD(Equality_DifferentSize_NotEqual)
        {
            //Arrange
            DoublyLinkedList a = { 1, 2, 3 };
            DoublyLinkedList b = { 1, 2 };

            //Assert
            Assert::IsTrue(a != b);
            Assert::IsFalse(a == b);
        }

        TEST_METHOD(Equality_SameValues_Equal)
        {
            //Arrange
            DoublyLinkedList a = { 1, 2, 3 };
            DoublyLinkedList b = { 1, 2, 3 };

            //Assert
            Assert::IsTrue(a == b);
            Assert::IsFalse(a != b);
        }

        TEST_METHOD(PushPop_BidirectionalLinks_Work)
        {
            //Arrange
            DoublyLinkedList list;
            list.PushBack(1);
            list.PushBack(2);
            list.PushBack(3);

            //Act
            list.PopFront();
            list.PopBack();

            //Assert
            Assert::AreEqual(static_cast<std::size_t>(1), list.Size());
            Assert::AreEqual(2, list.Front());
            Assert::AreEqual(2, list.Back());
        }
    };
}
