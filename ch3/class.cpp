/*
 *
 * Chapter 3-2 Class and Struct
 *
 */

/*
 *  접근제어 지시자
 *
 *  - public: 어디서든 접근허용
 *  - protected: 상속관계에 놓여있을 때, 유도 클래스에서의 접근허용
 *  - private: 클래스 내(클래스 내에 정의된 함수)내에에서만 접근허용
 *
 */

#include <iostream>


using namespace std;

class Car {
private:
    char gamerID[20];
    int fuelGauge;
    int carSpeed;

public:
    void InitMembers(char *ID, int fuel){
        fuelGauge = fuel;
    }

    void ShowCarState();

    void Accel();

    void Break();

};f

void Car:: ShowCarState()
{
    cout << "gamerID: " << gamerID <<endl;
    cout << "fuelGauge: " << fuelGauge <<endl;
    cout << "carSpeed: " << carSpeed <<endl <<endl;
}

void Car:: Accel() {
    cout << gamerID << " is Accelerrating... " << endl;
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

    class Car car1 = {"X3 330i M", 300, 140};
    class Car car2 = {"A5", 100, 120};
    class Car car3 = {"E350i", 200, 80};

    car1.ShowCarState();
    car2.ShowCarState();
    car3.ShowCarState();

    car1.Accel();
    car1.Accel();

    car1.Break();


    return 0;
}