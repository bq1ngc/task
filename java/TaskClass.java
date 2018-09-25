
class Task1{
    public static void run() {
        System.out.println("Task1：求1到10的阶乘之和");
        long _temp=1, mun=0;
        for (int i=1;i<=10;i++){
            _temp *= i;
            mun += _temp;
        }
        System.out.println("和为 "+ mun);
    }
}

class Task2{
    public static void run() {
        System.out.println("Task2：求满足1到n之和小于8888的最大整数");
        long mun=0, i=1;
        for (;mun<8888;++i){
            mun += i;
        }
        System.out.println("最大为 "+ (i-2));
    }
}

public class TaskClass{
    public static void main(String[] args) {
        Task1.run();
        Task2.run();
    }
}