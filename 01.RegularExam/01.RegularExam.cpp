// 01. Swimming Championship
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    
    int N; 
    int needPoint; 
    int swimCnt; 
    double hotelPrice; 
    double feeTax;

    cin >> N >> needPoint >> swimCnt >> hotelPrice >> feeTax;
        
    vector<double> dayPoints(N);
       
    for (int i = 0; i < N; i++) {
        cin >> dayPoints[i];
    }

   
    double totalPoints = 0;
    
    for (int idx = 0; idx < N; idx++) {
        
        totalPoints += dayPoints[idx];
        
        if (idx > 0) { 
           
            totalPoints += 0.05 * dayPoints[idx - 1];
        }
    }

    
    double totalHotelPrice = swimCnt * hotelPrice * N;
    double totalFeeTax = swimCnt * feeTax;
    double totalExp = totalHotelPrice + totalFeeTax;
        
    double sponsorShare = (totalPoints >= needPoint) ? 0.25 : 0.10;
    double moneyLeft = totalExp * (1 - sponsorShare);
        
    cout << setprecision(2) << fixed ;
    cout << "Money left to pay: " << moneyLeft << " BGN." << endl;
    
    if (totalPoints >= needPoint) {
        
        cout << "The championship was successful!" << endl;
    }
    else {
       
        cout << "The championship was not successful." << endl;
    }

    return 0;
}
