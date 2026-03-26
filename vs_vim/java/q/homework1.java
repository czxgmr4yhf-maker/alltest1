package q;

public class homework1 {
    public static void main(String[] args) {
        saveAccount saver1 = new saveAccount();
        saveAccount saver2 = new saveAccount();

        saver1.setSaving(200.00);
        saver2.setSaving(3000.00);

        saveAccount.modifyRate(0.04);

        //一个月的利润加存款
        saver1.calculate();
        saver2.calculate();

        System.out.print("saver1的");
        saver1.getSaving();

        System.out.print("saver2的");
        saver2.getSaving();        
    }
}
class saveAccount{
    static double Rate;
    private double saving;
    
    public void setSaving(double saving){
        this.saving = saving;
    }

    public void getSaving() {
        System.out.printf("存款为：%.2f\n", saving);                //printf格式化输出
    }

    void calculate(){
        saving += saving * Rate / 12;
    }

    static void modifyRate(double newRate){
        Rate = newRate;
    }
}