import java.util.Scanner;

class Scratch {
    public static void Main(String[] args) {
        int weight;
        Scanner in=new Scanner(System.in);
        weight=in.nextInt();
        int max=weight;
        int min=weight;
        int count=0;
        while (weight!=-1)
        {
            Scanner in1=new Scanner(System.in);
            weight=in1.nextInt();
            max=max > weight ?max:weight;
            min=min<weight?min:weight;
            count++;
        }
        System.out.println(max+min+count);
    }
}