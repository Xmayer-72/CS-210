//Driver.cpp
//Testing for self-organizing linked list ADT
#include "SOLL_ADT.cpp"
#include <iostream>
using namespace std;
int main()
{
    SOLLADT<char> testList;
    SOLLADT<char> testListTranspose;
    SOLLADT<char> testListMTF;
    cout << "1. Given Test Cases:\n\n";
    cout << "Insert A, Insert C, Insert B, Search C, Insert D, Search A, Search D, Search A, Search C, Search A, Search C, Search C, Insert E Search E\n\n\n";
    cout << "Standard search: \n\n";

    testList.insert('A');
    testList.insert('C');
    testList.insert('B');
    testList.search('C');
    testList.insert('D');
    testList.search('A');
    testList.search('D');
    testList.search('A');
    testList.search('C');
    testList.search('A');
    testList.search('C');
    testList.search('C');
    testList.insert('E');
    testList.search('E');
    testList.showSOLL();

    cout << "\n\n\nMTF search: \n\n";
    testListMTF.insert('A');
    testListMTF.insert('C');
    testListMTF.insert('B');
    testListMTF.insert('D');
    testListMTF.search_mtf('A');
    testListMTF.search_mtf('D');
    testListMTF.search_mtf('A');
    testListMTF.search_mtf('C');
    testListMTF.search_mtf('A');
    testListMTF.search_mtf('C');
    testListMTF.search_mtf('C');
    testListMTF.insert('E');
    testListMTF.search_mtf('E');
    testListMTF.showSOLL();

    cout << "\n\n\nTranspose search: \n";
    testListTranspose.insert('A');
    testListTranspose.insert('C');
    testListTranspose.insert('B');
    testListTranspose.insert('D');
    testListTranspose.search_t('A');
    testListTranspose.search_t('D');
    testListTranspose.search_t('A');
    testListTranspose.search_t('C');
    testListTranspose.search_t('C');
    testListTranspose.search_t('A');
    testListTranspose.search_t('C');
    testListTranspose.search_t('C');
    testListTranspose.insert('E');
    testListTranspose.search_t('E');
    testListTranspose.showSOLL();

    cout << "\n\n\n2. Our Test Cases:\n\n";
    // Your test cases here
 
        // Implement here!


    cout << "\n\n\n";
    system("PAUSE");
    return 0;
}