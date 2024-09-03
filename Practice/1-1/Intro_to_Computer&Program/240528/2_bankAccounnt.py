class account:
    def __init__(self, balance=0):
        self.__balance = balance
    
    def withdraw(self, amount):
        self.__balance -= amount
        return self.__balance
    
    def deposit(self, amount):
        self.__balance += amount
        return self.__balance
    
aAccount = account(2000)
print(aAccount.withdraw(1000))