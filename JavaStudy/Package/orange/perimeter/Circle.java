package orange.perimeter;

public class Circle
{
	double rad;
	final double pi;

	public Circle(double r)
	{
		rad = r;			
		pi = 3.14;
	}

	public double getPerimeter()
	{
		return rad*2*pi;
	}	
}
