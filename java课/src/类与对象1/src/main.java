class Point {
    double x, y;
    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    public boolean equals(Object o) {
        if (o == this) return true;
        if (!(o instanceof Point)) return false;
        Point p = (Point) o;
        return x == p.x && y == p.y;
    }
    public String toString() { return "(" + x + ", " + y + ")"; }
}
class Line {
    Point p1, p2;
    Line(Point p1, Point p2) {
        this.p1 = p1;
        this.p2 = p2;
    }
    double length() {
        double dx = p1.x - p2.x, dy = p1.y - p2.y;
        return Math.sqrt(dx * dx + dy * dy);
    }
    boolean parallelToAbscissa() { return p1.y == p2.y; }
    boolean parallelToOrdinate() { return p1.x == p2.x; }
    double slope() { return (p1.y - p2.y) / (p1.x - p2.x); }
    Point midPoint() { return new Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2); }
    public boolean equals(Object o) {
        if (o == this) return true;
        if (!(o instanceof Line)) return false;
        Line line = (Line) o;
        return (p1.equals(line.p1) && p2.equals(line.p2)) ||
                (p1.equals(line.p2) && p2.equals(line.p1));
    }
}
public class Test {
    public static void main(String[] args) {
        Point p1 = new Point(1, 2), p2 = new Point(3, 4);
        Line line = new Line(p1, p2);
        System.out.println(line.length());
        System.out.println(line.parallelToAbscissa());
        System.out.println(line.parallelToOrdinate());
        System.out.println(line.slope());
        System.out.println(line.midPoint());
        System.out.println(line.equals(line));
    }
}