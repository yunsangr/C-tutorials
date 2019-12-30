/*
 * Chapter 3-3 Understanding of OOP
 *
 *  실제로 세상에 있는 객체를 프로그램으로 구현한다.
 *
 * ex)
 * "나는 과일장수에게 두 개의 사과를 구매했다."
 *      개체(Object): 나, 과일장수, 사과
 *      데이터(State || Data): 두 개
 *      행위, 기능(Action, function): 구매
 *
 */

#include <iostream>

using namespace std;

class FruitSeller {
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InitMembers(int price, int num, int money);
    int SaleApples(int money);
    void ShowSalesResult();
};

void FruitSeller:: InitMembers(int price, int num, int money) {
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
}

int FruitSeller:: SaleApples(int money) {
    int num = money/APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
}

void FruitSeller:: ShowSalesResult() {
    cout << "판매자 정보 " << endl;
    cout << "사과 가격: " << APPLE_PRICE << endl;
    cout << "남은 사과: " << numOfApples << endl;
    cout << "판매 수익: " << myMoney << endl << endl;

}

class FruitBuyer{
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money){
        myMoney = money;
        numOfApples = 0;
    }
    void BuyApples(FruitSeller &seller, int money){
        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResult(){
        cout << "구매자 정보 " << endl;
        cout << "현재 잔액: " << myMoney << endl;
        cout << "사과 개수: " << numOfApples << endl;
    }
};

int main(){

    FruitSeller seller;
    seller.InitMembers(1000, 50, 0);

    seller.ShowSalesResult();
    seller.SaleApples(2000);
    seller.ShowSalesResult();

    FruitBuyer buyer;
    buyer.InitMembers(23000);
    seller.ShowSalesResult();

    buyer.BuyApples(seller, 3000);

    seller.ShowSalesResult();
    buyer.ShowBuyResult();




    return 0;
}













