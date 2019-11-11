import java.util.Scanner;

class Scratch {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("请输入a\n");
        float a=in.nextFloat();
        Scanner in1=new Scanner(System.in);
        System.out.println("请输入b\n");
        float b=in1.nextFloat();
        Scanner in2=new Scanner(System.in);
        System.out.println("请输入c\n");
        float c=in2.nextFloat();
        float d=b*b-4*a*c;
        float e=java.lang.;
        double x1,x2;
        x1=(-b+Math.sqrt(d))/(2*a);
        x2=(-b-Math.sqrt(d))/(2*a);
        System.out.println(x1+" "+x2);
    }
}
