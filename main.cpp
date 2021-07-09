#include <iostream>
#include <vector>
#include <cstdlib>


#define FOR_WAGONS(count, function) for (int i = 0; i < count; ++i) {function(i);}
#define PRINT_PEOPLE_SUM (std::cout << "Passengers in train: " << (peopleSum));

std::vector<int> train;
const int OPTIMAL_LOAD = 20;
int peopleSum = 0;

/**
 * @function predicate for macros FOR_WAGONS.
 * Prints the count of passengers if their number is over the optimal load.
 * @param wagon [out] wagon number of the wagon in train.
 */
void chekIfOverloaded(int wagon)
{
    if (train[wagon] > 20)
    {
        std::cout << "Wagon " << wagon + 1 << " is overloaded (" << train[wagon] << ")\n";
    }
}

/**
 * @funstion fills the train with passengers (randomly).
 * @param [in] wagon number to be filled.
 */
void fillTheWagon(int wagon)
{
    int a = std::rand() % (OPTIMAL_LOAD + 5);
    train.push_back(a);
    std::cout << "Wagon " << wagon + 1 << " gets " << a << " passengers.\n";
}

/**
 * @function predicate for macros FOR_WAGONS.
 * Prints the count of passengers if their number is under the optimal load.
 * @param wagon [out] wagon number of the wagon in train.
 */
void chekIfUnderloaded(int wagon)
{
    if (train[wagon] < OPTIMAL_LOAD)
    {
        std::cout << "Wagon " << wagon + 1 << " is underloaded (" <<
        OPTIMAL_LOAD - train[wagon] << " free seats)\n";
    }
}

/**
 * @function predicate for macros FOR_WAGONS. Add passengers count to global sum.
 * @param [out] wagon number of the wagon in train.
 */
void addToPeopleSum(int wagon)
{
    peopleSum += train[wagon];
}

int main() {

    std::srand(time(nullptr));

    FOR_WAGONS(OPTIMAL_LOAD, fillTheWagon);
    FOR_WAGONS(OPTIMAL_LOAD, chekIfOverloaded);
    FOR_WAGONS(OPTIMAL_LOAD, chekIfUnderloaded);
    FOR_WAGONS(OPTIMAL_LOAD, addToPeopleSum);
    PRINT_PEOPLE_SUM

    return 0;
}
