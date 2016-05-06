import java.util.Random;

class RandomNum 
{
	public static void main(String[] args) 
	{
		Random rand = new Random(12);
		// 현재 시간을 밀리 초 단위로 변환
		rand.setSeed(System.currentTimeMillis());

		for(int i=0; i<100; ++i)
			System.out.println(rand.nextInt(1000));
	}
}
