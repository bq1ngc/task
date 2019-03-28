import java.util.Random;

class Myrandom {
  public double mey = 0;
  public int mun=0;
  double _use=0;
  int _ok=0;

  Myrandom(double mey,int mun) {
    this.mey=mey;
    this.mun=mun;
  }

  public String[] run() {
    String[] ok=new String[this.mun];
    double temp;

    Random rand = new Random();
    for(int i=0; i<this.mun; i++) {
      while(true){
        temp=(mey-_use)*rand.nextDouble();
        if(i+1==mun) temp=mey-_use;
        temp = (double) Math.round(temp * 100) / 100;
        if(temp!=0 && temp!=(mey-_use) && mun-temp+_use>=0.01*(mun-i-1)) break;
      }
      _use+=temp;
      ok[i]=String.format("%.2f", temp);
       
    }
    return ok;
  }
}

class Redbao {
    public static void main(String[] args){
      Myrandom my=new Myrandom(100.0,10);
      String[] temp = my.run();
      for(int i=0;i<10;i++){
        System.out.println(temp[i]);
      }
    }
}
