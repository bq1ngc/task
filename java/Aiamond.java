/*
 * @Description 生成由*号组成的半菱形
 * @param args 行数
 */
public class Aiamond {
    public static void main(String[] args) {
        if (args.length <= 0) {
            args=new String[]{"5"};
        }
        int row = Integer.parseInt(args[0]);
        System.out.println("Row: " + row);

        for (int i=1; i<=row; i++) {
            for (int j=row; j>=i; j--) {
                System.out.print(" ");
            }
            for (int j=1; j<=i; j++) {
                System.out.print("* ");
            }
            System.out.println(' ');
        }
    }
}