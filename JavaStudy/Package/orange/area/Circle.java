package orange.area;

public class Circle
{
	double rad;
	final double pi;

	public Circle(double r)
	{
		rad = r;
		pi = 3.14;
	}

	public double getArea()
	{
		return rad*rad*pi;
	}	
}

