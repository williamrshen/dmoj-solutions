import java.util.*;

public class dmopc14c3p3 {
  public static class Veteren implements Comparable<Veteren>{
    public String name;
    public int skill;
    public int order;
    public Veteren(String n,int p, int o){
      this.name=n;
      this.skill=p;
      this.order=o;
    }
    @Override
    public int compareTo(Veteren o) {
      // TODO Auto-generated method stub
      if(this.skill>o.skill){
        return 1;
      }else if(o.skill>this.skill){
        return -1;
      }else{
        return this.order-o.order;
      }
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int VN = sc.nextInt();
    Veteren v[] = new Veteren[VN];
    
    for(int i = 0; i<VN; i++){
      v[i]=new Veteren(sc.next(), sc.nextInt(), i);
    }
    
    Arrays.sort(v);
    
    int NN = sc.nextInt();
    
    for(int i = 0; i<NN; i++){
      int S = sc.nextInt();
      int d = sc.nextInt();
      boolean teacher = false;
      for(int j = 0; j<VN; j++){
        if(v[j].skill<=S+d && v[j].skill>=S){
          System.out.println(v[j].name);
          teacher=true;
          break;
        }
      }
      if(teacher==false){
        System.out.println("No suitable teacher!");
      }
    }  
  }
}