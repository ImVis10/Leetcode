class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        big1 = big;
        medium1 = medium;
        small1 = small;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (big1 == 0) {
                return false;
            } else {
                big1 -= 1;
                return true;
            }
        } else if (carType == 2) {
            if (medium1 == 0) {
                return false;
            } else {
                medium1 -= 1;
                return true;
            }
        } else {
            if (small1 == 0) {
                return false;
            } else {
                small1 -= 1;
                return true;
            }
        }
    }
    
private:
    int big1;
    int medium1;
    int small1;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */