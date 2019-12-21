import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Lower_Bound {

	static ArrayList<Integer> list = new ArrayList<Integer>();
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		Random rand = new Random();
		int N = scan.nextInt();
		
		for(int i =0; i<N; i++) {	
			list.add(rand.nextInt(20));
		}
		
		list.sort(null);

		for(int i =0; i<N; i++) {	
			System.out.print( list.get(i) + " ");
		}
		
		System.out.print("\n");
		
		Lower_Bound(rand.nextInt(20));
	
	}

	public static void Lower_Bound(int k) {
		
		int start = 0;
		int end = list.size() - 1;
		int mid;
		
		// start가 end 보다 작을 때 까지 반복문을 돌려준다.
		while(start < end) {
			
			//중앙값을 찾는다.
			mid = (start + end) /2;
			
			//만약 k 값이 더 크다면 start를 mid + 1로 한간 올려주
			if(list.get(mid) < k) {
				start = mid + 1;
			}
			//아니면 end 값을 mid로 해준다.
			else {
				end = mid;
			}
			
		}
		
		System.out.print( k + " " + end);
		
	}
	
}
