/*
 * CSC/CIS-5-47991/47992 Program Logic Using C++ Spring 2023
 *
 * STUDENT:    Austin De La Cruz
 * ASSIGNMENT: Programming Assingment 1
 * DUE DATE:   04/20/2023
 *
 */

/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
 * Name: Go-Kart BRS
 * Description: Calculating rank, laps, and cost from the user's GoKart
 */
int main() 
{
  const double ROOKIE_COST = 2.20;
  const double NOVICE_COST = 1.90;
  const double CONTENDER_COST = 1.60;
  const double CHAMPION_COST = 1.30;
  int CarNumber, laps;
  double CostPerLap, TotalCost;
  string rank;
  cout << "Professor Locke's Get-Up-And-GoKart Track" << endl;
  cout << "Enter car number: ";
  cin >> CarNumber;
  while (true)
    {
      cout << "Enter total laps completed: ";
      cin >> laps;
      if (laps >= 0 && laps <= 19)
    {
  CostPerLap = ROOKIE_COST;
  rank = "Rookie";
  break;
}

else if (laps >= 20 && laps <= 29)
  {
    CostPerLap = NOVICE_COST;
    rank = "Novice";
    break;
  }

else if (laps >= 30 && laps <= 49)
  {
    CostPerLap = CONTENDER_COST;
    rank = "Contender";
    break;
  }

else if (laps >= 50)
  {
    CostPerLap = CHAMPION_COST;
    rank = "Champion";
    break;
  }

else
  {
    cout << "Invalid number, please input laps again." << endl;
  }
}

TotalCost = laps * CostPerLap;
cout<< endl;
cout << fixed << setprecision(2);
cout << "Car Number: " << setw(15) << setfill(' ') << right << CarNumber << endl;
cout << "Laps completed: " << setw(11) << setfill(' ') << right << laps << endl;
cout << "Driver rank: " << setw(14) << setfill(' ') << right << rank << endl;
cout << "Cost per lap: $" << setw(9) << setfill(' ') << right << CostPerLap <<
endl;
cout << "Total cost: $" << setw(9) << setfill(' ') << right << TotalCost <<
endl;
cout <<endl;
cout << "Thank you and drive safely" << endl;
 
  return 0;  
}
