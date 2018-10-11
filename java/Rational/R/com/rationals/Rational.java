package com.rationals;

public class Rational {
    public int fenzi;
    public int fenmu;
	
	public Rational(){
		fenzi = 0;
        fenmu = 0;
	}

    public Rational(int m, int n) {
        fenzi = m;
        fenmu = n;
    }

    private static int get_gcd(int a, int b) {
        int max, min;
        max = (a > b) ? a : b;
        min = (a < b) ? a : b;

        if (max % min != 0) {
            return get_gcd(min, max % min);
        } else
            return min;

    }

    private static Rational opt(Rational a) {
        int m = a.fenzi, n = a.fenmu;
        int t = get_gcd(m, n);
        if (t < 0)
            t = -t;
        Rational b = new Rational();
        b.fenmu = a.fenmu / t;
        b.fenzi = a.fenzi / t;
        return b;
    }

    public static Rational add(Rational a, Rational b) {
        Rational c = new Rational();
        c.fenmu = a.fenmu * b.fenmu;
        c.fenzi = a.fenzi * b.fenmu + a.fenmu * b.fenzi;
        return opt(c);
    }

    public static Rational sub(Rational a, Rational b) {
        Rational c = new Rational();
        c.fenmu = a.fenmu * b.fenmu;
        c.fenzi = a.fenzi * b.fenmu - a.fenmu * b.fenzi;
        return opt(c);
    }

    public static Rational muti(Rational a, Rational b) {
        Rational c = new Rational();
        c.fenmu = a.fenmu * b.fenmu;
        c.fenzi = a.fenzi * b.fenzi;
        return opt(c);
    }

    public static Rational div(Rational a, Rational b) {
        Rational c = new Rational();
        c.fenmu = a.fenmu * b.fenzi;
        c.fenzi = a.fenzi * b.fenmu;
        return opt(c);
    }

}