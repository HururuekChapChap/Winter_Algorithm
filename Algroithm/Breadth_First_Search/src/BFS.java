import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Data{
	int from;
	ArrayList<Integer> to = new ArrayList<Integer>();
	
	//생성
	Data(int from){
		this.from = from;
	}
	
	// 연결된 노드들
	public void setData(int to){
		this.to.add(to);
	}
};

public class BFS {
	
	//방문표시를 해줘야 다시 방문할 일이 없어진다.
	static boolean visited[];
	//N개의 갯수에 따라 늘어난다. 자바에서는 ArrayList로 이차원 배열을 만들 수 없는 것 같다.
	static ArrayList<Data> list = new ArrayList<Data>();
	
	public static void BFS(int start) {
		Queue<Integer> q = new LinkedList<>();
		
		q.add(start);
		visited[start] = true;
		int total = 0;
		
		while(!q.isEmpty()) {
			
			int item = q.poll();
			
			System.out.println(item + "탐색 ");
			
			for(int i = 0; i < list.get(item).to.size(); i++) {
				
				int to = list.get(item).to.get(i);
				
				if(visited[to] == false) {
					visited[to] = true;
					q.add(to);
				}
				
			}
			
		}
	
		
	}
	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int N, from = 0, to;
		Scanner scan = new Scanner(System.in);
		System.out.println("전체 노드의 갯수 : ");
		N = scan.nextInt();
		
		visited = new boolean[N];
		
		for(int i = 0; i<N; i++) {
			visited[i] = false;
		}
		
		//연결성 입
		do {
			System.out.println(from + "의 연결 노드의 갯수 : ");
			int total = scan.nextInt();
			
			list.add(new Data(from));
			System.out.println("연결 노드 입력 : ");
			for(int i = 0; i < total; i++) {
				to = scan.nextInt();
			
				if( to >=0 && to < N ) {
					list.get(from).setData(to);
				}
			
			}
			
			from++;
			
		}while(from < N);
		
		for(int i = 0; i<N; i++) {
			System.out.println("노드 : " + list.get(i).from);
			
			
			for(int j =0; j<list.get(i).to.size(); j++) {
				System.out.print(list.get(i).to.get(j) + " ");
			}
			System.out.println("");
			
		}
		
		//탐색 
			BFS(5);	
		
		
		
	}

}
