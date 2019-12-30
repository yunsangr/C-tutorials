/*
 *  Chapter 3. Intro
 *
 *
 */


#include <iostream>


using namespace std;

struct Car {
    enum {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };

    char gamerID[ID_LEN];
    int fuelGauge;
    int carSpeed;

    void ShowCarState();

    void Accel();

    void Break();

};

void Car:: ShowCarState()
{
    cout << "gamerID: " << gamerID <<endl;
    cout << "fuelGauge: " << fuelGauge <<endl;
    cout << "carSpeed: " << carSpeed <<endl <<endl;
}

void Car:: Accel() {
    cout << gamerID << " is Accelerating... " << endl;
    cout << "carSpeed: " << carSpeed << " => ";
    carSpeed = carSpeed + 20;
    cout << carSpeed << endl;
}

void Car:: Break() {
    cout << gamerID << " is breaking..." << endl;
    cout << "carSpeed: " << carSpeed << " => ";
    carSpeed = carSpeed - 20;
    cout << carSpeed << endl;
}

int main(){

    struct Car car1 = {"X3 330i M", 300, 140};
    struct Car car2 = {"A5", 100, 120};
    struct Car car3 = {"E350i", 200, 80};

    car1.ShowCarState();
    car2.ShowCarState();
    car3.ShowCarState();

    car1.Accel();
    car1.Accel();

    car1.Break();


    return 0;
}