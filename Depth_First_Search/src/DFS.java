import java.util.*;

class Data{
	 Vector<Integer> v = new Vector<Integer>();
	 
	 Data(){}
}


public class DFS {
	static int visited[]= new int[7];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Vector<Data> v = new Vector<Data>();
		Scanner scan = new Scanner(System.in);
		
		for(int i = 0; i<7; i++) {
			v.add(new Data());
			visited[i] = 0;
		}
		
		System.out.print("7개의 정점에 대해서 연결선 2개를 입력하시오.");
		
		for(int i = 0; i< 3; i++) {
			for(int j = 0; j<2; j++) {
				int item = scan.nextInt();
				v.get(i).v.add(item);
				v.get(item).v.add(i);
			}
		}
		
		visited[0] = 1;
		Fun_DFS(0,v);
		
	}
	
	static void Fun_DFS(int current, Vector<Data> v) {
		
		System.out.print(current + " - ");
		for(int i = 0; i< v.get(current).v.size(); i++ ) {
			
			if(visited[v.get(current).v.get(i)] == 0) {
				visited[v.get(current).v.get(i)]= 1;
				Fun_DFS(v.get(current).v.get(i), v);
			}
			
		}
		
	}

}
