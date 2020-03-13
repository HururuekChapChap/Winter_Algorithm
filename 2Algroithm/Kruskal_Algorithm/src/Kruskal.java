import java.util.*;

// https://includestdio.tistory.com/35 자바의 객체의 정렬을 공부하는데 좋은 자료이다.

class Data{
	int from;
	int to;
	int weight;
	
	Data(int to, int from, int weight){
		this.to = to;
		this.from = from;
		this.weight = weight;
	}
	
}

//최소신장 트리를 만드는 크르스칼 알고리즘.
public class Kruskal {
	
	static int parent[] = new int[10];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(int i = 1; i<8; i++) {
			parent[i] = i;
		}
		
		List<Data> list = new ArrayList<Data>();
		
		//이렇게 객체를 만들어서 list에 삽입해준다.
		list.add(new Data(1,7, 12));
		list.add(new Data(1,4, 28));
		list.add(new Data(1,2, 67));
		list.add(new Data(1,5, 17));
		list.add(new Data(2,4, 24));
		list.add(new Data(2,5, 62));
		list.add(new Data(3,5, 20));
		list.add(new Data(3,6, 37));
		list.add(new Data(4,7, 13));
		list.add(new Data(5,6, 45));
		list.add(new Data(5,7, 73));
		
		//자바의 객체 정렬 방식은 쉽지 않다. 두가지 방식이 있는데, 나는 이런 방식으로 일단 해봤다.
		Collections.sort(list, new Comparator<Data>() {

			@Override
			//이렇게 List Collection은 정렬하고 자 하는 list의 이름과 Comparator 객체를 넣어준다.
			//그리고 compare 함수에서 정의 해준다.
			public int compare(Data o1, Data o2) {
				// TODO Auto-generated method stub
				
				//같다면 0으로 
				int result = 0;
				//작다면 -1으로 
				if(o1.weight < o2.weight) {
					result = -1;
				}
				//크다면 1로 정렬해준다. 
				else if(o1.weight > o2.weight) {
					result = 1;
				}
				
				return result;
				
			}
		
		});
		
	
		for(int i = 0; i<list.size() ; i++) {
			System.out.print(list.get(i).weight + " ");
		}
		
		int sum = 0;
		int cnt = 0;
		int n = 0;
		
		//최소신장 트리의 간선은 항상 노드 -1로 6개일 때 까지 돌려준다. 
		while(n <6) {
			//크루스칼 알고리즘은 정렬을 통해서 무게가 덜 나가는 놈들로 정렬을 해준다.
			//그리고 거기서 하나씩 뽑아서 비교하는데, 서로 사이클이 돌지 않는다면 
			//합병해준다.
			int check = FindParent(list.get(cnt).from, list.get(cnt).to);
			
			if(check != 1) {
				
				Union(list.get(cnt).from, list.get(cnt).to);
				n++;
				sum+= list.get(cnt).weight;
				
			}
			
			cnt++;
			
		}
		
		System.out.println("\n 최소신장트리의 크기 : "+sum);
		
		
		
	}
	
	public static int GetParent(int num) {
		
		if(parent[num] == num) {
			return num;
		}
		
		return parent[num] = GetParent(parent[num]);
	}
	
	public static int FindParent(int A, int B) {
		
		int temp_a = GetParent(A);
		int temp_b = GetParent(B);
		
		if(temp_a == temp_b) {
			return 1;
		}
		
		return 0;
	}
	
	public static void Union(int A, int B) {
		
		int temp_a = GetParent(A);
		int temp_b = GetParent(B);
		
		if(temp_a < temp_b) {
			parent[temp_b] = temp_a;
		}
		else {
			parent[temp_a] = temp_b;
		}
		
	}

}
