import java.util.*;

public class Union_Find {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int Connected[] = new int[11];
		
		Scanner scan = new Scanner(System.in);
		
		for(int i=1; i<=10; i++) {
			Connected[i] = i;
		}
		
		Union(Connected, 1,2);
		Union(Connected, 2,3);
		System.out.println(Find(Connected,4, 1));
		for(int i = 1; i<=10; i++) {
			System.out.print(Connected[i] + " " );
		}
		
		
	}
	
	//최종 부모를 찾아주는 함수 
	static int getParent(int[] connected, int current) {
		
		if(connected[ current ] == current) return current;
		
		return connected[current] = getParent(connected, connected[current]);
	}
	
	//두 노드를 연결해주는 함수 
	static void Union(int[] connected, int a, int b) {
		
		int temp_a = getParent(connected, a);
		int temp_b = getParent(connected, b);
		
		if(temp_a < temp_b) {
			connected[temp_b] = temp_a;
		}
		else {
			connected[temp_a] = temp_b;
		}
		
	}
	
	//두 노드가 연결성을 가지고 있는지 알려주는 함수 
	static int Find(int[] connected, int a, int b) {
		
		if(getParent(connected, a) == getParent(connected, b)) {
			return 1;
		}
		
		return 0;
	}
	
	

}
