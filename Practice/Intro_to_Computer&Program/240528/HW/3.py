class BankAccount(object):
    interest_rate = 0.3 # 해당 클래스변수는 정상적입니다.
    def __init__(self, name, number, balance):
        self.__name = name
        self.__number = number
        self.__balance = balance  #각각의 인스턴스 변수들을 호출하지 않았기에 이하 코드들에 메소드를 추가해 호출을 해야 합니다.
        #return  해당 return 은 불필요하기에 제거하였습니다.

    def deposit(self, amount):
        self.__balance += amount
        print('잔고에 %d 입금되어 남은 잔고는 %d 입니다.' %(amount, self.__balance))

    def withdraw(self, amount):
        if amount > self.__balance :
            print('잔고가 부족합니다.')
        else:
            self.__balance -= amount
            print('잔고에서 %d 인출하여 남은 잔고는 %d 입니다.' %(amount, self.__balance))

    def accountInfo(self):
        print('계좌의 소유주는 %s, 계좌번호는 %d, 잔고는 %d 입니다.' %(self.__name, self.__number, self.__balance)) #호출되지 않은 인스턴스변수를 위해, 메소드를 하나 추가했습니다.

'''
아래는 코드 활용한 예제입니다.
busanBank = BankAccount('sw', 11221, 20000)
busanBank.deposit(2000)
busanBank.withdraw(10000)
busanBank.accountInfo()
print(BankAccount.interest_rate)
'''