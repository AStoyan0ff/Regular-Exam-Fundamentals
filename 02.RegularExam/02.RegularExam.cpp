// 02. Array to Number
#include <iostream>
#include <vector>
using namespace std;

int main() {
   
    int N;
    cin >> N; 

    vector<int> numbers(N);
    
    for (int idx = 0; idx < N; idx++) {
        cin >> numbers[idx];
    }
        
    while (numbers.size() > 1) {
        vector<int> myVector;
        
        for (size_t i = 0; i < numbers.size() - 1; i++) {
            myVector.push_back(numbers[i] + numbers[i + 1]);
        }
        numbers = myVector;
    }
        
    cout << numbers[0] << endl;
    
    return 0;
}
