
public class Rectangle extends Angle {
    public double height;

    public Rectangle() {
        super();
        height = 1.0;

    }

    public Rectangle(double h, double w) {
        height = h;
        super(w);
    }

    public static void main(String[] args) {
        Rectangle r = new Rectangle(1.0, 10.0);
        System.out.print("Area: ");
        System.out.println(r.getArea());
    }

    double getArea() {
        return height * width;
    }

    double getPerimeter() {
        return 2.0 * (height + width);
    }


}