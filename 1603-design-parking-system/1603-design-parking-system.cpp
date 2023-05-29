class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        parkingSlotCount[1] = big;
        parkingSlotCount[2] = medium;
        parkingSlotCount[3] = small;
    }
    
    bool addCar(int carType) {
        if (parkingSlotCount[carType] == 0) {
            return false;
        }
        parkingSlotCount[carType] -= 1;
        return true;
    }
    
private:
    map<int, int> parkingSlotCount;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */