class InsufficientFundsException extends Exception {
    private double amount;

    public InsufficientFundsException(double amount) {
        super("Insufficient funds! You need an additional $" + amount + " to complete the transaction.");
        this.amount = amount;
    }

    public double getAmount() {
        return amount;
    }
}

class BankAccount {

    private double currentBalance;

    public BankAccount(double currentBalance) {
        this.currentBalance = currentBalance;
    }

    public double getCurrentBalance() {
        return currentBalance;
    }

    public void setCurrentBalance(double currentBalance) {
        this.currentBalance = currentBalance;
    }

    public void withdrawMoney(double amount) throws InsufficientFundsException {
        double currentBalance = getCurrentBalance();
        if (amount > currentBalance) {
            double requiredFunds = amount - currentBalance;
            throw new InsufficientFundsException(requiredFunds);
        } else {
            setCurrentBalance(currentBalance - amount);
        }
    }
}

class ExceptionDemo1 {
    public static void main(String[] args) {
        BankAccount ba = new BankAccount(500);
        try {
            ba.withdrawMoney(600);
        } catch (InsufficientFundsException e) {
            System.out.println(e.getMessage());
        }
    }
}


