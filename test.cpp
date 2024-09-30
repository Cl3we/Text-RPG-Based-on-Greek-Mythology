#include <iostream>
#include <string>

using namespace std;

void convertArrayMember(int member);

int main(){
int array[3] = {1,2,3};
convertArrayMember(array[1]);
cout << array[1] << endl;

    return 0;
}

void convertArrayMember(int member){
member = 5;
}
