class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        this->s = small;
        this->m = medium;
        this->b = big;
    }
    
    bool addCar(int carType) {
        return (carType == 1)? b-- > 0 : (carType == 2)? m-- > 0 : s-- > 0;
    }
private:
    int s = 0, m = 0, b = 0;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
