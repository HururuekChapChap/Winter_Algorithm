import java.util.ArrayList;
import java.util.PriorityQueue;

class Data{
	
	private int to;
	private int weight;
	
	Data(int to, int weight){
		this.to = to;
		this.weight = weight;
	}
	
	public int getTo() {
		return to;
	}
	
	public int getWeight() {
		return weight;
	}
	
}

class Distance implements Comparable<Distance>{
	
	private int to;
	private int dis;
	
	Distance(int to, int dis){
		
		this.to = to;
		this.dis = dis;
		
	}
	
	public int getTo() {
		return to;
	}
	
	public int getDis() {
		return dis;
	}
	
	
	@Override
	public int compareTo(Distance other ) {
		if(this.dis < other.getDis()) return -1;
		else if(this.dis > other.getDis()) return 1;
		return 0;
	}
	
}


public class Dijkstra_Algroithm {

	static int distance[] = new int[11];
	static ArrayList<ArrayList<Data>> list = new ArrayList<ArrayList<Data>>();
	
	public static void Dijkstra(int start) {
		
		PriorityQueue<Distance> pq = new PriorityQueue<Distance>();
		distance[start] = 0;
		pq.offer(new Distance(start, 0));
		
		while(! pq.isEmpty()) {
			Distance temp = pq.poll();
			
			int from = temp.getTo();
			int dis = temp.getDis();
			
			for(int i=0; i< list.get(from).size();i++ ) {
				
				int to = list.get(from).get(i).getTo();
				int Sum_distance = dis + list.get(from).get(i).getWeight();
				
				if(Sum_distance < distance[to]) {
					distance[to] = Sum_distance;
					pq.offer(new Distance(to,Sum_distance));
				}
				
			}
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		for(int i =1 ; i<=10; i++) {
			distance[i] = 987654321;
		}
		
		
		for(int i = 0; i<11; i++) {
			list.add(new ArrayList<>());
		}
		
		
		list.get(1).add(new Data(2,2));
		list.get(1).add(new Data(3,5));
		list.get(1).add(new Data(4,1));
		
		list.get(2).add(new Data(1,2));
		list.get(2).add(new Data(3,3));
		list.get(2).add(new Data(4,2));
		
		list.get(3).add(new Data(1,5));
		list.get(3).add(new Data(2,3));
		list.get(3).add(new Data(4,3));
		list.get(3).add(new Data(5,1));
		list.get(3).add(new Data(6,5));
		
		list.get(4).add(new Data(1,1));
		list.get(4).add(new Data(2,2));
		list.get(4).add(new Data(3,3));
		list.get(4).add(new Data(5,1));
		
		list.get(5).add(new Data(3,1));
		list.get(5).add(new Data(4,1));
		list.get(5).add(new Data(6,2));
		
		list.get(6).add(new Data(3,5));
		list.get(6).add(new Data(5,2));
		
		Dijkstra(1);
		
		for(int i =1; i<=6; i++) {
			System.out.print(distance[i] +" ");
		}
		
		//System.out.println(list.get(1).get(0).getTo());
		
	}
	

}
 