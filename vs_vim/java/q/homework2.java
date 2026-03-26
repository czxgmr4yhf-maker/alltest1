package q;

public class homework2 {
    public static void main(String[] args){
        //对于圆周长选7.5，对于矩形，长宽分别为16.1,5.6
        Circle cir = new Circle();
        cir.setR(7.5);

        Rectangle rec = new Rectangle(16.1, 5.6);

        System.out.printf("圆的周长为%.2f,面积为%.2f\n", cir.getPermeter(), cir.getArea());
        System.out.printf("矩形的周长为%.2f,面积为%.2f\n", rec.getPermeter(), rec.getArea());
    }
}
abstract class Shape{
    abstract public double getArea();

    abstract public double getPermeter();
}

class Circle extends Shape{
    private double r;
    
    public void setR(double r){
        this.r = r;
    }

    public double getArea(){
        return 3.14*r*r;
    }

    public double getPermeter(){
        return 2*3.14*r;
    }
}

class Rectangle extends Shape{
    private double len;
    private double width;

    Rectangle(double len, double width){
        this.len = len;
        this.width = width;
    }

    public double getArea(){
        return len*width;
    }

    public double getPermeter(){
        return 2*len*width;
    }
}