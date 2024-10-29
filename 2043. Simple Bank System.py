class Bank:

    def __init__(self, balance: List[int]):
        self.balance = {}

        for i, bal in enumerate(balance):
           self.balance[i + 1] = bal 

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if 1 <= account1 and account1 <= len(self.balance) and 1 <= account2 and account2 <= len(self.balance) and self.balance[account1] >= money:
            self.balance[account1] -= money
            self.balance[account2] += money
            return True

        return False

    def deposit(self, account: int, money: int) -> bool:
        if 1 <= account and account <= len(self.balance):
            self.balance[account] += money
            return True

        return False

    def withdraw(self, account: int, money: int) -> bool:
        if 1 <= account and account <= len(self.balance) and self.balance[account] >= money:
            self.balance[account] -= money
            return True

        return False


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
