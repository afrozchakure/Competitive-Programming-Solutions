// My Solution
class ParkingSystem
{
    int big;
    int medium;
    int small;

public:
    ParkingSystem(int big, int medium, int small)
    {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1 && this->big > 0)
        {
            this->big -= 1;
            return true;
        }
        if (carType == 2 && this->medium > 0)
        {
            this->medium -= 1;
            return true;
        }
        if (carType == 3 && this->small > 0)
        {
            this->small -= 1;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

// Cleaner Solution
class ParkingSystem
{
    int big;
    int medium;
    int small;

public:
    ParkingSystem(int big, int medium, int small)
    {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1 && big == 0 || carType == 2 && medium == 0 || carType == 3 && small == 0)
            return false;

        if (carType == 1)
            big--;
        if (carType == 2)
            medium--;
        if (carType == 3)
            small--;

        return true;
    }
};