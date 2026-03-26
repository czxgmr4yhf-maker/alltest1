package q;

public class homework3 {
    public static void main(String[] args){
        int n = 10;
        
        Fibnon fib = new Fibnon();
        fib.Fibonon(n);
    }
}

class Fibnon{
    int a = 1;
    int b = 1;
    int count = 1;

    public void Fibonon(int n){
        if (count > n) {
            count = 1;
            System.out.printf("\n");
            return;
        }

        if (count == 1 || count == 2) {
            System.out.printf("%d ", 1);
        } else {
            System.out.printf("%d ", a + b);
            int c = a + b;
            a = b;
            b = c;
        }
        count++;
        Fibonon(n);

    }
}