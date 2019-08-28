#include <string>
#include "strlib.h"
#include "IntArray.h"
#include "error.h"
using namespace std;

IntArray::IntArray(){
    count=1;
    array=new int[1];
    *array=0;
}

IntArray::IntArray(int n){
    count=n;
    array=new int[n];
    for (int i=0; i<count; i++) {
        *(array+i)=0;
    }
}

IntArray::~IntArray() {
    delete [] array;
}

int IntArray::get(int k) {
    if (k>=count || k<0) {
        error("Argument is outside the border");
        return 0;
    }else {
        return *(array+k);
    }
}

void IntArray::put(int k, int value) {
    if (k>=count || k<0) {
        error("Argument is outside the border");
    } else {
        *(array+k)=value;
    }
}

int IntArray::size(){
    return count;
}
