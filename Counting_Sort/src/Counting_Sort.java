import java.util.Random;

public class Counting_Sort {
	
	static int Array[] = new int[10];
	static int Counting[] = new int[10];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Random rand = new Random();
		
		// 10개의 공간을 담을 수 있는 Array를 만들어 준다.
		for(int i = 0; i< 10; i++) {
			Array[i] = rand.nextInt(10) + 1;
		}
		
		// Array에 들어가 있는 값을 참조하여 Counting[index]를 증가시켜준다.
		for(int i =0; i<10; i++) {
			Counting[Array[i] - 1]++;
		}
		
		// 그리고 출력을 해준다. 그런데, 이부분이 while이 들어가서 출력해줄 때는,N 이라는 시간 복잡도가 안 나올 것 같다.
		
		for(int i = 0; i<10; i++) {
			
			if(Counting[i] != 0) {
				
				int temp = 0;
				
				while(temp < Counting[i]) {
					
					System.out.print(i +  " ");
					
					temp++;
					
				}
				
			}
			
		}
		
		
	}

}
