interface Greet
{
	void greet();
}

interface Bye extends Greet
{
	void bye();
}



class Greeting implements Bye
{
	public void greet()
	{
		System.out.println("안녕하세요!");
	}

		public void bye()
	{
		System.out.println("안녕히 계세요");
	}
}  

class Meet1
{
	public static void main(String[] args) 
	{
		Greeting morning = new Greeting();
		morning.greet();
		morning.bye();
	}
}
