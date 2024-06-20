/*! \file       main.cpp
 *  \author     Julio Carrasquel
 *  \version    1.0
 *  \date       29.06.2022
 *
 *  Exam. Main module.
 *  It's for your reference only (consider tests)! Do not upload it as a solution!
 *  Your submission MUST NOT contain the main() function inside.
 *
 *  Uncomment the tests below one by one and master the code in the solution.h
 *  such that the tests are passed properly (recollect TDD ideas).
 */

#include <cassert>

#include "solution.h"

// Test for Problem 1
void test1() {
    Teacher* arr[2];
	
    arr[0] = new InvitedTeacher("John Caine", 3);
    arr[1] = new AssociateTeacher("Sam Sawyer", 1000);

    std::cout << arr[0]->getName() << ' ' << arr[0]->calcWages() << std::endl; // must call calcWages() from InvitedTeacher
    std::cout << arr[1]->getName() << ' ' << arr[1]->calcWages() << std::endl; // must call calcWages() from AssociatedTeacher

    for(Teacher* t : arr)
        delete t;
}

// Test for Problem 2
void test2() {
   TArray tArr;
   tArr.addInvitedTeacher("John Caine", 3);
   tArr.addAssociateTeacher("Sam Sawyer", 1000);

   std::cout << tArr << std::endl;
}

// Test for Problem 3
void test3() {
   TArray tArr;
   tArr.addInvitedTeacher("John Caine", 4);
   tArr.addAssociateTeacher("Sam Sawyer", 1000);
   tArr.addInvitedTeacher("Samuel Johnson", 2);
   tArr.addAssociateTeacher("Angela Davies", 2000);

   std::pair<int,int> p = totalWagesOfTopTeachers(tArr, 3, 1000);

   std::cout << p.first << ' ' << p.second << std::endl;
}


// Test for Problem 4
void test4() {
   TArray arr1;
   arr1.addAssociateTeacher("Sam Sawyer", 1000);
   arr1.addAssociateTeacher("Angela Davies", 2000);
   arr1.addInvitedTeacher("John Caine", 4);
   arr1.addInvitedTeacher("Samuel Johnson", 2);

   // test CC
   TArray arr2(arr1);
   assert(arr2.getSize() == arr1.getSize());
   assert(arr2[0]->getName() == arr1[0]->getName());
   assert(arr2[0]->calcWages() == arr1[0]->calcWages());
   assert(arr2[1]->getName() == arr1[1]->getName());
   assert(arr2[1]->calcWages() == arr1[1]->calcWages());
   assert(arr2[2]->getName() == arr1[2]->getName());
   assert(arr2[2]->calcWages() == arr1[2]->calcWages());
   assert(arr2[3]->getName() == arr1[3]->getName());
   assert(arr2[3]->calcWages() == arr1[3]->calcWages());

   // test CAO
   TArray arr3;
   arr3.addAssociateTeacher("John", 1);
   arr3.addInvitedTeacher("Jack", 2);

   arr3 = arr2;
   assert(arr3.getSize() == arr1.getSize());
   assert(arr3[0]->getName() == arr1[0]->getName());
   assert(arr3[0]->calcWages() == arr1[0]->calcWages());
   assert(arr3[1]->getName() == arr1[1]->getName());
   assert(arr3[1]->calcWages() == arr1[1]->calcWages());
   assert(arr3[2]->getName() == arr1[2]->getName());
   assert(arr3[2]->calcWages() == arr1[2]->calcWages());
   assert(arr3[3]->getName() == arr1[3]->getName());
   assert(arr3[3]->calcWages() == arr1[3]->calcWages());
}

int main() {
    // Uncomment the tests step by step

   test1();
   test2();
   test3();
   test4();
}
