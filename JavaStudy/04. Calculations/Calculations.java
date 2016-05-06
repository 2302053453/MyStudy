class Calc
{
	int add(int a, int b)
	{
		return a+b;
	}
}
class Calculations
{	
	
	public static void main(String[] args) 
	{
		int c;

		Calc calc = new Calc();

		c = calc.add(8,9);
		System.out.println("8 + 9 = "+c);
	}
}
