import com.rationals.Rational;

public class run {

    public static void main(String[] args) {
        Rational a = new Rational(1, 2);
        Rational b = new Rational(2, 6);
        System.out.println(" a: " + a.fenzi + "/" + a.fenmu);
        System.out.println(" b: " + b.fenzi + "/" + b.fenmu);
        System.out.println("");
        Rational c = Rational.add(a, b);
        System.out.println(" +: " + c.fenzi + "/" + c.fenmu);
        c = Rational.sub(a, b);
        System.out.println(" -: " + c.fenzi + "/" + c.fenmu);
        c = Rational.muti(a, b);
        System.out.println(" *: " + c.fenzi + "/" + c.fenmu);
        c = Rational.div(a, b);
        System.out.println(" /: " + c.fenzi + "/" + c.fenmu);

    }
}