import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Heap_Sort {

	//리스트의 크기를 동적으로 하기 위해서 ArrayList로 만들었다.
	static ArrayList<Integer> list = new ArrayList<Integer>();
	static int n;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//넣고싶은 양을 입력 받아준다.
		int n;
		Scanner input = new Scanner(System.in);
		Random rand = new Random();
		
		//트리 구조는 1 부터 시작하기 때문에, 하나를 추가해준다.
		n = input.nextInt();
		list.add(0);
		
		// 랜덤 값으로 list에 추가해주면서 한번 씩 Heapify로 정렬을 해준다.
		for(int i = 1; i<=n; i++) {
			list.add(rand.nextInt(100));
			System.out.print(list.get(i) + " ");
			Heapify(i);
		}
		
		System.out.println("\n=========힙 구조로 정렬 한 모습 =========");
		
		for(int i =  1; i <=n; i++) {
			System.out.print(list.get(i) + " ");
		}
		System.out.println("\n=========힙 정렬 한 모습 =========");
		
		for(int i= 1; i<=n; i++) {
			//최대값을 출력해준다.
			System.out.print(Heap_Sort() + " ");
		}
		
		
		
		
	}
	
	//Heap 구조로 만들어 주는 Heapify 함
	public static void Heapify(int num) {
		
		//현재 시작 점을 매개변수로 받아준다.
		int current = num;
		
		//아래서 부터 위로 올라가는 방식으로 구성해준다.
		while(current > 1) {
			
			//트리구조는 현재 위치의 나누기 2 한 것이 루트이다.
			int root = current /2 ;
			
			//만약에 루트 보다 현재 위치의 값이 더 크다면 서로 바꿔준다.
			if(list.get(current) > list.get(root) ) {
				int temp = list.get(current);
				list.set(current, list.get(root));
				list.set(root, temp);
			}
			
			//그리고 현재 위치를 루트로 바꿔준다.
			current = root;
		}
		
	}
	
	//하향식 힙 정
	public static int Heap_Sort() {
		
		//최고 위치의 루트 값을 반환 해주기 위해서 item 변수로 받아준다.
		int item = list.get(1);
		int current = 1;
		
		//현재 최상단 루트의 값을 마지막 노드의 값으로 바꿔준다.
		list.set(1, list.get(list.size() - 1));
		//그리고 list의 길이를 하나 줄여준다.
		list.remove(list.size()-1);
		
		//현재 노드의 두배한 노드의 오른쪽 노드의 위치가 list의 크기 보다 작을 때까지 돌려준다.
		while(current * 2 + 1 <list.size()) {
			
			//다음 노드의 위치 
			int next = current * 2;
			
			//만약 오른쪽(홀수) 노드의 크기가 더 크다면 위치 이동을 시켜준다.
			if(list.get(next) < list.get(next + 1)) {
				next++;
			}
			
			//현재 값 보다 next 노드의 크기가 더 크다면 바꿔준다.
			if(list.get(next) > list.get(current)) {
				int temp = list.get(next);
				list.set(next, list.get(current));
				list.set(current, temp);
			}
			
			current = next;
			
		}
		
		//최고값 반
		return item;
		
	}

}
