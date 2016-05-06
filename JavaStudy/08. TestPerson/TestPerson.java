class Person 
{
	private String name;

	void setName(String n)
	{
		name = n;
	}

	String getName() 
	{
		return name;
	}
	
}

class Girl extends Person
{
	void print()
	{
		System.out.println(getName()+"양");
	}
}

class TestPerson
{
	public static void main(String[] args) 
	{
		Girl nara = new Girl();
		nara.setName("나라");
		nara.print();
	}
}