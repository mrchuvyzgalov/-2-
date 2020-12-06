#include "test_decision.h"
#include "test_runner.h"

void test_decision::TestAlldecisions() {
    TestRunner tr;

    RUN_TEST(tr, test_decision::TestEuler);
    RUN_TEST(tr, test_decision::TestDiophantine);
    RUN_TEST(tr, test_decision::TestBruteForce1);
    RUN_TEST(tr, test_decision::TestBruteForce2);
    RUN_TEST(tr, test_decision::TestFractions);
}

void test_decision::TestFunction(const DecisionClass& class_) {
    {                                                      
        Deductions<int> d = decision(1, 2, 5, class_);      
                                                           
        std::vector<int> v1 = { 2 };                       
                                                           
        ASSERT_EQUAL(d.get_leftovers(), v1);               
        ASSERT_EQUAL(d.get_module(), 5);                   
    }                                                      
                                                           
    {                                                      
        Deductions<int> d = decision(12, 8, 48, class_);   
                                                           
        std::vector<int> v1 = { };                         
                                                           
        ASSERT_EQUAL(d.get_leftovers(), v1);               
        ASSERT_EQUAL(d.get_module(), 0);                   
    }                                                      
                                                           
    {                                                      
        Deductions<int> d = decision(9, 3, 12, class_);     
                                                           
        std::vector<int> v1 = { 3, 7, 11};                 
                                                           
        ASSERT_EQUAL(d.get_leftovers(), v1);               
        ASSERT_EQUAL(d.get_module(), 12);                  
    }                                                      
                                                           
    {                                                      
        Deductions<int> d = decision(-3, 3, 12, class_);    
                                                           
        std::vector<int> v1 = { 3, 7, 11};                 
                                                           
        ASSERT_EQUAL(d.get_leftovers(), v1);               
        ASSERT_EQUAL(d.get_module(), 12);                  
    }                                                      
                                                           
    {                                                      
        Deductions<int> d = decision(-3, -9, 12, class_);   
                                                           
        std::vector<int> v1 = { 3, 7, 11};                 
                                                           
        ASSERT_EQUAL(d.get_leftovers(), v1);               
        ASSERT_EQUAL(d.get_module(), 12);                  
    }                                                      
                                                           
    {                                                      
        Deductions<int> d = decision(9, -9, 12, class_);    
                                                           
        std::vector<int> v1 = { 3, 7, 11};                 
                                                           
        ASSERT_EQUAL(d.get_leftovers(), v1);               
        ASSERT_EQUAL(d.get_module(), 12);                  
    }                                                      
}

void test_decision::TestEuler() {
    TestFunction(DecisionClass::EULER);
}

void test_decision::TestDiophantine() {
    TestFunction(DecisionClass::DIOPHANTINE);
}

void test_decision::TestBruteForce1() {
    TestFunction(DecisionClass::BRUTE_FORCE_1);
}

void test_decision::TestBruteForce2() {
    TestFunction(DecisionClass::BRUTE_FORCE_2);
}

void test_decision::TestFractions() {
    TestFunction(DecisionClass::FRACTIONS);
}
