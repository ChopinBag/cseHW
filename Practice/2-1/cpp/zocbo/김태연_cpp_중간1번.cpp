// 2023 김태연 C++프로그래밍과실습 중간고사 1번
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

// 여기부터 구현 시작
// class 구현
enum class Currency {
  USD,
  KRW
};

class CurrencyConverter {
public:
    CurrencyConverter();
    double convert(Currency from, Currency to, double amount) const;

private:
    std::map<Currency, double> exchange_rates;
};

CurrencyConverter::CurrencyConverter(){
	std::map<Currency,double> ex_rates{{Currency::KRW,1180},{Currency::USD,1180}};
	exchange_rates = ex_rates;
}
double CurrencyConverter::convert(Currency from, Currency to, double amount)const {
	if(from==Currency::KRW&&to==Currency::USD)
		amount = amount/1180;
	else if(from==Currency::USD&&to==Currency::KRW)
		amount = amount*1180;
	return amount;
}

class Money {
public:
    Money(double amount, Currency currency);
    Money add(const Money& other) const;
    Money subtract(const Money& other) const;
    void display() const;

private:
    double convertCurrency(const Money& other) const;
    double amount;
    Currency currency;
};

Money::Money(double amount, Currency currency){
	this->amount = amount;
	this->currency = currency;
}

double Money::convertCurrency(const Money& other)const {
	CurrencyConverter converter = CurrencyConverter();
	double amount = converter.convert(other.currency,currency,other.amount);
	return amount;
	
}
Money Money::subtract(const Money& other) const{
	double amount = this->amount-this->convertCurrency(other);
	Money* newmoney = new Money(amount,currency);
	return *newmoney;
}
Money Money::add(const Money& other) const{
	double amount = this->amount+this->convertCurrency(other);
	Money* newmoney = new Money(amount,currency);
	return *newmoney;
}
void Money::display() const{
	if(currency==Currency::USD)
		std::cout<<std::fixed<<std::setprecision(2)<<"Amount: "<<amount<<" USD"<<endl;
	if(currency==Currency::KRW)
		std::cout<<std::fixed<<std::setprecision(2)<<"Amount: "<<amount<<" KRW"<<endl;
}

// 여기까지 구현하는게 문제였습니다.
// 문제는 총 3문제 주어졌고, 정답 코드만 다시 확인 가능합니다.

int main() {
  Money usd1(50, Currency::USD);
  Money usd2(20, Currency::USD);
  Money krw1(40000, Currency::KRW);

  Money result = usd1.add(usd2);
  result.display();

  result = usd1.add(krw1);
  result.display(); 

  result = usd1.subtract(usd2);
  result.display();

  result = usd1.subtract(krw1);
  result.display();

  Money zero_amount(0, Currency::USD);
  result = usd1.add(zero_amount);
  result.display();

  result = usd1.add(usd1).subtract(usd1);
  result.display(); 

  return 0;
}